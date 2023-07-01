#ifndef UNIT_HH
#define UNIT_HH

#include "libraries.hh"

enum class UnitType : char {
  Knight = 'K', Swordsman = 'S', Archer = 'A', Pikeman = 'P',
  Ram = 'R', Catapult = 'C', Worker = 'W', Base = 'B', NoUnit = '0'
};

class Unit {
private:
    static uint instanceCounter;
protected:
    char member;
    UnitType type;
    uint ID;
    uint x_position;
    uint y_position;
    int durability;
    uint speed;
    void increaseCounter();
    void setMember(uint val);
    void setID(uint val);
    void setXY(uint valX, uint valY);
    void setDurability(int val);
public:
    Unit(char, UnitType, uint, uint, uint, int, uint);
    uint getCounter();
    const char& getMember() const;
    const UnitType& getType() const;
    const uint& getID() const;
    const uint& getX() const;
    const uint& getY() const;
    const int& getDurability() const;
    const uint& getSpeed() const;
};

#endif
