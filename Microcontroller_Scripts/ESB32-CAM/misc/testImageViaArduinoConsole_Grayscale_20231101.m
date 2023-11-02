
clearvars, clc, close all

im = load('testImageViaArduinoConsole_Grayscale_20231101.txt');
im2 = load('testImageViaArduinoConsole_Grayscale_20231101_v2.txt');

% figure()
% imshow(im, [0, 255]);

figure()
imshow(im2, [0, 255]);
