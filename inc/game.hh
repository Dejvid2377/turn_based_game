#ifndef GAME_HH
#define GAME_HH

#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
using Cell = variant<int, shared_ptr<Unit>>;

class Game {
private:
  int turn_counter;
  unordered_map<int, shared_ptr<Unit>> units;
  unordered_map<int,unordered_map<int,list<Cell>>> mapBattle;
public:
  Game(const string& filename, const string& filename2);
  ~Game();
  void addUnit(int id, const shared_ptr<Unit> & unit);
  void removeUnit(int id);
  shared_ptr<Unit> getUnit(int id);

  bool createObjectList(const string& filename);
  bool createBattField(const std::string& filename);

  bool updateMap();
  bool updateBattField();

  void deleteObjectFromMap(uint x, uint y,const shared_ptr<Unit>& value);
  void addObjectToMap(uint x, uint y, const shared_ptr<Unit>& value);

  void displayMap();
  void displayObjectAt(uint x, uint y, uint index);
  void displayAllObjects();
};

bool deleteElementFromList(list<Cell>& lst,const shared_ptr<Unit>& value);
bool addElementToList(list<Cell>& lst, const shared_ptr<Unit>& value);

  // #include "serialization.hh" 
  // friend class boost::serialization::access;

  // template <class Archive>
  // void serialize(Archive& ar, const unsigned int version) {
  //   ar & units;
  //   ar & mapBattle;
  // }

#endif
