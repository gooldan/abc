#pragma once
#include "Controller.h"
#include <time.h>
#include <cv.h>
#include <highgui.h>
#include "XMLConfig.h"
#include "CameraReceivedBuffer.h"
#include "ImageFlowProcessing.h"
#include <stdlib.h>
#include <stdio.h>

class CameraController :
	public Controller
{
private:
	int cameraNum;
	int fps;
	int width;
	int height;
	int VideoStreamType;
	string FileName;
	CameraReceivedBuffer *buffer;
public:
<<<<<<< HEAD
  void Start(void);
  void FakeStart(void);
  CameraReceivedBuffer *GetBuffer(void);
  CameraController(XMLConfig *x, CameraReceivedBuffer *buf);
  ~CameraController(void);
=======
	void Start(void);
	void FakeStart(void);
	CameraReceivedBuffer *GetBuffer(void);
	CameraController(XMLConfig *x, CameraReceivedBuffer *buf);
	~CameraController(void);
>>>>>>> origin/master
};

