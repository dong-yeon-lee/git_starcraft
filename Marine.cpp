#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using namespace std;

extern Zergling Zergling1;

firebat::firebat()
	: Unit({ 0,0 } , { 0 , 0 })
	, moveSpeed(1)
{
}

Marine::Marine(Location currentLocation_, Location targetLocation_, int moveSpeed)
	: Unit(currentLocation_, targetLocation_)
	, moveSpeed(moveSpeed)
{
}

Marine::Marine(const Marine& others)
	: Unit(others)
	, moveSpeed(others.moveSpeed)
{
}

Marine::~Marine()
{
}

void Marine::Move()
{
	float Dir;
	float dx;
	float dy;
	float dt = 0.1;

	Dir = atan2((GetTargetLocation().y - GetLocation().y), (GetTargetLocation().x - GetLocation().x));

	dx = moveSpeed * cos(Dir);
	dy = moveSpeed * sin(Dir);

	SetLocation(GetLocation().x + dx * dt, GetLocation().y + dy * dt);
}

void Marine::IsZerglingNear(const Location zerglingCurrentLocation)
{
	int ViewRange = 5;
	int UpgradedSpeed = 2;
	float RelativeRange;

	RelativeRange = sqrt(pow((GetLocation().x - zerglingCurrentLocation.x), 2) + pow((GetLocation().y - zerglingCurrentLocation.y), 2));

	if (RelativeRange <= ViewRange)
	{
		moveSpeed = UpgradedSpeed;
	}
	else
	{
		moveSpeed = 1;
	}
}














