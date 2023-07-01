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
  public:
    static UnitBase* getInstance();
    const UnitType& getProductUnit() const;
};


#endif