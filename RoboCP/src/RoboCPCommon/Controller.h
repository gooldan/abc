#pragma once
#include <QtCore/qthread.h>

struct Sleeper : private QThread
{
	static void msleep(unsigned long msecs) { QThread::msleep(msecs); }
};

class Controller
{
public:
	void Start(void);
	void FakeStart(void);
	void Stop(void);
	Controller(void);
	~Controller(void);
};

