#ifndef GAME_HH
#define GAME_HH

#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"

class Game {
private:
  uint gold;
  uint baseID;
  unordered_map<int, shared_ptr<Unit>> units;
  vector<vector<list<int>>> mapBattle;

public:
  Game(const string& filename, const string& filename2);
  void addUnit(int id, shared_ptr<Unit> unit);
  void removeUnit(int id);
  bool createMap(const string& filename);
  bool updateMap(const string& filename);
  bool createBattField(const std::string& filename);
  bool updateBattField(const string& filename);
  void deleteObjectFromList(uint x, uint y, int value); //zmienic nazwy tych funkcji
  void addObjectToList(uint x, uint y, int value);

  shared_ptr<Unit> getUnit(int id);
  void displayMap();
  void fillMap();
  void displayObjectAt(uint x, uint y, uint index);
  const unordered_map<int, shared_ptr<Unit>>& getUnits();
  void printAllUnits() const;
  void displayAllObjects();
};

bool deleteElementFromList(list<int>& lst, int value);
bool addElementToList(list<int>& lst, int value);

  // #include "serialization.hh" 
  // friend class boost::serialization::access;

  // template <class Archive>
  // void serialize(Archive& ar, const unsigned int version) {
  //   ar & units;
  //   ar & mapBattle;
  // }

#endif
