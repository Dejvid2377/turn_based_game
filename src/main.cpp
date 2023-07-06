#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
#include "game.hh"

void takeSwitch(int val);
void speedTests();
void serializationTest();
void otherTests();
// void fillMap(std::vector<std::vector<std::list<CellValue>>>& mapa);
// void displayMapa(const std::vector<std::vector<std::list<CellValue>>>& mapa);
int main() {
    
    int x;
    cin >> x;
    takeSwitch(x);
    return 0;
}

//******************************************************************************************************
void takeSwitch(int val) {
    switch(val) {
        case 1:
            speedTests();
            break;
        case 2:
            serializationTest();
            break;
        case 3:
            otherTests();
            break;
        default:
            break;
    }
}


void serializationTest() {

}

void speedTests() {
    std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3;
    Game game(MAP_FILE,STATUS_FILE);
    game.displayMap();
    start1 = std::chrono::steady_clock::now();
    //while(1) {
        int x, y, index;
        //cin >> x >> y;
        x = 0;
        y = 0;
        shared_ptr<UnitModel> unit = make_shared<UnitModel>(UnitType::Knight);
        game.addObjectToMap(x,y,unit);
        game.displayMap();
        cout << endl;
        game.displayAllObjects();
        game.deleteObjectFromMap(x,y, unit);
        game.displayMap();
        cout << endl;
        game.displayAllObjects();

        if (unit == nullptr) 
            cout << "mnull\n";
    //}

    
    end1 = std::chrono::steady_clock::now();

    
    duration<double> duration1 = end1-start1;
    cout << "Czas : " << duration1.count() << endl;
   

}

void otherTests() {
    Game game(MAP_FILE,STATUS_FILE);

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
}

// void fillMap(std::vector<std::vector<std::list<CellValue>>>& mapa) {
//     for (int i = 0; i < 3; ++i) {
//         std::vector<std::list<CellValue>> vectorRow;
//         for (int j = 0; j < 3; ++j) {
//             CellValue value = i * j;
//             std::list<CellValue> list;
//             list.push_back(value);
//             vectorRow.push_back(list);
//         }
//         mapa.push_back(vectorRow);
//     }
// }

// void displayMapa(const std::vector<std::vector<std::list<CellValue>>>& mapa) {
//     for (const auto& vectorRow : mapa) {
//         for (const auto& list : vectorRow) {
//             for (const auto& value : list) {
//                 // Access the CellValue value and display it
//                 if (std::holds_alternative<int>(value)) {
//                     int intValue = std::get<int>(value);
//                     std::cout << intValue << " ";
//                 } else if (std::holds_alternative<Unit>(value)) {
//                     // Handle the Unit value display
//                     // Assuming Unit has a method to display its value, e.g., displayValue()
//                     const Unit& unitValue = std::get<Unit>(value);
//                     cout << "nic tam nie ma" << endl; 
//                 }
//             }
//         }
//         std::cout << std::endl;
//     }
// }
