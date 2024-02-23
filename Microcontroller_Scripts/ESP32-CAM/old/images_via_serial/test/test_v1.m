%% Development Information
% WVU-COSMOS \ COSMOS-AFS \ 2CAM \ protocol \ testing
% 
% Test image capture via text of serial monitor in Arduino IDE (uint_8).
% 
% 
% Primary Developer Contact Information:
% Jacob P. Krell
% Aerospace Engineering Undergraduate Student
% Statler College of Engineering & Mineral Resources
% Dept. Mechanical and Aerospace Engineering
% West Virginia University (WVU)
% jpk0024@mix.wvu.edu
%
% Developers:
%   - Jacob P. Krell (JPK)
%   - Aom Bauman (AB)
%
%
% Development History
% Date              Developer        Comments
% ---------------   -------------    --------------------------------
% Nov. 1, 2023      JPK, AB          Grayscale
% Nov. 8, 2023      JPK              JPG
%
%%


% NOTES
% 8 bit --> 2^8 = 256
% 64 pixels --> 64*256 = 16384 = 2^14
% 






clearvars, clc, close all

RGB = 1;

% =========================================================================

im = readmatrix('test_20231108_jpg.txt');

if RGB
    raw = im;
    clear im
    m = 0;
    for i = 1:3:31
        m = m + 1;  
        for n = 1:1600
            im(m,n,:) = raw(i:i+2,n);
        end
    end
end

figure()
imshow(im, [0 255]);

