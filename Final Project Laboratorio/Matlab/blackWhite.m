function input_image = blackWhite(input_image, threshold)
    for i=1:size(input_image,1)
        for j=1:size(input_image,2)
            if input_image(i,j) >= threshold
               input_image(i,j) = 255;
            else
               input_image(i,j) = 0;
            end
        end
    end
end