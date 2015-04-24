#pragma once
#include <Command.h>

Command::Command(QObject* parent)
: SenderBase(parent)
, m_CommandType(CommandType::Stay)
, m_CommandCondition(CommandCondition::PassedDistance)
, m_Value(0)
{
	//  Time = time(NULL);
}

Command::Command(CommandType commandType, CommandCondition commandCondition, float value)
{
	m_CommandType = commandType;
	m_CommandCondition = commandCondition;
	m_Value = value;
	//  Time = time(NULL);
}