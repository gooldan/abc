#pragma once
#include <QObject>

struct RoboPoint3d
{
	short x;
	short y;
	short z;
};

Q_DECLARE_METATYPE(RoboPoint3d)