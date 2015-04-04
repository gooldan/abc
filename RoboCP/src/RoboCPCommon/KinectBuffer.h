#pragma once
#include "ReceivedBuffer.h"
#include "KinectData.h"
#include "QtCore\qsharedpointer.h"

using namespace std;

class KinectBuffer : public ReceivedBuffer < QSharedPointer<KinectData> >
{
public:
  KinectBuffer (int size) : ReceivedBuffer< QSharedPointer<KinectData> > (size) {}
};
