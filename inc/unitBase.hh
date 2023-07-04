#ifndef UNITBASE_HH
#define UNITBASE_HH
#include "unit.hh"

class UnitBase : public Unit {
  private:
    static UnitBase* base1;
    static UnitBase* base2;
    UnitType productUnit;
    static int identifier;

    UnitBase(char,UnitType,uint,uint,uint,int,uint,UnitType);
    UnitBase();
    static const UnitBase& initialValues();

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & boost::serialization::base_object<Unit>(*this);
        ar & productUnit;
        ar & identifier;
        ar & base1;
        ar & base2;
    }
  public:
    static UnitBase* getInstance();
    const UnitType& getProductUnit() const;
    void setProductUnit(UnitType unit);
};

#endif