#pragma once
#include "ClientReceiver.h"


ClientReceiver::ClientReceiver(XMLConfig * x)
{
	port = x->CommandPort.c_str(); // Reading port from config
}

ClientReceiver::~ClientReceiver(void)
{
}

void ClientReceiver::Start()
{
	try{
		QTcpSocket *socket = new QTcpSocket();
		socket->connectToHost("127.0.0.1", 9000); // Что должно быть в скобочках?
		QDataStream in(socket);
		Command com;

//		while (socket->state() == QTcpSocket::ConnectedState)
//			in >> com;
	}
	catch (exception& e) {
		cout << "ClientReceiver: Exception: " << e.what() << endl; //TODO: write in log
#ifdef ENABLE_LOGGING
		RAW_LOG(INFO, "ClientReceiver: Exception: %s", e.what());
#endif
	}



	// try {
	// 
	//  boost::asio::io_service io_service;
	//tcp::endpoint endpoint (tcp::v4 (), atoi(port.toStdString().c_str()) );
	// tcp::acceptor acceptor (io_service, endpoint);

	// tcp::iostream socketStream;

	// cout << "ClientReceiver: Waiting for connection.." << endl; //TODO: write in log
	//#ifdef ENABLE_LOGGING
	// RAW_LOG (INFO, "ClientReceiver: Waiting for connection..");
	// #endif
	// acceptor.accept (*socketStream.rdbuf ()); // waiting from connection from any IP

	// cout << "ClientReceiver: Connected!" << endl; //TODO: write in log
	//#ifdef ENABLE_LOGGING
	// RAW_LOG (INFO, "ClientReceiver: Connected!");
	// #endif 
	// boost::archive::xml_iarchive ia(socketStream); // We will receive objects in XML
	//
	// Command com;
	// while (!socketStream.fail() ) {
	//  ia >> BOOST_SERIALIZATION_NVP(com);
	//   cout << "New command: " << com.ComType << " " << com.ComCondition << " " << com.Value << endl; // TODO: command buffer
	//   #ifdef ENABLE_LOGGING
	//  RAW_LOG (INFO, "New command: %d %d %f", com.ComType, com.ComCondition, com.Value);
	//   #endif
	//}
	// 
	// }
	// catch (exception& e) {
	//   cout << "ClientReceiver: Exception: " << e.what () << endl; //TODO: write in log
	//   #ifdef ENABLE_LOGGING
	//  RAW_LOG (INFO, "ClientReceiver: Exception: %s", e.what());
	//   #endif
	// }
}