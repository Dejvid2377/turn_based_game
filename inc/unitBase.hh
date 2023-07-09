#ifndef UNITBASE_HH
#define UNITBASE_HH
#include "unit.hh"

//class inheriting from the Unit class representing Base model
//extends the values ​​of the unit class with fields assigned only to a Base unit
//inspired by the design pattern "Singleton" but modified : allows you to create only TWO instances
/***********************************************************************
* base1, base2 - pointers to one of two allowed instances of Base model*
* identifier - helps to distinguish instances                          *
***********************************************************************/
class UnitBase : public Unit {
  private:
    static UnitBase* base1;
    static UnitBase* base2;
    UnitType productUnit;
    static int identifier;

    UnitBase(char,UnitType,uint,uint,uint,int,uint,UnitType);
    UnitBase();
    static const UnitBase& initialValues();

  public:
    static UnitBase* getInstance();
    const UnitType& getProductUnit() const;
    void setProductUnit(UnitType unit);
};

//prototype of a data serialization tool - the project was abandoned
    // friend class boost::serialization::access;

    // template<class Archive>
    // void serialize(Archive& ar, const unsigned int version) {
    //     ar & boost::serialization::base_object<Unit>(*this);
    //     ar & productUnit;
    //     ar & identifier;
    //     ar & base1;
    //     ar & base2;
    // }

#endif