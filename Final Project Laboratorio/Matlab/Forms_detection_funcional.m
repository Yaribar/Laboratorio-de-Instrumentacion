
clear all
close all

labview = serialport("COM1",115200);
configureTerminator(labview,"CR/LF")
cam = ipcam('http://192.168.8.7:8080/videofeed');
bw_threshold = 63;

while true
    
    if labview.NumBytesAvailable~=0
        
        object_presence = read(labview,1,"string")
        object_presenceint = str2num(object_presence);
        if object_presenceint == 1
            pause(1)
            img = snapshot(cam);
        end
        %img = imread("rectangulo.jfif");
        %figure;
        %imshow(img)
        
        img_gray = rgb2gray(img);
        img_bw = blackWhite(img_gray, bw_threshold);
        %imshow(img_bw);
        %subplot 233
        img_filt = medfilt2(img_bw,[20 20]);
        %imshow(img_filt);
        %subplot 234
        
        %cropping 1 parametes
        row_start = 200 ;
        row_end = 900;
        col_start = 500;
        col_end = 1500;
        
        
        cropped_img = img_filt(row_start:row_end,col_start:col_end,:);
        %imshow(cropped_img)
        %subplot 235
        
        stats = regionprops('table',cropped_img,'Centroid','MajorAxisLength','MinorAxisLength','Area')
        
        Square_areathreshold = 150000; %1
        Circle_areathreshold = 101000; %2
        Triangle_areathreshold = 110000; %3
        
        
        Shape= 0;
        %imshow(cropped_img)
        
        stats2 = stats{:,:}
        
        [max_num,max_idx] = max(stats2(:))
        
        if stats.Area(max_idx) > Square_areathreshold
            Shape = 1
        elseif stats.Area(max_idx) > Triangle_areathreshold & stats.Area(max_idx) < Square_areathreshold
            Shape = 2
        else
            Shape = 3
        end
        
        cropped_RGBimg = img(row_start:row_end,col_start:col_end,:);
        
        
        if max_idx > 1
            
            img_centroid = imcrop(cropped_RGBimg,[stats.Centroid(max_idx)-25 stats.Centroid(max_idx+length(stats.Centroid))-25 50 50]);
        else
            
            img_centroid = imcrop(cropped_RGBimg,[stats.Centroid(1)-25 stats.Centroid(2)-25 50 50]);
            
        end
        
        %figure;
        %imshow(img_centroid)
        
        
        RGB_average = [0,0,0];
        for k=1:3
            RGB_average(k) = mean(img_centroid(:,:,k),'all');
            k
        end
        
        data_out = [RGB_average Shape];
        data_out_string = sprintf('%.0f,' , data_out);
        data_out_string = data_out_string(1:end-1)% strip final comma
        writeline(labview,data_out_string)
        flush(labview)
        
        RGB_average = [];
        data_out = [];
            
    end
    
end

