#pragma once
#include "ReceivedBuffer.h"
#include "CameraReceived.h"
#include "QtCore\qsharedpointer.h"

class CameraReceivedBuffer :  public ReceivedBuffer <QSharedPointer<CameraReceived>>
{
public:
  CameraReceivedBuffer (int size) : ReceivedBuffer <QSharedPointer<CameraReceived>> (size) {}
};

