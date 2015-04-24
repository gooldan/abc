#include "SendSenderConfig.h"

SendSenderConfig::SendSenderConfig():Port(0), IP("")  {
  
}
SendSenderConfig::~SendSenderConfig(){
  
}
int SendSenderConfig::getPort() {
  return Port;
}
string SendSenderConfig::getIP() {
  return IP;
}
