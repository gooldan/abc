#include "KinectController.h"

KinectController::KinectController(KinectBuffer * buf)
{
	buffer = buf;
}

void KinectController::grabberCallBack(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
{
	PointCloud<PointXYZ>::Ptr cld(new PointCloud<PointXYZ>(*cloud));
	QSharedPointer <KinectData> kData(new KinectData(cld, time(NULL))); // Creating KinectData
	buffer->Enqueue(kData); // Adding it to buffer
}

void KinectController::Start(void)
{
	Grabber* interface = new OpenNIGrabber(); // Creating new grabber

	boost::function<void
		(const PointCloud<PointXYZ>::ConstPtr&)> f = boost::bind(&KinectController::grabberCallBack, this, _1);

	boost::signals2::connection c = interface->registerCallback(f);

	interface->start();
}

KinectController::~KinectController()
{
}

void KinectController::FakeStart()
{
	cout << "KinectController: loading clouds..." << endl; //TODO: write in log
#ifdef ENABLE_LOGGING
	RAW_LOG (INFO, "KinectController: loading clouds...!");
#endif

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("KinectCloud1.pcd", *cloud1); // loading clouds from HDD
	pcl::io::loadPCDFile<pcl::PointXYZ>("KinectCloud2.pcd", *cloud2);
	cout << "KinectController: ready" << endl; //TODO: write in log
#ifdef ENABLE_LOGGING
	RAW_LOG (INFO, "KinectController: ready");
#endif
	while (true) { // Making new KinectData every 2 seconds
		Sleeper::msleep(100);
		QSharedPointer <KinectData> kData1(new KinectData(cloud1, time(NULL)));
		buffer->Enqueue(kData1);

		Sleeper::msleep(100);
		QSharedPointer <KinectData> kData2(new KinectData(cloud2, time(NULL)));
		buffer->Enqueue(kData2);
	}
}