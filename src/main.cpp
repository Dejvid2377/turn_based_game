#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
#include "game.hh"

int main() {
    Game game;

    std::shared_ptr<UnitModel> unitModel = std::make_shared<UnitModel>(UnitType::Knight);
    game.addUnit(unitModel->getID(), unitModel);
    std::shared_ptr<UnitBase> unitBase(UnitBase::getInstance());
    game.addUnit(unitBase->getID(), unitBase);


    if (unitModel != nullptr) {
        std::cout << "nie jest\n";
        std::cout << "licznik po stworzeniu 2 obiektów: " << unitModel->getCounter() << std::endl;
    }

    std::shared_ptr<Unit> retrievedUnit = game.getUnit(0);

    if (retrievedUnit != nullptr) {
        std::cout << "Retrieved Unit:\n";

        std::shared_ptr<UnitModel> unitModelPtr = std::dynamic_pointer_cast<UnitModel>(retrievedUnit);
        if (unitModelPtr != nullptr) {
            std::cout << "licznik po stworzeniu nowego obiektu ktory pokazuje na 0 element mapy: " << unitModelPtr->getCounter() << std::endl;
            // You can access the UnitModel-specific functions and members using unitModelPtr
            std::cout << "Cost of the retrieved UnitModel: " << unitModelPtr->getCost() << std::endl;
        } else {
            std::cout << "Dynamic cast failed. Retrieved unit is not an instance of UnitModel.\n";
        }
    }

{
    std::ofstream file("data.txt");
    boost::archive::text_oarchive oa(file);
    oa << game;
}
    std::ifstream file("data.txt");
    boost::archive::text_iarchive ia(file);
    Game restoredDerived;
    ia >> restoredDerived;
    shared_ptr<Unit> ptr = restoredDerived.getUnit(0);
    shared_ptr<UnitModel> unitptr = dynamic_pointer_cast<UnitModel>(ptr);
    cout << *(unitptr) << endl;


    shared_ptr<Unit> ptr2 = restoredDerived.getUnit(1);
    shared_ptr<UnitBase> baseptr = dynamic_pointer_cast<UnitBase>(ptr2);
    UnitType unit = baseptr->getProductUnit();
    cout << static_cast<char>(unit) << endl;
    cout << static_cast<char>(baseptr->getType()) << endl;

    return 0;
}
