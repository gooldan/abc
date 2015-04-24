#pragma once
#include <cv.h>
#include <highgui.h>
#include <QObject>
#define MAX_COUNT 400 

struct DisplacementVector
{
	float  BeginningX;
	float  BeginningY;
	float  EndX;
	float  EndY;
	double Length;
};

Q_DECLARE_METATYPE(DisplacementVector)

class DisplacementImages
{
public:
	DisplacementVector *Vectors;
	DisplacementVector Motion;
	int NumVectors;
	void CountMotion(void);
	double Dist(CvPoint2D32f Point1, CvPoint2D32f Point2);
	DisplacementImages(void);
	~DisplacementImages(void);
};