#pragma once
#include "Received.h"
#include <time.h>
#include <cv.h>
#include "DisplacementImages.h"
class CameraReceived :
  public Received
{
public:
  IplImage *Frame;
  DisplacementVector Motion;
  time_t Time;
  CameraReceived(IplImage *ImageToSave);
  CameraReceived();
  ~CameraReceived(void);
};

