#ifndef UNITMODEL_HH
#define UNITMODEL_HH
#include "unit.hh"

class UnitModel : public Unit {
private:
    uint cost;
    uint attackRange;
    uint buildTime;
    UnitModel(char, UnitType, uint, uint, uint, int, uint, uint, uint, uint);
    static const UnitModel& initialValues(UnitType);
public:
    UnitModel(UnitType);
    const uint& getCost() const; 
    const uint& getAttackRange() const;
    const uint& getBuildTime() const;
};

#endif
