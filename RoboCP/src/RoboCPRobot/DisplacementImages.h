#pragma once
#include <cv.h>
#include <highgui.h>
/*
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
*/

#include "QtCore\qdatastream.h"

#include "QtXml\qdom.h"
#include "SenderBase.h"

#include <QObject>
#define MAX_COUNT 400 

typedef struct Vector //: public SenderBase
{
	/*
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_NVP(BeginningX);
		ar & BOOST_SERIALIZATION_NVP(BeginningY);
		ar & BOOST_SERIALIZATION_NVP(EndX);
		ar & BOOST_SERIALIZATION_NVP(EndY);
		ar & BOOST_SERIALIZATION_NVP(Length);
	}*/

	//Q_OBJECT
		//Q_PROPERTY(float BeginningX READ getBeginningX WRITE setBeginningX)
		/*Q_PROPERTY(float EndX READ getEndX WRITE setEndX)
		Q_PROPERTY(float BeginningY READ getBeginningY WRITE setBeginningY)
		Q_PROPERTY(float EndY READ getEndY WRITE setEndY)
		Q_PROPERTY(double Length READ getLength WRITE setLength)*/

	float BeginningX, EndX, BeginningY, EndY;
	double Length;

public:
	float getBeginningX() const {return BeginningX;}
	void setBeginningX(float newBeginningX) {BeginningX=newBeginningX;}
	float getEndX() const {return EndX;}
	void setEndX(float newEndX) {EndX=newEndX;}
	float getBeginningY() const {return BeginningY;}
	void setBeginningY(float newBeginningY) {BeginningY=newBeginningY;}
	float getEndY() const {return EndY;}
	void setEndY(float newEndY) {EndY=newEndY;}
	double getLength() const {return Length;}
	void setLength(double newLength) {Length=newLength;};
}
Vector;

class DisplacementImages
{
public:
	Vector *Vectors;
	Vector Motion;
	int NumVectors;
	void CountMotion(void);
	double Dist(CvPoint2D32f Point1, CvPoint2D32f Point2);
	DisplacementImages(void);
	~DisplacementImages(void);
};

