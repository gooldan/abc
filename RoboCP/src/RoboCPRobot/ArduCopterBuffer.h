#pragma once
#include "ReceivedBuffer.h"
#include "ArduCopterReceived.h"
#include "QtCore\qsharedpointer.h"

class ArduCopterBuffer : public ReceivedBuffer < QSharedPointer<ArduCopterReceived> >
{
public:
	ArduCopterBuffer (int size) : ReceivedBuffer < QSharedPointer<ArduCopterReceived> > (size) {}
};

