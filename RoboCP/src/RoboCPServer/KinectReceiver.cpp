#pragma once
#include "KinectReceiver.h"
#include "QtTest\qtest.h"

KinectReceiver::KinectReceiver (XMLConfig * x, KinectBuffer* b)
{
  ip = x->IP; // Reading IP from config
  port = x->KinectPort; // Reading port from config
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
    tcp::iostream socketStream (ip.toStdString().c_str(), port.toStdString().c_str() ); // Trying to connect

    if (!socketStream.fail() ) {
      cout << "KinectReceiver: Connected!" << endl; // TODO: write in log
      #ifdef ENABLE_LOGGING
	    RAW_LOG (INFO,  "KinectReceiver: Connected!");
      #endif
	    QTest::qSleep (5000);

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