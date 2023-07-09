#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
#include "game.hh"

int main() {

    return 0;
}


// void speedTests() {
//     std::chrono::steady_clock::time_point start1, end1, start2, end2, start3, end3;
//     Game game(MAP_FILE,STATUS_FILE);
//     start1 = std::chrono::steady_clock::now();

//     int x = 0;
//     int y = 0;
//     end1 = std::chrono::steady_clock::now();
   
   
//     //auto ptr = game.getUnit(unit2->getID());
//     //game.deleteObjectFromMap(unit2->getX(),unit2->getY(),ptr);
//     game.displayMap();
//     game.displayAllObjects();
//     cout << "---------------------\n";
//     duration<double> duration1 = end1-start1;
//     cout << "Czas : " << duration1.count() << endl;
//     shared_ptr<UnitModel> unit = make_shared<UnitModel>(UnitType::Catapult);
//     game.addObjectToMap(x,y,unit);
//     game.createStatus("status.txt");
//     if (game.executeOrders("rozkazy.txt"))
//         cout << "works1\n";
    
//     shared_ptr<UnitModel> unit2 = make_shared<UnitModel>(UnitType::Knight);
//     game.addObjectToMap(x+5,y+4,unit2);
    
//     game.createStatus("status2.txt");
//     if (game.executeOrders("rozkazy1.txt"))
//         cout << "works2\n";

//     game.createStatus("status3.txt");
//     if (game.executeOrders("rozkazy2.txt"))
//         cout << "works3\n";
    
//     game.displayMap();
// }