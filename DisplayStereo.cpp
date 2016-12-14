#include <iostream>
#include <fstream>
#include <ApplicationServices/ApplicationServices.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "barrel/barrel_dist.hpp"

using namespace std;
using namespace cv;

Mat dup(Mat dst)
{
    cv::Size sz=dst.size();
    Mat lift(sz.height, sz.width*2, CV_8UC3);
    lift.adjustROI(0, 0, 0, -sz.width);
    dst.copyTo(lift);
    lift.adjustROI(0, 0, -sz.width, sz.width);
    dst.copyTo(lift);
    lift.adjustROI(0, 0, sz.width, 0);
    return lift;
}

Mat cvMatFromCGImage(CGImage *image)
{
    CGFloat cols, rows;
    cols=CGImageGetWidth(image);
    rows=CGImageGetHeight(image);
    Mat cvMat(rows, cols, CV_8UC4); // 8 bits per component, 4 channels
    CGContextRef contextRef = CGBitmapContextCreate(cvMat.data,             // Pointer to backing data
                                                cols,                       // Width of bitmap
                                                rows,                       // Height of bitmap
                                                8,                          // Bits per component
                                                cvMat.step[0],              // Bytes per row
                                                CGImageGetColorSpace(image),                 // Colorspace
                                                kCGImageAlphaNoneSkipLast |
                                                kCGBitmapByteOrderDefault);

    CGContextDrawImage(contextRef, CGRectMake(0, 0, cols, rows), image);
    CGContextRelease(contextRef);
    return cvMat;
}

Mat captureScreen(){
    CGDirectDisplayID displayId = CGMainDisplayID();
    CGImageRef imageRef = CGDisplayCreateImage(displayId);
    Mat img=cvMatFromCGImage(imageRef);
    CGImageRelease(imageRef);
    resize(img, img, cv::Size(img.size().width/3, img.size().height/3));
    return img;
}

int main(void)
{
    namedWindow("VR vision");
    while(true){
        IplImage input=captureScreen();
        PrepareBarrelDistortion(&input, input.width/2, input.height/2,.0000008,.0000016);
        Mat dst=BarrelDistortion(&input);
        Mat lift;
        hconcat(dst, dst, lift);
        dst.release();
        imshow("Result", lift);
        waitKey(1);
        lift.release();
    }
    system("pause");
    destroyWindow("VR vision");
    return 0;
}
