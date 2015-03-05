#pragma once
#include "Controller.h"
#include "controller.h"
#include <time.h>
#include <cv.h>
#include <highgui.h>
#include "XMLConfig.h"
#include "CameraReceivedBuffer.h"
#include "ImageFlowProcessing.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;
class CameraMock :
	public Controller
{
private:
  int cameraNum;
  int fps;
  int width;
  int height;
  CameraReceivedBuffer *buffer;
public:
	CameraMock(XMLConfig *x, CameraReceivedBuffer *buf);
	~CameraMock(void);
	CameraReceivedBuffer *GetBuffer(void);
	void Start(void);
};

