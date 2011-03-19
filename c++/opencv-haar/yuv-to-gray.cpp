#include <cv.h>       /* for OpenCV basic structures for ex.: IPLImage */
#include <highgui.h>  /* for OpenCV functions like cvCvtColor */
#include <stdio.h>

IplImage * 
cvLoadImageYUV(FILE *fin, int w, int h)
{
    /* On grayscale Y = R = B = G. Pretty easy :-) */
    IplImage *image   = cvCreateImage(cvSize(w, h), IPL_DEPTH_8U, 3);
    int j = 0;    

    assert(image);
    assert(fin);

    /* We read only Y information */
    for (int i = 0; i < w*h; ++i)
    {
        unsigned char y_sample = fgetc(fin);

        if (y_sample < 0) {
            printf("Error, dont have enough samples !!!\n");
            exit(-1);
        }

        /* We must write R G B with the same Y*/
        image->imageData[j] = y_sample;
        image->imageData[j + 1] = y_sample;
        image->imageData[j + 2] = y_sample;
        j += 3;
    }

    return image;
}



int main (int argc, char ** argv)
{
    FILE * input      = NULL;
    IplImage * output = NULL;
    int width         = 0;
    int height        = 0;

    if (argc < 5) {
        printf("usage: [%s] <input yuv 4:2:0 image file> <input image width> <input image height> <output image file>\n", argv[0]);
        return 0;
    }

    input = fopen(argv[1], "r");
    
    if (!input) {
        printf("Error opening file[%s]\n", argv[1]);
        return -1;
    }

    width  = atoi(argv[2]);
    height = atoi(argv[3]);

    output = cvLoadImageYUV(input, width, height);

    if (!output) {
        printf("error generating output image !!!\n");
        return -1;
    }

    if (cvSaveImage(argv[4], output)) {
        printf("Generated image[%s]\n", argv[4]);
    } else {
        printf("Error Generating image[%s]\n", argv[4]);
    }

    cvReleaseImage(&output);
    fclose(input);
    return 0;
}


