#include <iostream>
#include "Unit.h"
#include "Zergling.h"
#include "Marine.h"
#include "Stalker.h"

int main()
{
	Location StartLocation = { 0 , 0 };
	Location TargetLocation = { 50 , 50 };
	Location firstTargetLocation_Zergling = { 50 , 0 };
	Location firstTargetLocation_Stalker = { 10 , 20 };
	int Init_Speed = 1;
	float dt = 0.1;
	float t = 0;
	float BlinkTime = t;
	float BlinkTimeStep = 5;
	bool isBlink = true;
	
	Zergling Zergling1 = { StartLocation , firstTargetLocation_Zergling , Init_Speed , false };
	Marine Marine1 = { StartLocation , TargetLocation , Init_Speed };
	Stalker Stalker1 = { StartLocation , firstTargetLocation_Stalker , Init_Speed };

	bool goal_flag = false;
	bool isFirstTargetReached_Zergling = false;
	bool isFirstTargetReached_Stalker = false;
	float RelativeRange;

	while (!goal_flag)
	{

		if ( !isFirstTargetReached_Zergling)
		{
			isFirstTargetReached_Zergling = Zergling1.IsSpeedUpgraded(isFirstTargetReached_Zergling);
			if (isFirstTargetReached_Zergling)
			{
				Zergling1.SetTargetLocation(TargetLocation);
			}
		}

		Marine1.IsZerglingNear(Zergling1.GetLocation());

		if (!isFirstTargetReached_Stalker)
		{
			isFirstTargetReached_Stalker = Stalker1.IsTargetUpdated(isFirstTargetReached_Stalker);
			if (isFirstTargetReached_Stalker)
			{
				Stalker1.SetTargetLocation(TargetLocation);
			}
			
		}
		if (t >= BlinkTime)
		{
			isBlink = true;
		}
		if (isBlink)
		{
			Stalker1.Blink();
			isBlink = false;
			BlinkTime = BlinkTime + BlinkTimeStep;
		}
		

		Zergling1.Move();
		Marine1.Move();
		Stalker1.Move();

		t = t + dt;

		cout << "( t = " << t << " sec ) ";
		cout << "|| Zergling : ( " << Zergling1.GetLocation().x << " , " << Zergling1.GetLocation().y << " ) -> ( " << Zergling1.GetTargetLocation().x << " , " << Zergling1.GetTargetLocation().y << " )";
		cout << "|| Marine : ( " << Marine1.GetLocation().x << " , " << Marine1.GetLocation().y << " ) -> ( " << Marine1.GetTargetLocation().x << " , " << Marine1.GetTargetLocation().y << " )";
		cout << "|| Stalker : ( " << Stalker1.GetLocation().x << " , " << Stalker1.GetLocation().y << " ) -> ( " << Stalker1.GetTargetLocation().x << " , " << Stalker1.GetTargetLocation().y << " )" << endl;

		if (Zergling1.GetLocation().x >= TargetLocation.x && Zergling1.GetLocation().y >= TargetLocation.y)
		{
			cout << "Zergling Win!" << endl;
			Zergling1.DisplayCurrentLocation();
			goal_flag = true;
		}
		if (Marine1.GetLocation().x >= TargetLocation.x && Marine1.GetLocation().y >= TargetLocation.y)
		{
			cout << "Marine Win!" << endl;
			Marine1.DisplayCurrentLocation();
			goal_flag = true;
		}
		if (Stalker1.GetLocation().x >= TargetLocation.x && Stalker1.GetLocation().y >= TargetLocation.y)
		{
			cout << "Stalker Win!" << endl;
			Stalker1.DisplayCurrentLocation();
			goal_flag = true;
		}
	}

	

	return 0;
}