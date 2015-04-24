#pragma once
#include "Config.h"
#include "configFactory.h"
class ClientReceiverConfig : public Config{
public:
  ClientReceiverConfig();
  friend class configFactory;
  ~ClientReceiverConfig();
  string getCommandPort();

private:
  string CommandPort;
};