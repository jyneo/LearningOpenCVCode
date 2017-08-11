/**
  * @file:            ch2_ex2_5.cpp
  * @description:     Description
  * @author:          yangjun
  * @copyright (c):   2017 yangjun. All Rights Reserved
  * @date             2017/8/10 18:09
  */ 

#include "cv.h"
#include "highgui.h"


IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5)
{
	// Best to make sure input image is divisible by two.
	assert(in->width % 2 == 0 && in->height % 2 == 0);

	IplImage* out = cvCreateImage(cvSize(in->width / 2, in->height / 2), in->depth, in->nChannels);
	cvPyrDown(in, out);
	return(out);
};

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("F:\\visual studio 2017 project\\LearningOpenCV_Code\\lena\\lena.jpg");
	IplImage* img2 = cvCreateImage(cvSize(img->width / 2, img->height / 2), img->depth, img->nChannels);
	//IplImage* img2 = cvCreateImage(cvSize(img->width, img->height), img->depth, img->nChannels);

	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	
	cvShowImage("Example1", img);
	img2 = doPyrDown(img);
	cvShowImage("Example2", img2);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img2);
	cvDestroyWindow("Example1");
	cvDestroyWindow("Example2");
}