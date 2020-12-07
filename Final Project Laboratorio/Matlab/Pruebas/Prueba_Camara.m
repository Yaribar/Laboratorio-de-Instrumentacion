cam = ipcam('http://192.168.8.7:8080/videofeed');


imgip = snapshot(cam);

imshow(imgip)