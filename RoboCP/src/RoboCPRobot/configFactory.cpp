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
    config->Port = treeOfObject.value("Port").toInt();
    return config;
  }
  if (type == "Command"){
    CommandConfig *config= new CommandConfig();
    config->Port = treeOfObject.value("Port").toInt();
    return config;
  }
  if (type == "Send"){
    SendConfig *config= new SendConfig();
    config->Port = treeOfObject.value("Port").toInt();
    config->IsAvailable = treeOfObject.value("IsAvailable").toInt();
    return config;
  }
  if (type == "Carduino"){
    CarduinoConfig *config= new CarduinoConfig();
    config->Port = treeOfObject.value("Port").toString().toStdString();
    return config;
  }
  if (type == "Arducopter"){
    ArducopterConfig *config= new ArducopterConfig();
		const QByteArray asc = treeOfObject.value("Port").toString().toUtf8(); 
		for (int i = 0; i < asc.length(); ++i)
		{
			cout << asc[i];
		}
		string str = string(asc.constData(), asc.length());
		config->Port = treeOfObject.value("Port").toString().toStdString();
    config->IsAvailable = treeOfObject.value("IsAvailable").toInt();
    config->DoFakeStart = treeOfObject.value("DoFakeStart").toInt();
    return config;
  }
  if (type == "Camera"){
    CameraConfig *config= new CameraConfig();
    config->Number = treeOfObject.value("Number").toInt();
    config->FramesPerSecond = treeOfObject.value("FramesPerSecond").toInt();
    config->FrameWidth = treeOfObject.value("FrameWidth").toInt();
    config->FrameHeight = treeOfObject.value("FrameHeight").toInt();
    return config;
  }
  if (type == "SendSender"){
    SendSenderConfig *config= new SendSenderConfig();
    config->Port = treeOfObject.value("Port").toInt();
    config->IP = treeOfObject.value("IP").toString().toStdString();
    return config;
  }

return nullptr;
}

Config* configFactory::ConfigByName(QString configName)
{
	return MapOfConfigs[configName];
}