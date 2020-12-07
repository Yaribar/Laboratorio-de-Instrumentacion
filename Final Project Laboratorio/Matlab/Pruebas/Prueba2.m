clear all
close all
cam = ipcam('http://192.168.8.7:8080/videofeed');

bw_threshold=50

img = snapshot(cam);
figure;
imshow(img)

img_gray = rgb2gray(img);
figure;
imshow(img_gray)
img_bw = blackWhite(img_gray, bw_threshold);
figure;
imhist(img_gray);