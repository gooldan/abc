#pragma once
#include "ReceivedBuffer.h"
#include "NanoReceived.h"
#include "QtCore\qsharedpointer.h"

class NanoReceivedBuffer :
  public ReceivedBuffer< QSharedPointer<NanoReceived> >
{
public:
	NanoReceivedBuffer (int size) : ReceivedBuffer< QSharedPointer<NanoReceived> > (size) {}
};

