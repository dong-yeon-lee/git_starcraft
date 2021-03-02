#include <iostream>
#include "Stalker.h"

using namespace std;

Stalker::Stalker()
	: Unit({ 0,0 } , { 0 , 0 })
	, moveSpeed(1)
{
}

Stalker::Stalker(Location currentLocation_, Location targetLocation_, int moveSpeed)
	: Unit(currentLocation_, targetLocation_)
	, moveSpeed(moveSpeed)
{
}

Stalker::Stalker(const Stalker& others)
	: Unit(others)
	, moveSpeed(others.moveSpeed)
{
}

Stalker::~Stalker()
{
}

void Stalker::Move()
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

void Stalker::Blink()
{
	float Dir;
	float dx;
	float dy;
	float Blink_dist = 5;

	Dir = atan2((GetTargetLocation().y - GetLocation().y), (GetTargetLocation().x - GetLocation().x));

	dx = Blink_dist * cos(Dir);
	dy = Blink_dist * sin(Dir);

	SetLocation(GetLocation().x + dx, GetLocation().y + dy);
}

bool Stalker::IsTargetUpdated(const bool isFirstTargetReached)
{
	float RelativeRange;
	float dt = 0.1;

	RelativeRange = sqrt(pow((GetTargetLocation().x - GetLocation().x), 2) + pow((GetTargetLocation().y - GetLocation().y), 2));

	if (!isFirstTargetReached && RelativeRange <= moveSpeed * dt)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}












