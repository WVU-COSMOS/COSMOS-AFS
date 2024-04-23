// Kelly Peed [KP], PPT
// kjp00002@mix.wvu.edu
// 
// Jacob P. Krell [JPK]
// jpk0024@mix.wvu.edu
// 
// Merge of battery charge and accelerometer.
// ===============================================================

#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Arduino.h>
#include <Adafruit_MPU6050.h> // [JPK]
#include <Adafruit_Sensor.h> // [JPK]

Adafruit_INA219 ina219;
Adafruit_MPU6050 mpu; // [JPK]

bool hasRun = false;           // variable to determine if program has run, will only be false first time this runs
float SOC_prev = 0;            // declare variable for previous SOC, will only be zero first time this runs
unsigned long prevTime = 0;    // declare variable for previous time, will only be zero first time this runs

// [JPK] Define a structure to hold sensor data
struct SensorData {
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
};

void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1); // Accel. has delay(10)
  }
    
  Serial.println("Hello!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();
  Serial.println("Measuring voltage and current with INA219 ...");

  // [JPK] Try to initialize:
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);
}

void loop() // [KP] loop(void) 
{

  // DECLARE VARIABLES
  float shuntvoltage = 0;             // Shunt Voltage (V)
  float busvoltage = 0;               // Battery Voltage (V)
  float current_mA = 0;               // Current (mA)
  float loadvoltage = 0;              // Load Voltage (V)
  float power_mW = 0;                 // Power (mW)
  const float charging_voltage = 4.2; // Charging Voltage, const. (V)
  const float cutoff_voltage = 2.65;  // Discharge Cutoff, const. (V)
  const int Qn = 3350;                // Battery Capacity, const. (mAh)

  // GET VALUES
  shuntvoltage = ina219.getShuntVoltage_mV(); // Built-in function from Adafruit INA219
  busvoltage = ina219.getBusVoltage_V();      // Built-in functino from Adafruit INA219
  current_mA = ina219.getCurrent_mA();        // Built-in function from Adafruit INA219
  power_mW = ina219.getPower_mW();            // Built-in function from Adafruit INA219
  loadvoltage = busvoltage + (shuntvoltage / 1000);

  // GET TIME AND CHANGE IN TIME
  unsigned long currentTime = millis();                    // time (ms) since the program has been run
  unsigned long dt = (currentTime - prevTime)/(1000*3600); // change in time (hours) between each loop
  prevTime = currentTime;                                  // updates previous time to use in next loop

  // OBTAIN INITIAL SOC
  if (hasRun == false){
    hasRun = true; // this program has now run, so change to true

    // obtain initial SOC values from trend reported in paper (Zhang, et al. 2016)
    // parameters for LNMCO battery (Li-Ni-Mn-Co)
    const float a =  3.5;
    const float b = -0.0334;
    const float c = -0.106;
    const float d =  0.7399;
    const float m =  1.403;
    const int   n =  2;

    // define vectors for SOC, OCV, and approximation value
    const int size = 101; // Size of OCV and SOC vector
    float s[size];        // Range of values going from 0 -> 1
    float V[size];        // Open Circuit Voltage (OCV)
    float aprx[size];     // To compare against OCV values
  
    // build vectors
    for (int k = 0; k < size; ++k) {
      s[k] = k * 0.01;                                                           // SOC values ranging from 0 -> 1
      V[k] = a + b * powf(-logf(s[k]), m) + c * s[k] + d * expf(n * (s[k] - 1)); // OCV formula provided by Zhang, et al. using defined parameters
    }

    // modify the approximation array "aprx" to subtract the OCV values from the detected bus voltage
    // the bus voltage is divided by 4 to account for the 4 batteries; the formula from Zhang, et al. only applies for a single battery
    // this assumes the OCV value eventually detected is the same for each battery

    for (int k = 0; k < size; ++k) {
      aprx[k] = abs((busvoltage/4) - V[k]);
    }
  
    // find which value in the approximation array is closest to zero
    // the location of this value is where the battery voltage most closely matches to the theoretical OCV values
    // the corresponding SOC value is at this same location

    float minVal = aprx[0];
    int minIndex = 0;
    for (int k = 1; k < size; ++k) {
      if (aprx[k] < minVal) {
        minVal = aprx[k];
        minIndex = k;
      }
    }

  // THIS IS THE INITIAL SOC VALUE
    SOC_prev = s[minIndex];
    Serial.print("Initial Battery Percentage: "); Serial.print(SOC_prev*100); Serial.println(" %");
  
  }

  // CALCULATE BATTERY PERCENTAGE

  float SOC = SOC_prev - ((current_mA/Qn)*dt); // coulomb counting method to get SOC
  SOC_prev = SOC;                              // update previous SOC with current SOC

  
  Serial.print("Bus Voltage:        "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage:      "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:       "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:            "); Serial.print(current_mA); Serial.println(" mA");
  //Serial.print("Power:              "); Serial.print(power_mW); Serial.println(" mW");
  Serial.print("Battery Percentage: "); Serial.print(SOC*100); Serial.println(" %");
  Serial.println("");

  // delay(2000); // [JPK] use below delay at end of loop

  // ===============================================================
  // ===============================================================
  // ===============================================================
  // ===============================================================
  // [JPK] Accelerometer:

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // START debug ==============================================

  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  // Serial.print("Temperature: ");
  // Serial.print(temp.temperature);
  // Serial.println(" degC");

  Serial.println("");

  // END debug ================================================

  // // START non-debug ==============================================

  // // Create a SensorData object and populate it with sensor data
  // SensorData data;
  // data.ax = a.acceleration.x; // m/s^2
  // data.ay = a.acceleration.y;
  // data.az = a.acceleration.z;
  // data.gx = g.gyro.x; // rad/s
  // data.gy = g.gyro.y;
  // data.gz = g.gyro.z;

  // // Send the data over the serial port
  // Serial.write(reinterpret_cast<uint8_t*>(&data), sizeof(data));

  // // END non-debug ================================================
  
  delay(500); // sampling delay time (ms)
}