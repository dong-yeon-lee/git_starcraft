#pragma once

#include <iostream>
#include "Unit.h"

class Zergling : public Unit
{
public:
    Zergling();
    Zergling(Location currentLocation_, Location targetLocation_, int moveSpeed, bool speedUpgrade);
    Zergling(const Zergling& other);
    virtual ~Zergling();

    void Move();
    bool IsSpeedUpgraded(const bool isFirstTargetReached);
private:
    int moveSpeed;
    bool speedUpgrade;
};
