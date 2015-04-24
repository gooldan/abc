#pragma once
#include "QtCore\qdatastream.h"
#include <QObject>

class SenderBase : public QObject
{
	Q_OBJECT
public:
	SenderBase(QObject* parent = 0) : QObject(parent) {};

	void Start(void);
	void Stop(void);
};

QDataStream & operator<<(QDataStream &ds, const SenderBase &obj);
QDataStream & operator>>(QDataStream &ds, SenderBase &obj);