  #include "../inc/game.hh"

  //BOOST_CLASS_EXPORT_GUID(UnitBase, "unitBase")
  //BOOST_CLASS_EXPORT_GUID(UnitModel, "unitModel")

  Game::Game(const string& filename, const string& filename2)
  {
    this->createMap(filename2);
    this->createBattField(filename);
  }
  
  void Game::addUnit(int id, shared_ptr<Unit> unit) {
     auto result = units.insert({id,unit}); 
     if (result.second)
       cout << "add" << endl; 

     }
  void Game::removeUnit(int id) { units.erase(id); }

  shared_ptr<Unit> Game::getUnit(int id)
  {
    auto it = units.find(id);
      if (it != units.end())
          return it->second;
      return nullptr;
  }

  bool Game::createMap(const string& filename)
  {
    ifstream file(filename, ios::in);
    if (!file)
      return false;

    string line;
    string firstLine;
    string value;

    if (getline(file, firstLine))
      gold = std::stoi(firstLine);

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

        if (unitBase->getMember() == 'P')
          baseID = tempID;

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
    ifstream file(filename);
    if (file.is_open()) {
        char character;
        vector<list<int>> vectorRow;
        list<int> list;

        while (file.get(character)) {
            if (character != '\n') {
                int value = character - '0' + 2000;
                list.push_back(value);
                vectorRow.push_back(list);
                list.clear();
            } else {
                mapBattle.push_back(vectorRow);
                vectorRow.clear();
            }
        }
        if (!list.empty()) {
            vectorRow.push_back(list);
        }
        if (!vectorRow.empty()) {
            mapBattle.push_back(vectorRow);
        }

        file.close();
        std::cout << "End of file reached." << std::endl;

        for (const auto & unit : units ) {
          auto model = unit.second;
          this->addObjectToList(model->getX(),model->getY(),model->getID());
          cout << model->getX() <<" "<<model->getY() << " " << model->getID() << endl;
        }

        cout << mapBattle.size() << " " << mapBattle[0].size() << endl;
    } else {
        std::cout << "Unable to open file for reading." << std::endl;
        return false;
    }
    return true;
}

  void Game::deleteObjectFromList(uint x, uint y, int value) 
  {
      if (y >= 0 && y < mapBattle.size() && x >= 0 && x < mapBattle[y].size()) {
          list<int>& objectList = mapBattle[y][x];
          if (deleteElementFromList(objectList, value))
            cout << "Object with value " << value << " deleted from position (" << x << ", " << y << ")" << std::endl;
          else
            cout << "object from position (" << x << ", " << y << ")" << " doesnt exist " << endl;
      } else {
          cout << "Invalid coordinates!" << endl;
      }
  }
  
  void Game::addObjectToList(uint x, uint y, int value)
  {
    if (y >= 0 && y < mapBattle.size() && x >= 0 && x < mapBattle[y].size()) {
        std::list<int>& objectList = mapBattle[y][x];
        if (addElementToList(objectList, value))
            std::cout << "Object with value " << value << " added to position (" << x << ", " << y << ")" << std::endl;
    } else {
        std::cout << "Invalid coordinates!" << std::endl;
    }
  }

  bool deleteElementFromList(std::list<int>& lst, int value) 
{
    auto it = find(lst.begin(), lst.end(), value);
    if (it != lst.end()) {
        lst.erase(it);
        return true;
    }

    return false;
}

  bool addElementToList(list<int>& lst, int value) 
{
    auto it = find(lst.begin(), lst.end(), value);
    if (it == lst.end()) {
        lst.push_back(value);
        return true;
    }

    return false;
}

/**********************************************************************************/
  void Game::fillMap() {
      for (int i = 0; i < 3; ++i) {
          std::vector<std::list<int>> vectorRow;
          for (int j = 0; j < 3; ++j) {
              int value = i + j + 2;
              std::list<int> list;
              list.push_back(value);
              vectorRow.push_back(list);
          }
          mapBattle.push_back(vectorRow);
      }
  }

  void Game::displayMap() {
      for (const auto& vectorRow : mapBattle) {
          for (const auto& list : vectorRow) {
              for (const auto& value : list) {
                  int value1 = value;
                  cout << value1 << " " ;
              }
          }
          std::cout << std::endl;
      }
  }

  void Game::displayObjectAt(uint x, uint y, uint index) {
      if (x >= 0 && x < mapBattle.size() && y >= 0 && y < mapBattle[x].size()) {
          const list<int>& objectList = mapBattle[x][y];
          if (index >= 0 && index < objectList.size()) {
              auto it = objectList.begin();
              std::advance(it, index);
              int selectedObject = *it;
              std::cout << "Object at position (" << x << ", " << y << ") with index " << index << ": " << selectedObject << std::endl;
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
