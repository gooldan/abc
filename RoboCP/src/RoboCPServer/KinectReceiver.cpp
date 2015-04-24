#pragma once
#include "KinectReceiver.h"
#include "controller.h"

KinectReceiver::KinectReceiver (XMLConfig * x, KinectBuffer* b)
{
  ip = QString(x->IP.c_str()); // Reading IP from config
  port = QString(x->KinectPort.c_str()); // Reading port from config
  kinectBuffer = b;

  // We will receive encoded point clouds, so we need to decode them
  octreeCoder = new PointCloudCompression<PointXYZ> (x->CompressionProfile, x->ShowStatistics, x->PointResolution,
                                                         x->OctreeResolution, x->DoVoxelGridDownDownSampling, x->IFrameRate,
                                                         x->DoColorEncoding, x->ColorBitResolution);
}

KinectReceiver::~KinectReceiver ()
{
  delete (octreeCoder);
}

void KinectReceiver::Start ()
{
  try {
		tcp::iostream socketStream(ip.toUtf8().data(), port.toUtf8().data()); // Trying to connect

    if (!socketStream.fail() ) {
      cout << "KinectReceiver: Connected!" << endl; // TODO: write in log
      #ifdef ENABLE_LOGGING
	    RAW_LOG (INFO,  "KinectReceiver: Connected!");
      #endif
		Sleeper::msleep (5000);

	    while (true ) {
		    QSharedPointer<KinectData> kData (new KinectData); // Creating new KinectData
		    socketStream >> kData->Time; // Receivig time
		    octreeCoder->decodePointCloud (socketStream, kData->Cloud); // Then receiving point cloud
		    kinectBuffer->Enqueue (kData); // adding KinectData in KinectBuffer
	    }
	  }
  }
  catch (exception& e) {
    cout << "KinectReceiver: Exception: " << e.what () << endl; // TODO: write in log
    #ifdef ENABLE_LOGGING
	  RAW_LOG (INFO,  "KinectReceiver: Exception: %s", e.what());
    #endif
  }
}