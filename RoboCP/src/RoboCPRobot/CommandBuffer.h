#pragma once
#include "ReceivedBuffer.h"
#include "Command.h"
#include "QtCore\qsharedpointer.h"

class CommandBuffer :  public ReceivedBuffer <QSharedPointer<Command>>
{
public:
  CommandBuffer (int size) : ReceivedBuffer <QSharedPointer<Command>> (size) {}
};

