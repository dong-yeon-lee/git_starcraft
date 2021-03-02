#pragma once

#include <iostream>
#include <cmath>

using namespace std;

struct Location
{
    float x;
    float y;
};

class Unit
{
public:
    Unit();
    Unit(Location currentLocation_ , Location targetLocation_);
    Unit(const Unit& other);
    virtual ~Unit();

    virtual void SetLocation(const float x, const float y);
    virtual Location GetLocation() const;
    virtual void Move() = 0;
    virtual void DisplayCurrentLocation() const;

    virtual void SetTargetLocation(const Location targetLocation_);
    virtual Location GetTargetLocation() const;

private:
    Location currentLocation_;
    Location targetLocation_;
};



