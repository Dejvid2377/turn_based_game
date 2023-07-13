#ifndef GAME_HH
#define GAME_HH

#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
using Cell = variant<int, shared_ptr<Unit>>;
using actionTuple = tuple<bool,int>;

//class representing game instance
//main instance served by the mediator program
//player programs can create their own instances for simulation purposes
/**********************************************************************
* turn_counter - variable to store actual game turn                   *
* goldTab - array for store players gold value                        *
* baseLocker - array to monitor players base ability to build units   *
* units - map to store pointers for all units                         *
* mapBattle - instance to store 3D model of the game.                 *
*            - Cell is a type to store information about path kind or *
*              unit stayed on the path                                *
* strengthTable - 2D array for comparing units strength               *
***********************************************************************/
class Game {
private:
  int turn_counter;
  int goldTab[2];
  int baseLocker[2];
  unordered_map<int, shared_ptr<Unit>> units;
  unordered_map<int,unordered_map<int,list<Cell>>> mapBattle;
  unordered_map<UnitType, unordered_map<UnitType, uint>> strengthTable;
  void initializeTable();
  void gameInitialize(const string& filename, const string& filename2);
  void turnPreparation();
  void changeMember();
public:
  Game(const string& filename, const string& filename2);
  Game(const Game& other);
  void addUnit(int id, const shared_ptr<Unit> & unit);
  void removeUnit(int id);
  shared_ptr<Unit> getUnit(int id);
  bool createObjectList(const string& filename);
  bool createBattField(const string& filename);
  bool deleteObjectFromMap(uint x, uint y,const shared_ptr<Unit>& value);
  bool addObjectToMap(uint x, uint y, const shared_ptr<Unit>& value);
  void createStatus(const string & filename);
  uint getPower(UnitType u1, UnitType u2);
  bool checkWinCondition();
  bool executeOrders(const string & filename);
  bool checkMove(uint id, uint x, uint y, map<int,actionTuple> & actionMap);
  bool checkBuild(uint id, char ch);
  bool checkAttack(uint id, uint id2, map<int,actionTuple> & actionMap);
  list<Cell>::iterator findObjectByAddress(list<Cell>& objectList, const shared_ptr<Unit>& searchObject);
  void displayMap();
  list<Cell> * getPath(uint x, uint y);
  void displayAllObjects();
};

//helper functions not related to the class
bool deleteElementFromList(list<Cell>& lst,const shared_ptr<Unit>& value);
bool addElementToList(list<Cell>& lst, const shared_ptr<Unit>& value);
uint calculateDistance(uint x1, uint x2, uint y1, uint y2);
bool checkChar(UnitType type);

  // #include "serialization.hh" 
  // friend class boost::serialization::access;

  // template <class Archive>
  // void serialize(Archive& ar, const unsigned int version) {
  //   ar & units;
  //   ar & mapBattle;
  // }

#endif
