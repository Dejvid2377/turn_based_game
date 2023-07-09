#include "../inc/unit.hh"

uint Unit::instanceCounter = 0;

void Unit::increaseCounter() {
    instanceCounter++;
}

uint Unit::getCounter() { return instanceCounter; }

//class parametric constructor
Unit::Unit(char v1, UnitType v2, uint v3, uint v4, uint v5, int v6, uint v7)
    : member(v1),
      type(v2),
      ID(v3),
      x_position(v4),
      y_position(v5),
      durability(v6),
      speed(v7)
{
}

void Unit::setMember(char val) { member = val; }
const char& Unit::getMember() const { return member; }

void Unit::setID(uint val)
{   
    if (instanceCounter)
     ID = val; 
}
const uint& Unit::getID() const { return ID; }

void Unit::setXY(uint valX, uint valY) {
    x_position = valX;
    y_position = valY;
}
const uint& Unit::getX() const { return x_position; }
const uint& Unit::getY() const { return y_position; }

void Unit::setDurability(int val) { durability = val; }
const int& Unit::getDurability() const { return durability; }

const uint& Unit::getSpeed() const { return speed; }

const UnitType& Unit::getType() const { return type; }




