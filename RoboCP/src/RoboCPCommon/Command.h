#pragma once
#include <time.h>
#include "SenderBase.h"
#include <QObject>

class Command : public SenderBase
{
	Q_OBJECT

	Q_PROPERTY(CommandType commandType READ getCommandType WRITE setCommandType)
	Q_PROPERTY(CommandCondition commandCondition READ getCommandCondition WRITE setCommandCondition)
	Q_PROPERTY(float value READ getValue WRITE setValue)
	Q_PROPERTY (time_t time READ getTime WRITE setTime)

	Q_ENUMS(CommandType)
	Q_ENUMS(CommandCondition)

public:
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

	Command(QObject* parent = 0);
	Command(CommandType commandType, CommandCondition commandCondition, float value);

	void setCommandType(CommandType commandType)                { m_CommandType = commandType; }
	void setCommandCondition(CommandCondition commandCondition) { m_CommandCondition = commandCondition; }
	void setValue(float value)                                  { m_Value = value; }
	void setTime(time_t time)                                   { m_Time = time; };

	CommandType          getCommandType() const      { return m_CommandType; }
	CommandCondition     getCommandCondition() const { return m_CommandCondition; }
	float                getValue() const            { return m_Value; }
	time_t               getTime() const             { return m_Time; }

private:
	CommandType      m_CommandType;
	CommandCondition m_CommandCondition;
	float m_Value;
	time_t m_Time;
};