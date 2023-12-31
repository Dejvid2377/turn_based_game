#include "../inc/unitModel.hh"

//the only possible constructor that imposes values ​​depending on the entity type
UnitModel::UnitModel(UnitType type)
    : Unit(initialValues(type).getMember(),
           type,
           initialValues(type).getID(),
           initialValues(type).getX(),
           initialValues(type).getY(),
           initialValues(type).getDurability(),
           initialValues(type).getSpeed()),
      cost(initialValues(type).getCost()),
      attackRange(initialValues(type).getAttackRange()),
      buildTime(initialValues(type).getBuildTime())
{
    this->setID(Unit::getCounter());
    Unit::increaseCounter();
}

//parametric constructor to help create the main constructor, not available to the public
UnitModel::UnitModel
    (char v1, UnitType v2, uint v3, uint v4, uint v5, int v6, uint v7, uint v8, uint v9, uint v10)
    : Unit(v1, v2, v3, v4, v5, v6, v7),
      cost(v8),
      attackRange(v9),
      buildTime(v10)
{}

//a function that creates model (exemplary) objects for military units 
//created instance once, next objects get only variables values
const UnitModel& UnitModel::initialValues(UnitType type) {
    static const UnitModel knight('0',UnitType::Knight, 0, 0, 0, 70, 5, 400, 1, 5);
    static const UnitModel swordsman('0', UnitType::Swordsman, 0, 0, 0, 60, 2, 250, 1, 3);
    static const UnitModel archer('0', UnitType::Archer, 0, 0, 0, 40, 10, 250, 5, 3);
    static const UnitModel pikeman('0', UnitType::Pikeman, 0, 0, 0, 50, 2, 200, 2, 3);
    static const UnitModel ram('0', UnitType::Ram, 0, 0, 0, 90, 2, 500, 1, 4);
    static const UnitModel catapult('0', UnitType::Catapult, 0, 0, 0, 50, 2, 800, 7, 6);
    static const UnitModel worker('0', UnitType::Worker, 0, 0, 0, 20, 2, 100, 1, 2);

    switch (type) {
        case UnitType::Knight:
            return knight;
        case UnitType::Archer:
            return archer;
        case UnitType::Swordsman:
            return swordsman;
        case UnitType::Pikeman:
            return pikeman;
        case UnitType::Ram:
            return ram;
        case UnitType::Catapult:
            return catapult;
        case UnitType::Worker:
            return worker;
        default:
            throw runtime_error("Unknown unit type");
    }
}

std::ostream& operator<<(std::ostream& os, const UnitModel& UnitModel) {
    os << "Member: " << UnitModel.getMember() << "\n"
       << "Type: " << static_cast<char>(UnitModel.getType()) << "\n"
       << "ID: " << UnitModel.getID() << "\n"
       << "X: " << UnitModel.getX() << "\n"
       << "Y: " << UnitModel.getY() << "\n"
       << "Durability: " << UnitModel.getDurability() << "\n"
       << "Speed: " << UnitModel.getSpeed() << "\n"
       << "Cost: " << UnitModel.getCost() << "\n"
       << "Attack Range: " << UnitModel.getAttackRange() << "\n"
       << "Build Time: " << UnitModel.getBuildTime();
    return os;
}

const uint& UnitModel::getCost() const { return cost; }
const uint& UnitModel::getAttackRange() const { return attackRange; }
const uint& UnitModel::getBuildTime() const { return buildTime; }

uint UnitModel::checkCost(UnitType type)
{
    return initialValues(type).getCost();
}

uint UnitModel::checkTime(UnitType type)
{
    return initialValues(type).getBuildTime();
}