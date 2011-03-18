#include <cv.h>       /* for OpenCV basic structures for ex.: IPLImage */
#include <highgui.h>  /* for OpenCV functions like cvCvtColor */
#include <stdio.h>

IplImage * 
cvLoadImageYUV(FILE *fin, int w, int h)
{
    assert(fin);

    IplImage *py      = cvCreateImage(cvSize(w,    h), IPL_DEPTH_8U, 1);
    IplImage *pu      = cvCreateImage(cvSize(w/2,h/2), IPL_DEPTH_8U, 1);
    IplImage *pv      = cvCreateImage(cvSize(w/2,h/2), IPL_DEPTH_8U, 1);
    IplImage *pu_big  = cvCreateImage(cvSize(w,    h), IPL_DEPTH_8U, 1);
    IplImage *pv_big  = cvCreateImage(cvSize(w,    h), IPL_DEPTH_8U, 1);
    IplImage *image   = cvCreateImage(cvSize(w,    h), IPL_DEPTH_8U, 3);
    IplImage *result  = NULL;

    assert(py);
    assert(pu);
    assert(pv);
    assert(pu_big);
    assert(pv_big);
    assert(image);

    for (int i = 0; i < w*h; ++i)
    {
        int j = fgetc(fin);
        if (j < 0)
            goto cleanup;
        py->imageData[i] = (unsigned char) j;
    }

    for (int i = 0; i < w*h/4; ++i)
    {
        int j = fgetc(fin);
        if (j < 0)
            goto cleanup;
        pu->imageData[i] = (unsigned char) j;
    }

    for (int i = 0; i < w*h/4; ++i)
    {
        int j = fgetc(fin);
        if (j < 0)
            goto cleanup;
        pv->imageData[i] = (unsigned char) j;
    }

    cvResize(pu, pu_big, CV_INTER_NN);
    cvResize(pv, pv_big, CV_INTER_NN);
    cvMerge(py, pu_big, pv_big, NULL, image);

    result = image;

cleanup:
    cvReleaseImage(&pu);
    cvReleaseImage(&pv);

    cvReleaseImage(&py);
    cvReleaseImage(&pu_big);
    cvReleaseImage(&pv_big);

    if (result == NULL)
        cvReleaseImage(&image);

    return result;
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


