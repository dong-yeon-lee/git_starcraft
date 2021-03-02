#include <iostream>
#include "Unit.h"

using namespace std;

Unit::Unit()
	: currentLocation_({ 0 , 0 })
	, targetLocation_({0 , 0})
{
}

Unit::Unit(Location currentLocation , Location targetLocation)
	: currentLocation_(currentLocation)
	, targetLocation_(targetLocation)
{
}

Unit::Unit(const Unit& others)
    : currentLocation_(others.currentLocation_)
	, targetLocation_(others.targetLocation_)
{
}

Unit::~Unit()
{
}

void Unit::SetLocation(const float x, const float y)
{
	currentLocation_ = { x , y };
}

Location Unit::GetLocation() const
{
	Location result = currentLocation_;

	return result;
}

void Unit::SetTargetLocation(const Location targetLocation)
{
	targetLocation_ = targetLocation;
}

Location Unit::GetTargetLocation() const
{
	Location result = targetLocation_;

	return result;
}

void Unit::DisplayCurrentLocation() const
{
	cout << "Current Location : ( " << currentLocation_.x << " , " << currentLocation_.y << " )" << " Target  Location : ( " << targetLocation_.x << " , " << targetLocation_.y << " )" << endl;
}



