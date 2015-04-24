#pragma once
#include "CommandMaker.h"





CommandMaker::CommandMaker (XMLConfig * x)
{
	ip = QString(x->IP.c_str()); // Reading IP from config
	port = QString(x->CommandPort.c_str()); // Readin port from config
}

CommandMaker::~CommandMaker ()
{
}

void CommandMaker::Start ()
{
  try {
		tcp::iostream socketStream(ip.toUtf8().data(), port.toUtf8().data()); // Trying to connect

	if (!socketStream.fail() ) {
      cout << "CommandMaker: Connected!" << endl; // TODO: write in log
      #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO, "CommandMaker: Connected!");
	  #endif
	  

	  boost::archive::xml_oarchive oa(socketStream); // We want to send commands in XML
	  
	  Command com;

	  while (!socketStream.fail() ) {
		// Reading command
		cout << "input command type (int):" << endl;
		int input = 0;
		cin >> input;
		com.setCommandType(Command::CommandType(input));
		cout << "input command condition (int):" << endl;
		cin >> input;
        com.setCommandCondition(Command::CommandCondition(input));
		cout << "input condition value (float):" << endl;
		float inFloat;
		cin >> inFloat;
		com.setValue(inFloat);

		QByteArray block;
        QDataStream sendStream(&block, QIODevice::ReadWrite);
 
//        sendStream << quint16(0) << com;
        sendStream.device()->seek(0);
        sendStream << (quint16)(block.size() - sizeof(quint16));
		socketStream.write(block,block.size());
		//oa << BOOST_SERIALIZATION_NVP(com); // Sending command
	  }
	
	}
  }
  catch (exception& e) {
    cout << "CommandMaker: Exception: " << e.what () << endl; // TODO: write in log
    #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO, "CommandMaker: Exception: %s", e.what());
    #endif
  }
}
