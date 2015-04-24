#include "ClientReceiverConfig.h"

ClientReceiverConfig::ClientReceiverConfig():CommandPort("")  {
  
}
ClientReceiverConfig::~ClientReceiverConfig(){
  
}
string ClientReceiverConfig::getCommandPort() {
  return CommandPort;
}
