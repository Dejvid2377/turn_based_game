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

//******************************************************************************************************
std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3;
Game game2;
int iter = 100;
    // Pomiar czasu dla pierwszej pętli for
    start1 = std::chrono::steady_clock::now();
    std::shared_ptr<UnitModel> unitModel22 = std::make_shared<UnitModel>(UnitType::Knight);
    end1 = std::chrono::steady_clock::now();

    start3 = std::chrono::steady_clock::now();

    std::unordered_map<int, std::string> mapa2;
        
    for (int i = 0; i < iter; ++i) {
        game2.addUnit(i, unitModel22);
    }

    end3 = std::chrono::steady_clock::now();
    
    // Pomiar czasu dla drugiej pętli for
    start2 = std::chrono::steady_clock::now();

    auto myMap = game2.getUnits();

    for (int j = 0; j < iter; ++j) {
        mapa2[j] = "i";
        mapa2[j] = "asd";
        mapa2[j] = "iasd";
    }

    for (const auto& element : mapa2) {
    int klucz = element.first;
    
    // Sprawdzenie czy klucz istnieje w myMap
    if (myMap.count(klucz) > 0) {
        // Klucz istnieje w myMap
        // Można tu umieścić odpowiednie działania lub kod
        // np. wykonanie pewnych operacji na wartości przypisanej do klucza
    }
}

    end2 = std::chrono::steady_clock::now();

    // Obliczenie czasów trwania dla obu pętli
    duration<double> duration1 = end1-start1;
    duration<double> duration2 = end2-start2;
    duration<double> duration3 = end3-start3;
    duration1 *= iter;
    duration1 += duration3;

    // Porównanie czasów i wyświetlenie informacji
    if (duration1 < duration2) {
        auto time = duration2.count() / duration1.count();
        std::cout << "Pierwsza pętla była szybsza "<< time << " razy.\n";
    } else if (duration1 > duration2) {
        auto time = duration1.count() / duration2.count();
        std::cout << "Druga pętla była szybsza "<< time << " razy.\n";
    } else {
        std::cout << "Obie pętle trwały tyle samo czasu.\n";
    }

    return 0;
}
