imagen = imread('Test1_original.bmp');

im_r =(imagen(:,:,1)) ;
im_g =(imagen(:,:,2)) ;
im_b =(imagen(:,:,3)) ;

ImagenfinalRGB(:,:,3)=im_b ;
ImagenfinalRGB(:,:,2)=im_g ;
ImagenfinalRGB(:,:,1)=im_r;

ImagenfinalRGB=double(ImagenfinalRGB);imshow(ImagenfinalRGB);title('Imagen recuperada');

