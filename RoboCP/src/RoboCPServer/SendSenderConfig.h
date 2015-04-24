#pragma once
#include "Config.h"
#include "configFactory.h"
class SendSenderConfig : public Config{
public:
  SendSenderConfig();
  friend class configFactory;
  ~SendSenderConfig();
  int getPort();
  string getIP();

private:
  int Port;
  string IP;
};