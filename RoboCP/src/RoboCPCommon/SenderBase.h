#pragma once
#include "QtCore\qdatastream.h"
#include "QtCore\qvariant.h"
#include <QtCore/qnamespace.h>
#include <QObject>

class SenderBase : public QObject
{
  Q_OBJECT
public:
  SenderBase();
  ~SenderBase(void);

  void Start(void);
  void Stop(void);
};

QDataStream &  operator<<(QDataStream &ds, const SenderBase &obj);
QDataStream & operator>>(QDataStream &ds, SenderBase &obj);