#pragma once
/*
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
*/

#include <time.h>
#include "SenderBase.h"

#include <QObject>

enum CommandType{
	MoveForward,
	Rotate,
	Stay
};

enum CommandCondition{
	PassedTime,
	PassedDistance,
	NearObject
};

class Command// : public SenderBase
{
 //   Q_OBJECT
public:
	//Q_PROPERTY(int ComType READ getComType WRITE setComType)
	//Q_PROPERTY(int ComCondition READ getComCondition WRITE setComCondition)
	//Q_PROPERTY (float Value READ getValue WRITE setValue)
	//Q_PROPERTY (time_t Time READ getTime WRITE setTime)
	
  Command (CommandType CType, CommandCondition CCondition, float ConditionValue);
  Command ();

  int getComType() const {return ComType;}
  void setComType(int newComType) {ComType=newComType;}
  int getComCondition() const {return ComCondition;}
  void setComCondition(int newComCondition) {ComCondition=newComCondition;}
  float getValue() const {return Value;}
  void setValue(float newValue) {Value=newValue;}
  time_t getTime() const {return Time;}
  void setTime(time_t newTime) {Time=newTime;};
private:
  int ComType;
  int ComCondition;
  float Value;
  time_t Time;
};
