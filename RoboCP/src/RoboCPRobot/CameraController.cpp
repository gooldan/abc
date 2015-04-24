#include "CameraController.h"
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

CameraController::CameraController(XMLConfig *x, CameraReceivedBuffer *buf)
{
  buffer = buf;
  cameraNum = x->CameraNumber;
  fps = x->CameraFramesPerSecond;
  width = x->CameraFrameWidth;
  height = x->CameraFrameHeight;
}


CameraReceivedBuffer *CameraController::GetBuffer(void)
{
  return buffer;
}

CameraController::~CameraController(void)
{
}

void CameraController::Start(void)
{
  CvCapture *Capture;//= cvCreateCameraCapture(cameraNum);

  Capture=cvCreateCameraCapture(cameraNum);

  IplImage *Frame;
  IplImage *FrameLast = 0;
  cvSetCaptureProperty(Capture,CV_CAP_PROP_FRAME_WIDTH,width);
  cvSetCaptureProperty(Capture,CV_CAP_PROP_FRAME_HEIGHT,height);
  cvSetCaptureProperty(Capture,CV_CAP_PROP_FPS,fps);
  ImageFlowProcessing obj;
  DisplacementImages Displacement;
  
  
  while (true){
    Frame = cvQueryFrame(Capture);
	
	QSharedPointer <CameraReceived> CameraImg(new CameraReceived(Frame));

	if(FrameLast != 0)
	{
		obj.CountDisplacement(FrameLast, Frame, &Displacement);
		Displacement.CountMotion();
		CameraImg->Motion = Displacement.Motion;
	}
	CameraImg->Time = time(NULL);
    buffer->Enqueue(CameraImg);
/*	cout << (CameraImg->Motion.BeginningX-CameraImg->Motion.BeginningY)*(CameraImg->Motion.BeginningX-CameraImg->Motion.BeginningY) + (CameraImg->Motion.EndX-CameraImg->Motion.EndY)*(CameraImg->Motion.EndX-CameraImg->Motion.EndY) << "    "
		 << CameraImg->Motion.BeginningX << " "
		 << CameraImg->Motion.BeginningY << " "
		 << CameraImg->Motion.EndX << " "
		 << CameraImg->Motion.EndY << " "
		 << endl;
*/
	FrameLast = Frame;
  }
}

void CameraController::FakeStart(void)
{
	CvCapture *Capture; 
	Capture=cvCreateFileCapture("C:/Users/Svetlana/Videos/Movavi Library/Umka2.avi");
    cout<<"\nSecond camera isn't found! Videostream from file will be used.\n";

	IplImage *Frame;
  IplImage *FrameLast = 0;
  cvSetCaptureProperty(Capture,CV_CAP_PROP_FRAME_WIDTH,width);
  cvSetCaptureProperty(Capture,CV_CAP_PROP_FRAME_HEIGHT,height);
  cvSetCaptureProperty(Capture,CV_CAP_PROP_FPS,fps);
  ImageFlowProcessing obj;
  DisplacementImages Displacement;
  
  
  while (true){
    Frame = cvQueryFrame(Capture);
	
	if (Frame==NULL){
		cvSetCaptureProperty(Capture, CV_CAP_PROP_POS_AVI_RATIO , 0);
	FrameLast = cvQueryFrame(Capture);
	Frame=cvQueryFrame(Capture);
	}
	
	QSharedPointer<CameraReceived> CameraImg(new CameraReceived(Frame));
	
	if(FrameLast != 0)
	{
		obj.CountDisplacement(FrameLast, Frame, &Displacement);
		Displacement.CountMotion();
		CameraImg->Motion = Displacement.Motion;
	}
	CameraImg->Time = time(NULL);
    buffer->Enqueue(CameraImg);
	FrameLast = Frame;
  }
}

