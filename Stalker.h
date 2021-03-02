#pragma once

#include <iostream>
#include "Unit.h"

class Stalker : public Unit
{
public:
    Stalker();
    Stalker(Location currentLocation_, Location targetLocation_, int moveSpeed);
    Stalker(const Stalker& other);
    virtual ~Stalker();

    void Move();
    void Blink();
    bool IsTargetUpdated(const bool isFirstTargetReached);
private:
    int moveSpeed;
};