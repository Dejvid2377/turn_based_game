#include "../inc/game.hh"
//BOOST_CLASS_EXPORT_GUID(UnitBase, "unitBase")
//BOOST_CLASS_EXPORT_GUID(UnitModel, "unitModel")

Game::Game(const string& filename, const string& filename2)
{
  this->createObjectList(filename2);
  this->createBattField(filename);
}

Game::~Game()
{
  //for (auto& pair : units) {
  //    pair.second.reset();
  //}
  //units.clear();
}
  
void Game::addUnit(int id, const shared_ptr<Unit> & unit)
{
   auto result = units.insert({id,unit}); 
   if (result.second)
     cout << "add" << endl; 
}
  
void Game::removeUnit(int id) 
{   
    units[id].reset();
    units.erase(id); 
}

shared_ptr<Unit> Game::getUnit(int id)
{
  auto it = units.find(id);
    if (it != units.end())
        return it->second;
    return nullptr;
}

bool Game::createObjectList(const string& filename)
{
    ifstream file(filename, ios::in);
    if (!file)
      return false;

    string line;
    string firstLine;
    string value;

    getline(file, firstLine);
    
    while (getline(file, line)) {
      char tempMember;
      char tempType;
      int tempDur;
      uint tempX, tempY, tempID;
      
      istringstream iss(line);
      iss >> tempMember >> tempType;
      iss >> tempID >> tempX >> tempY >> tempDur;

      UnitType unitType = static_cast<UnitType>(tempType);

      if (unitType == UnitType::Base) {
        char tempBuild;
        iss >> tempBuild;
        unitType = static_cast<UnitType>(tempBuild);

        shared_ptr<UnitBase> unitBase(UnitBase::getInstance());
        unitBase->setMember(tempMember);
        unitBase->setID(tempID);
        unitBase->setXY(tempX,tempY);
        unitBase->setDurability(tempDur);
        unitBase->setProductUnit(unitType);

        this->addUnit(tempID,unitBase);

      } else {
          shared_ptr<UnitModel> unitModel = make_shared<UnitModel>(unitType);
          unitModel->setMember(tempMember);
          unitModel->setID(tempID);
          unitModel->setXY(tempX,tempY);
          unitModel->setDurability(tempDur);    

          this->addUnit(tempID,unitModel);    
      }
    }

    file.close();
    return true;
}

bool Game::createBattField(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        char character;

        int y = 0;
        int x = 0;

        while (file.get(character)) {
            if (character != '\n') {
                int symbol = character - '0';
                mapBattle[y][x].push_back(symbol);
                ++x;
            } else {
                ++y;
                x = 0;
            }
        }

        file.close();
        std::cout << "End of file reached." << std::endl;

        for (const auto& unit : units) {
            auto model = unit.second;
            this->addObjectToMap(model->getX(), model->getY(), model);
            std::cout << model->getX() << " " << model->getY() << " " << model->getID() << std::endl;
        }

        std::cout << mapBattle.size() << " " << mapBattle[0].size() << std::endl;

    } else {
        std::cout << "Unable to open file for reading." << std::endl;
        return false;
    }
    return true;
}



void Game::deleteObjectFromMap(uint x, uint y, const shared_ptr<Unit>& value) {
    if (y >= 0 && y < mapBattle.size()) {
        auto it = mapBattle.find(y);
        if (it != mapBattle.end() && x >= 0 && x < it->second.size()) {
            std::list<Cell>& objectList = it->second[x];
            if (deleteElementFromList(objectList, value)) {
                removeUnit(value->getID());
                std::cout << "Object deleted from position (" << x << ", " << y << ")" << std::endl;
            }
            else
                std::cout << "Object does not exist at position (" << x << ", " << y << ")" << std::endl;
        }
    } else {
        std::cout << "Invalid coordinates!" << std::endl;
    }
}

  
void Game::addObjectToMap(uint x, uint y, const shared_ptr<Unit>& value) {
    cout << "y: " << y << "map.size(): " << mapBattle.size() << endl;
    if (y >= 0 && y < mapBattle.size()) {
        auto it = mapBattle.find(y);
        if (it != mapBattle.end() && x >= 0 && x < it->second.size()) {
            cout << "x: " << x << "second.size(): " << it->second.size() << endl; 
            std::list<Cell>& objectList = it->second[x];
            if (addElementToList(objectList, value)) {
                addUnit(value->getID(),value);
                std::cout << "Object added to position (" << x << ", " << y << ")" << std::endl;
            }
        }
    } else {
        std::cout << "Invalid coordinates!" << std::endl;
    }
}


bool deleteElementFromList(std::list<Cell>& lst, const shared_ptr<Unit>& value) {
    auto it = std::find_if(lst.begin(), lst.end(), [&](const Cell& cell) {
        return std::holds_alternative<std::shared_ptr<Unit>>(cell) && std::get<std::shared_ptr<Unit>>(cell) == value;
    });

    if (it != lst.end()) {
        lst.erase(it);
        return true;
    }

    return false;
}

bool addElementToList(std::list<Cell>& lst,const shared_ptr<Unit>& value) {
    auto it = std::find_if(lst.begin(), lst.end(), [&](const Cell& cell) {
        return std::holds_alternative<std::shared_ptr<Unit>>(cell) && std::get<std::shared_ptr<Unit>>(cell) == value;
    });

    if (it == lst.end()) {
        lst.push_back(value);
        return true;
    }

    return false;
}


//**********************************************************************************

void Game::displayMap() {
    for (uint i = 0; i < mapBattle.size(); ++i) {
        for (uint j = 0; j < mapBattle[i].size(); ++j) {
            const std::list<Cell>& cellList = mapBattle[i][j];
            for (const auto& cell : cellList) {
                if (std::holds_alternative<int>(cell)) {
                    int value = std::get<int>(cell);
                    std::cout << value << " ";
                } else if (std::holds_alternative<std::shared_ptr<Unit>>(cell)) {
                    std::shared_ptr<Unit> unit = std::get<std::shared_ptr<Unit>>(cell);
                    int id = unit->getID();
                    std::cout << id << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}




void Game::displayObjectAt(uint x, uint y, uint index) {
    if (x >= 0 && x < mapBattle.size() && y >= 0 && y < mapBattle[x].size()) {
        const std::list<Cell>& objectList = mapBattle[y][x];
        if (index >= 0 && index < objectList.size()) {
            auto it = objectList.begin();
            std::advance(it, index);
            const Cell& selectedCell = *it;
            if (std::holds_alternative<int>(selectedCell)) {
                int selectedObject = std::get<int>(selectedCell);
                std::cout << "Object at position (" << x << ", " << y << ") with index " << index << ": " << selectedObject << std::endl;
            } else if (std::holds_alternative<std::shared_ptr<Unit>>(selectedCell)) {
                std::shared_ptr<Unit> selectedUnit = std::get<std::shared_ptr<Unit>>(selectedCell);
                int durability = selectedUnit->getID();
                std::cout << "Object at position (" << x << ", " << y << ") with index " << index << ": ID = " << durability << std::endl;
            }
        } else {
            std::cout << "Invalid object index at position (" << x << ", " << y << ")" << std::endl;
        }
    } else {
        std::cout << "Invalid coordinates!" << std::endl;
    }
}


  void Game::displayAllObjects() {
    for (const auto& pair : units) {
        cout << pair.first << " ";
        cout << pair.second->getDurability();
        cout << " ";
        cout << endl;

    }
    }
