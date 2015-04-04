#pragma once
#include "ReceivedBuffer.h"
#include "Send.h"
#include "QtCore\qsharedpointer.h"

using namespace std;

class SendBuffer : public ReceivedBuffer < QSharedPointer<Send> >
{
public:
	SendBuffer (int size) : ReceivedBuffer< QSharedPointer<Send> > (size) {}
};

