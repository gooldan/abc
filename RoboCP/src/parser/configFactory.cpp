#include "configFactory.h"

configFactory::~configFactory(){

}
configFactory::configFactory(){
  }

void configFactory::Parse(){
  QFile json("config.json");
  if (json.open(QIODevice::ReadOnly))
  {
    QJsonParseError  parseError;
    QJsonObject jsonDoc = QJsonDocument::fromJson(json.readAll(), &parseError).object();
    for (auto it = jsonDoc.begin(); it != jsonDoc.end(); it++)
    {
      MapOfConfigs[it.key()] = DetermineConfigObject(it.value().toObject());
    }
  }
}
Config* configFactory::DetermineConfigObject(QJsonObject treeOfObject)
{
QString type = treeOfObject.value("Type").toString();
  if (type == "Kinect"){
    KinectConfig *config= new KinectConfig();
	config->Port = treeOfObject.value("Port").toDouble();
    return config;
  }
  if (type == "Command"){
    CommandConfig *config= new CommandConfig();
	config->Port = treeOfObject.value("Port").toDouble();
    return config;
  }
  if (type == "Send"){
    SendConfig *config= new SendConfig();
	config->Port = treeOfObject.value("Port").toDouble();
	config->IsAvailable = treeOfObject.value("IsAvailable").toDouble();
    return config;
  }
  if (type == "Carduino"){
    CarduinoConfig *config= new CarduinoConfig();
    config->Port = treeOfObject.value("Port").toString().toUtf8().data();
    return config;
  }
  if (type == "Arducopter"){
    ArducopterConfig *config= new ArducopterConfig();
		config->Port = treeOfObject.value("Port").toString().toUtf8().data();
	config->IsAvailable = treeOfObject.value("IsAvailable").toDouble();
	config->DoFakeStart = treeOfObject.value("DoFakeStart").toDouble();
    return config;
  }
  if (type == "Camera"){
    CameraConfig *config= new CameraConfig();
	config->Number = treeOfObject.value("Number").toDouble();
	config->FramesPerSecond = treeOfObject.value("FramesPerSecond").toDouble();
	config->FrameWidth = treeOfObject.value("FrameWidth").toDouble();
	config->FrameHeight = treeOfObject.value("FrameHeight").toDouble();
    return config;
  }
  if (type == "SendSender"){
    SendSenderConfig *config= new SendSenderConfig();
	config->Port = treeOfObject.value("Port").toDouble();
    config->IP = treeOfObject.value("IP").toString().toUtf8().data();
    return config;
  }
  if (type == "ClientReceiver"){
    ClientReceiverConfig *config= new ClientReceiverConfig();
		config->CommandPort = treeOfObject.value("CommandPort").toString().toUtf8().data();
    return config;
  }

return nullptr;
}

Config* configFactory::ConfigByName(QString configName)
{
	return MapOfConfigs[configName];
}