#pragma once
/*
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
*/
#include "QtXml\qdom.h"
#include "SenderBase.h"
#include <QObject>

class Point3d //: public SenderBase
{
	/*
  template <typename Archive>
  void serialize(Archive& ar, const unsigned int version)
  {
    ar & BOOST_SERIALIZATION_NVP(x);
    ar & BOOST_SERIALIZATION_NVP(y);
    ar & BOOST_SERIALIZATION_NVP(z);
  }*/
  
	//Q_OBJECT
//Q_PROPERTY(short x READ getx WRITE setx)
	//	Q_PROPERTY (short y READ gety WRITE sety)
	//	Q_PROPERTY (short z READ getz WRITE setz)

  short x;
  short y; 
  short z;

public:
	short getx() const {return x;}
	void setx(short newx) {x=newx;}
	short gety() const {return y;}
	void sety(short newy) {y=newy;}
	short getz() const {return z;}
	void setz(short newz) {z=newz;};
};