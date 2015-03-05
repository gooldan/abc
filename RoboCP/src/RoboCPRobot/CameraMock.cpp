#include "CameraMock.h"


CameraMock::CameraMock(XMLConfig *x, CameraReceivedBuffer *buf)
{
  buffer = buf;
  cameraNum = x->CameraNumber;
  fps = x->CameraFramesPerSecond;
  width = x->CameraFrameWidth;
  height = x->CameraFrameHeight;
}


CameraMock::~CameraMock(void)
{
}

CameraReceivedBuffer *CameraMock::GetBuffer(void)
{
  return buffer;
}

void CameraMock::Start(void)
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
	
	boost::shared_ptr<CameraReceived> CameraImg(new CameraReceived(Frame));
	
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
