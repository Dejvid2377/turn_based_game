#ifndef UNITMODEL_HH
#define UNITMODEL_HH
#include "unit.hh"

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


    // friend class boost::serialization::access;

    // template<class Archive>
    // void serialize(Archive& ar, const unsigned int version) {
    //     ar & boost::serialization::base_object<Unit>(*this);
    //     ar & cost;
    //     ar & attackRange;
    //     ar & buildTime;
    // }

#endif
