#include "SendProcessing.h"

SendProcessing::SendProcessing(NanoReceivedBuffer *nano, ArduCopterBuffer *ardu, CameraReceivedBuffer *camera, SendBuffer *send)
{
  nanoBuffer = nano;
  arduBuffer = ardu;
  sendBuffer = send;
  cameraBuffer = camera;
}

void SendProcessing::Start()
{
	QSharedPointer <ArduCopterReceived> arduData (new ArduCopterReceived);
	QSharedPointer <NanoReceived> nanoData (new NanoReceived);
	QSharedPointer <CameraReceived> cameraData (new CameraReceived);
  
    while (true){
	  QSharedPointer <Send> sendData(new Send);
//	  sendData->Time = time(NULL);
	  
	  if (arduBuffer->Used->try_wait()){
		arduBuffer->Used->post();
        arduData = arduBuffer->Dequeue();
	  }
        //sendData->Acceleration = arduData->Acceleration;
		sendData->Roll = arduData->Roll;
		sendData->Pitch = arduData->Pitch;
		sendData->Yaw = arduData->Yaw;
		sendData->AltitudeSonic = arduData->AltitudeSonic;
		sendData->AltitudeBarometer = arduData->AltitudeBarometer;
    sendData->PacketType = arduData->PacketType;
	  
	  if (nanoBuffer->Used->try_wait()){
		nanoBuffer->Used->post();
	    nanoData = nanoBuffer->Dequeue();
	  }
        sendData->TopSonicSensor = nanoData->TopSonicSensor;
		sendData->FrontSonicSensor = nanoData->FrontSonicSensor;
		sendData->LeftSonicSensor = nanoData->LeftSonicSensor;
		sendData->RightSonicSensor = nanoData->RightSonicSensor;
		sendData->BackSonicSensor = nanoData->BackSonicSensor;
	  
		if (cameraBuffer->Used->try_wait()){
		  cameraBuffer->Used->post();
		  cameraData = cameraBuffer->Dequeue();
		}
//		sendData->Motion = cameraData->Motion;

      sendBuffer->Enqueue (sendData);
	  Sleeper::msleep (50);
  }
}

SendProcessing::~SendProcessing(void)
{
}
