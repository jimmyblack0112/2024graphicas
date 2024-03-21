///File-New 空白檔案, 成 week05-1_opencv.cpp
#include <opencv/highgui.h>
int main()
{///Intel performence library
    IplImage * img = cvLoadImage("c:/image.jpg");
    cvShowImage("week05", img);
    cvWaitKey(0);
}
