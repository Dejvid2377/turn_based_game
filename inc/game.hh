#ifndef GAME_HH
#define GAME_HH

#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
using Cell = variant<int, shared_ptr<Unit>>;
using actionTuple = tuple<bool,int>;


class Game {
private:
  int turn_counter;
  int goldTab[2];
  int baseLocker[2];
  unordered_map<int, shared_ptr<Unit>> units;
  unordered_map<int,unordered_map<int,list<Cell>>> mapBattle;
  unordered_map<UnitType, unordered_map<UnitType, uint>> strengthTable;
  void addUnit(int id, const shared_ptr<Unit> & unit);
  void initializeTable();
public:
  Game(const string& filename, const string& filename2);

  void removeUnit(int id);
  shared_ptr<Unit> getUnit(int id);

  bool createObjectList(const string& filename);
  bool createBattField(const string& filename);
  void gameInitialize(const string& filename, const string& filename2);

  bool deleteObjectFromMap(uint x, uint y,const shared_ptr<Unit>& value);
  bool addObjectToMap(uint x, uint y, const shared_ptr<Unit>& value);

  void createStatus(const string & filename);
  void turnPreparation();
  void changeMember();
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
