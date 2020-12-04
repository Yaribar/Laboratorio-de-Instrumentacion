clear all
close all
cam = ipcam('http://192.168.8.7:8080/videofeed');


img = snapshot(cam);

imshow(img)

img_gray = rgb2gray(img);

img_bw = imbinarize(img_gray);

img_filt = medfilt2(img_bw,[20 20]);

%cropping parametes

row_start = 200 ;
row_end = 900;
col_start = 400;
col_end = 1500;

cropped_img = img_filt(row_start:row_end,col_start:col_end,:);



stats = regionprops('table',cropped_img,'Centroid','MajorAxisLength','MinorAxisLength','Area') 

Square_areathreshold = 150000; %1
Circle_areathreshold = 101000; %2
Triangle_areathreshold = 85000; %3

Shape= 0;
imshow(cropped_img)

stats2 = stats{:,:}

[max_num,max_idx] = max(stats2(:))

if stats.Area(1) > Square_areathreshold
        Shape = 1
elseif stats.Area(1) > Triangle_areathreshold & stats.Area(max_idx) < Square_areathreshold
        Shape = 2
    else
        Shape = 3
end

cropped_RGBimg = img(row_start:row_end,col_start:col_end,:);



img_centroid = imcrop(cropped_RGBimg,[stats.Centroid(max_idx)-25 stats.Centroid(max_idx+length(stats.Centroid))-25 50 50]);
figure;
imshow(img_centroid)


RGB_average = [0,0,0];
for i=1:3
RGB_average(i) = mean(img_centroid(:,:,i),'all');
end


data_out = [RGB_average Shape]

data_outString = sprintf('%.0f,' , data_out);
data_outString = data_outString(1:end-1)% strip final comma    

