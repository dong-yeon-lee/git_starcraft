#include <iostream>
#include "Zergling.h"

using namespace std;

Zergling::Zergling()
	: Unit({ 0,0 }, { 0 , 0 })
	, moveSpeed(1)
	, speedUpgrade(false)
{
}

Zergling::Zergling(Location currentLocation_, Location targetLocation_, int moveSpeed, bool speedUpgrade)
	: Unit(currentLocation_, targetLocation_)
	, moveSpeed(moveSpeed)
	, speedUpgrade(speedUpgrade)
{
}

Zergling::Zergling(const Zergling& others)
	: Unit(others)
	, moveSpeed(others.moveSpeed)
	, speedUpgrade(others.speedUpgrade)
{
}

Zergling::~Zergling()
{
}

void Zergling::Move()
{
	float Dir;
	float dx;
	float dy;
	float dt = 0.1;
	
	Dir = atan2((GetTargetLocation().y - GetLocation().y), (GetTargetLocation().x - GetLocation().x));
	
	dx = moveSpeed * cos(Dir);
	dy = moveSpeed * sin(Dir);

	SetLocation(GetLocation().x+dx*dt , GetLocation().y+dy*dt);
}

bool Zergling::IsSpeedUpgraded(const bool isFirstTargetReached)
{
	float RelativeRange;
	float dt = 0.1;

	RelativeRange = sqrt(pow((GetTargetLocation().x - GetLocation().x), 2)+ pow((GetTargetLocation().y - GetLocation().y), 2));

	if(!isFirstTargetReached && RelativeRange <= moveSpeed*dt )
	{
		moveSpeed = 2;
		return true;
	}
	else
	{
		moveSpeed = 1;
		return false;
	}

	
}














