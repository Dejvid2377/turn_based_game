#ifndef UNITMODEL_HH
#define UNITMODEL_HH
#include "unit.hh"

//class inheriting from the Unit class representing combat units
//extends the values ​​of the unit class with fields assigned only to a combat unit
class UnitModel : public Unit {
private:
    uint cost;
    uint attackRange;
    uint buildTime;
    UnitModel() = default;
    UnitModel(char, UnitType, uint, uint, uint, int, uint, uint, uint, uint);
    static const UnitModel& initialValues(UnitType);
public:
    UnitModel(UnitType);
    const uint& getCost() const; 
    const uint& getAttackRange() const;
    const uint& getBuildTime() const;
    static uint checkCost(UnitType type);
    static uint checkTime(UnitType type);
    friend std::ostream& operator<<(std::ostream& os, const UnitModel& unitModel);

};

//prototype of a data serialization tool - the project was abandoned
    // friend class boost::serialization::access;

    // template<class Archive>
    // void serialize(Archive& ar, const unsigned int version) {
    //     ar & boost::serialization::base_object<Unit>(*this);
    //     ar & cost;
    //     ar & attackRange;
    //     ar & buildTime;
    // }

#endif
