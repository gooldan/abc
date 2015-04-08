#pragma once
#include "controller.h"
#include "Command.h"
#include "ArduCopterBuffer.h"
#include "CommandBuffer.h"
#include "configFactory.h"
#include "SerialCom.h"
#include <string.h>
#include <time.h>
#include "QtCore\qsharedpointer.h"

#ifdef ENABLE_LOGGING
#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <glog/raw_logging.h>
#endif

//#define COPTER_MSG_TYPES_TEST
//#define COPTER_TELEMETRY_TEST

#define COPTER_BAUD_RATE 115200
#define COPTER_SECONDS_TO_RECONNECT 5

class ArduCopterController :
  public Controller
{
private:
  ArduCopterBuffer *buffer;
	CommandBuffer *combuffer;
  ArducopterConfig *config;
  SerialCom *copterCom;
  QString copterPort;
  time_t lastReadTime;
	bool doWork;
	char stage;
  void sendInitionalData(void);
	char* ConvertCommandToMavlink(Command comm);
public:
  void Start(void);
	void NormalStart(void);
	void Work(void);
	void Configure(Config *x, ArduCopterBuffer *buf, CommandBuffer *combuf);
  void FakeStart(void);
  ArduCopterController();
  ~ArduCopterController(void);
};

