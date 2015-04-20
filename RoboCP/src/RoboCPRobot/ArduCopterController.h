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
 uchar f[] = { 254, 18, 0, 255, 190, 70, 216, 5, 218, 5, 49, 4, 224, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 };
 uchar a[] = { 254, 18, 0, 255, 190, 70, 216, 5, 218, 5, 49, 4, 52,  4, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 };
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
	int timePassed;
	bool doWork;
	char stage;
  void sendInitionalData(void);
	void EvaluateCommand(Command comm);
	unsigned char* currentControlState;
	int packetcount;
public:
  void Start(void);
	void NormalStart(void);
	void Work(void);
	void Configure(Config *x, ArduCopterBuffer *buf, CommandBuffer *combuf);
  void FakeStart(void);
  ArduCopterController();
  ~ArduCopterController(void);
};

