#ifndef UNIT_HH
#define UNIT_HH

#include "libraries.hh"

//enum class type for different units on battleground
enum class UnitType : char {
  Knight = 'K', Swordsman = 'S', Archer = 'A', Pikeman = 'P',
  Ram = 'R', Catapult = 'C', Worker = 'W', Base = 'B', NoUnit = '0'
};

//base class for Base model and other units
class Unit {
private:
//static variable to monitor the number of class instances and inheriting classes
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
public:
    Unit(char, UnitType, uint, uint, uint, int, uint);
    Unit() = default;
    virtual ~Unit() {} 
    uint getCounter();
    const char& getMember() const;
    void setMember(char val);    
    const UnitType& getType() const;
    const uint& getID() const;
    void setID(uint val);    
    const uint& getX() const;
    const uint& getY() const;
    void setXY(uint valX, uint valY);    
    const int& getDurability() const;
    void setDurability(int val);    
    const uint& getSpeed() const;
};

// friend class boost::serialization::access;

//     template<class Archive>
//     void serialize(Archive& ar, const unsigned int version) {
//         ar & member;
//         ar & type;
//         ar & ID;
//         ar & x_position;
//         ar & y_position;
//         ar & durability;
//         ar & speed;
//         ar & instanceCounter;
//     }

#endif
