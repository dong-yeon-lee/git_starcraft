#pragma once

#include <iostream>
#include "Unit.h"

class Marine : public Unit
{
public:
    Marine();
    Marine(Location currentLocation_, Location targetLocation_, int moveSpeed);
    Marine(const Marine& other);
    virtual ~Marine();

    void Move();
    void IsZerglingNear(const Location zerglingCurrentLocation);
private:
    int moveSpeed;
};