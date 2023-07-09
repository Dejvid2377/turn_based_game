#include "../inc/unitBase.hh"

int UnitBase::identifier = 0;
UnitBase* UnitBase::base1 = nullptr;
UnitBase* UnitBase::base2 = nullptr;

//the only possible constructor that imposes values ​​depending on the entity type
UnitBase::UnitBase()
  :   Unit(initialValues().getMember(),
           initialValues().getType(),
           initialValues().getID(),
           initialValues().getX(),
           initialValues().getY(),
           initialValues().getDurability(),
           initialValues().getSpeed()),
  productUnit(initialValues().getProductUnit())
  {
    this->setID(Unit::getCounter());
    Unit::increaseCounter();
  }

//parametric constructor to help create the main constructor, not available to the public
UnitBase::UnitBase
    (char v1, UnitType v2, uint v3, uint v4, uint v5, int v6, uint v7, UnitType v8)
    :Unit(v1,v2,v3,v4,v5,v6,v7),
     productUnit(v8)
    {}


//a function that creates model (exemplary) objects for Base type unit 
const UnitBase& UnitBase::initialValues() {
  static UnitBase base('0',UnitType::Base, 0, 0, 0, 200, 0,UnitType::NoUnit);
  return base;
}

//function that provides an accessible instance of a class
//only option to create class instance from user pointview
UnitBase* UnitBase::getInstance() {
  if (identifier == 0) {
    if (base1 == nullptr) {
      base1 = new UnitBase();
      identifier++;
      return base1;
    }
  } else if (identifier == 1) {
      if (base2 == nullptr) {
        base2 = new UnitBase();
        identifier++;
        return base2;
      }
    }

  return nullptr;   
  }

const UnitType& UnitBase::getProductUnit() const { return productUnit; }
void UnitBase::setProductUnit(UnitType unit) { productUnit = unit; }