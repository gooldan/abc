#include "CameraReceived.h"


CameraReceived::CameraReceived(IplImage *ImageToSave)
{
        Frame = 0;
	Frame = cvCloneImage(ImageToSave);
}

CameraReceived::CameraReceived()
{
  Motion.setBeginningX(0);
  Motion.setBeginningY(0);
  Motion.setEndX(0);
  Motion.setEndY(0);
  Frame = 0;
}

CameraReceived::~CameraReceived(void)
{
  cvReleaseImage(&Frame);
}
