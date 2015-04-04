#pragma once
#include <time.h>
#include "Point3d.h"
#include "DisplacementImages.h"
/*
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/shared_ptr.hpp>
*/

#include "QtXml\qdom.h"
#include <time.h>
#include "SenderBase.h";
#include <QObject>


class Send : public SenderBase
{
    Q_OBJECT
	Q_PROPERTY(unsigned short TopSonicSensor READ getTopSonicSensor WRITE setTopSonicSensor)
	Q_PROPERTY(unsigned short FrontSonicSensor READ getFrontSonicSensor WRITE setFrontSonicSensor)
	Q_PROPERTY(unsigned short LeftSonicSensor READ getLeftSonicSensor WRITE setLeftSonicSensor)
    Q_PROPERTY(unsigned short RightSonicSensor READ getRightSonicSensor WRITE setRightSonicSensor)
	Q_PROPERTY(unsigned short BackSonicSensor READ getBackSonicSensor WRITE setBackSonicSensor)
	Q_PROPERTY(float Roll READ getRoll WRITE setRoll)
	Q_PROPERTY(float Pitch READ getPitch WRITE setPitch)
	Q_PROPERTY(float Yaw READ getYaw WRITE setYaw)
	Q_PROPERTY(float AltitudeSonic READ getAltitudeSonic WRITE setAltitudeSonic)
	Q_PROPERTY(float AltitudeBarometer READ getAltitudeBarometer WRITE setAltitudeBarometer)
	Q_PROPERTY(Point3d Acceleration READ getAcceleration WRITE setAcceleration)
	Q_PROPERTY(int PacketType READ getPacketType WRITE setPacketType)
	Q_PROPERTY(time_t Time READ getTime WRITE setTime)
	Q_PROPERTY(Vector Motion READ getMotion WRITE setMotion)

public:
  unsigned short TopSonicSensor;
  unsigned short FrontSonicSensor;
  unsigned short LeftSonicSensor;
  unsigned short RightSonicSensor;
  unsigned short BackSonicSensor;

  float Roll;
  float Pitch;
  float Yaw;
  float AltitudeSonic;
  float AltitudeBarometer;
    
  Point3d Acceleration;
  int PacketType;
  time_t Time;
  //IplImage *Frame;
  Vector Motion;


  unsigned short getTopSonicSensor() const {return TopSonicSensor;}
  void setTopSonicSensor(unsigned short newTopSonicSensor) {TopSonicSensor=newTopSonicSensor;}
  unsigned short getFrontSonicSensor() const {return FrontSonicSensor;}
  void setFrontSonicSensor(unsigned short newFrontSonicSensor) {FrontSonicSensor=newFrontSonicSensor;}
  unsigned short getLeftSonicSensor() const {return LeftSonicSensor;}
  void setLeftSonicSensor(unsigned short newLeftSonicSensor) {LeftSonicSensor=newLeftSonicSensor;}
  unsigned short getRightSonicSensor() const {return RightSonicSensor;}
  void setRightSonicSensor(unsigned short newRightSonicSensor) {RightSonicSensor=newRightSonicSensor;}
  unsigned short getBackSonicSensor() const {return BackSonicSensor;}
  void setBackSonicSensor(unsigned short newBackSonicSensor) {BackSonicSensor=newBackSonicSensor;}

  float getRoll() const {return Roll;}
  void setRoll(float newRoll) {Roll=newRoll;}
  float getPitch() const {return Pitch;}
  void setPitch(float newPitch) {Pitch=newPitch;}
  float getYaw() const {return Yaw;}
  void setYaw(float newYaw) {Yaw=newYaw;}
  float getAltitudeSonic() const {return AltitudeSonic;}
  void setAltitudeSonic(float newAltitudeSonic) {AltitudeSonic=newAltitudeSonic;}
  float getAltitudeBarometer() const {return AltitudeBarometer;}
  void setAltitudeBarometer(float newAltitudeBarometer) {AltitudeBarometer=newAltitudeBarometer;}
  Point3d getAcceleration() const {return Acceleration;}
  void setAcceleration(Point3d newAcceleration) {Acceleration=newAcceleration;}
  int getPacketType() const {return PacketType;}
  void setPacketType(int newPacketType) {PacketType=newPacketType;}
  time_t getTime() const {return Time;}
  void setTime(time_t newTime) {Time=newTime;}
  Vector getMotion() const {return Motion;}
  void setMotion(Vector newMotion) {Motion=newMotion;}


  Send(void);
  ~Send(void); 

};

//BOOST_SERIALIZATION_SHARED_PTR(Send)