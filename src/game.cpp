#include "../inc/game.hh"
//BOOST_CLASS_EXPORT_GUID(UnitBase, "unitBase")
//BOOST_CLASS_EXPORT_GUID(UnitModel, "unitModel")

//class constructor with setting initial game variables values  
Game::Game(const string& filename, const string& filename2)
{
    goldTab[0] = 2000;
    goldTab[1] = 2000;
    baseLocker[0] = 0;
    baseLocker[1] = 0;
    turn_counter = 0;
    gameInitialize(filename, filename2);
    initializeTable();
}

//function adding unit to units list
void Game::addUnit(int id, const shared_ptr<Unit> & unit)
{
   units.insert({id,unit}); 
}
//function removing unit from units list
void Game::removeUnit(int id) 
{   
    units[id].reset();
    units.erase(id); 
}

//function for getting access to chosen object (access by ID)
shared_ptr<Unit> Game::getUnit(int id)
{
  auto it = units.find(id);
    if (it != units.end())
        return it->second;
    return nullptr;
}

//function for game initialization, changing data inside files to data inside game instance
void Game::gameInitialize(const string& filename, const string& filename2)
{
    if(!createObjectList(filename2)) {
        if(createBattField(filename)) {
            shared_ptr<UnitBase> base1(UnitBase::getInstance());
            base1->setMember('E');
            base1->setXY(0,0);
            this->addUnit(base1->getID(),base1);
            this->addObjectToMap(base1->getX(), base1->getY(), base1);

            shared_ptr<UnitBase> base2(UnitBase::getInstance());
            base2->setMember('P');
            base2->setXY(mapBattle[0].size()-1,mapBattle.size()-1);
            this->addUnit(base2->getID(),base2);
            this->addObjectToMap(base2->getX(), base2->getY(), base2);
        }
    } else
        createBattField(filename);
}

//function creating units list basing on status.txt file
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

//function creating 3D game map basing on file mapa.txt and units list created by Game::createObjectList
bool Game::createBattField(const string& filename) {
    ifstream file(filename);
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

        for (const auto& unit : units) {
            auto model = unit.second;
            if(!this->addObjectToMap(model->getX(), model->getY(), model))
                return false;
        }


    } else
        return false;
    
    return true;
}

//function for deleting object from 3D map and units list
bool Game::deleteObjectFromMap(uint x, uint y, const shared_ptr<Unit>& value) {
    if (y >= 0 && y < mapBattle.size()) {
        auto it = mapBattle.find(y);
        if (it != mapBattle.end() && x >= 0 && x < it->second.size()) {
            list<Cell>& objectList = it->second[x];
            if (deleteElementFromList(objectList, value))
                removeUnit(value->getID());
            else
                return false;
        }
    } else
        return false;
    return true;
}

//function for adding unit to chosen map path and to units list
bool Game::addObjectToMap(uint x, uint y, const shared_ptr<Unit>& value) {
    if (y >= 0 && y < mapBattle.size()) {
        auto it = mapBattle.find(y);
        if (it != mapBattle.end() && x >= 0 && x < it->second.size()) {
            list<Cell>& objectList = it->second[x];
            if (addElementToList(objectList, value)) {
                addUnit(value->getID(),value);
                value->setXY(x,y);
            }
        }
    } else 
        return false;
    
    return true;
}

//helper function, return information about object presence on chosen list
bool deleteElementFromList(list<Cell>& lst, const shared_ptr<Unit>& value) {
    auto it = find_if(lst.begin(), lst.end(), [&](const Cell& cell) {
        if (holds_alternative<shared_ptr<Unit>>(cell)) {
            const auto& sharedUnit = get<shared_ptr<Unit>>(cell);
            return sharedUnit.get() == value.get();
        }
        return false;
    });

    if (it != lst.end()) {
        lst.erase(it);
        return true;
    }

    return false;
}

//helper function, return information about object presence on chosen list
bool addElementToList(list<Cell>& lst,const shared_ptr<Unit>& value) {
    auto it = find_if(lst.begin(), lst.end(), [&](const Cell& cell) {
        return holds_alternative<shared_ptr<Unit>>(cell) && get<shared_ptr<Unit>>(cell) == value;
    });

    if (it == lst.end()) {
        lst.push_back(value);
        return true;
    }

    return false;
}

//function for creating status.txt file basing on current turn and game status
void Game::createStatus(const string & filename)
{
    cout << "tura: " << turn_counter << endl;
    Game::turnPreparation();

    ofstream file(filename);

    if(file.is_open())
    {   
        file << goldTab[(turn_counter-1)%2] << endl;

        for (const auto& unit : units) {
            
            auto model = unit.second;
            file << model->getMember() << " ";
            file << static_cast<char>(model->getType()) << " ";
            file << model->getID() << " ";
            file << model->getX() << " ";
            file << model->getY() << " ";
            file << model->getDurability() << " ";

            if (model->getType() == UnitType::Base)
            {
                auto baseModel = dynamic_pointer_cast<UnitBase>(model);
                file << static_cast<char>(baseModel->getProductUnit());
            }
            
            file << endl;
        }
    }
    else
        file.close();
    
    file.close();
}

//function for changing members type 
//giving each player the correct information which units belong to him ('P' member)
void Game::changeMember()
{
    for (const auto& unit : units) {
        auto model = unit.second;
        if (model->getMember() == 'P')
            model->setMember('E');
        else
            model->setMember('P');
    }
}

//function intializing units strength values
void Game::initializeTable()
{
    strengthTable[UnitType::Knight] =
    {
        {UnitType::Knight,35},
        {UnitType::Swordsman,35},
        {UnitType::Archer,35},
        {UnitType::Pikeman,35},
        {UnitType::Catapult,35},
        {UnitType::Ram,50},
        {UnitType::Worker,35},
        {UnitType::Base,35}
    };

    strengthTable[UnitType::Swordsman] =
    {
        {UnitType::Knight,30},
        {UnitType::Swordsman,30},
        {UnitType::Archer,30},
        {UnitType::Pikeman,20},
        {UnitType::Catapult,20},
        {UnitType::Ram,30},
        {UnitType::Worker,30},
        {UnitType::Base,30}
    };

    strengthTable[UnitType::Archer] =
    {
        {UnitType::Knight,15},
        {UnitType::Swordsman,15},
        {UnitType::Archer,15},
        {UnitType::Pikeman,15},
        {UnitType::Catapult,10},
        {UnitType::Ram,10},
        {UnitType::Worker,15},
        {UnitType::Base,15}
    };

    strengthTable[UnitType::Pikeman] =
    {
        {UnitType::Knight,35},
        {UnitType::Swordsman,15},
        {UnitType::Archer,15},
        {UnitType::Pikeman,15},
        {UnitType::Catapult,15},
        {UnitType::Ram,10},
        {UnitType::Worker,15},
        {UnitType::Base,10}
    };

    strengthTable[UnitType::Catapult] =
    {
        {UnitType::Knight,40},
        {UnitType::Swordsman,40},
        {UnitType::Archer,40},
        {UnitType::Pikeman,40},
        {UnitType::Catapult,40},
        {UnitType::Ram,40},
        {UnitType::Worker,40},
        {UnitType::Base,50}
    };

    strengthTable[UnitType::Ram] =
    {
        {UnitType::Knight,10},
        {UnitType::Swordsman,10},
        {UnitType::Archer,10},
        {UnitType::Pikeman,10},
        {UnitType::Catapult,10},
        {UnitType::Ram,10},
        {UnitType::Worker,10},
        {UnitType::Base,50}
    };

    strengthTable[UnitType::Worker] =
    {
        {UnitType::Knight,5},
        {UnitType::Swordsman,5},
        {UnitType::Archer,5},
        {UnitType::Pikeman,5},
        {UnitType::Catapult,5},
        {UnitType::Ram,5},
        {UnitType::Worker,5},
        {UnitType::Base,1}
    };
}

//ensuring that the necessary changes are made before the start of each subsequent turn
void Game::turnPreparation()
{
//this fragment changing game state
    Game::changeMember();
    turn_counter++;
    if (baseLocker[0] != 0)
        baseLocker[0] -= 1;
    if (baseLocker[1] != 0)
        baseLocker[1] -= 1;

//this fragment creating new units if current base passes cooltime
    for (uint i=0; i<2; ++i) {
        if (baseLocker[i]==0) {
            auto unit = dynamic_pointer_cast<UnitBase>(Game::getUnit(i));
            UnitType type = unit->getProductUnit();
            if (type != UnitType::NoUnit) {
                shared_ptr<UnitModel> unitModel = make_shared<UnitModel>(type);
                Game::addObjectToMap(unit->getX(),unit->getY(),unitModel);
                unit->setProductUnit(UnitType::NoUnit);
            }
        }
    }
//function changing gold value basing on workers units in gold mines
    for (const auto& row : mapBattle) {
        for (const auto& col : row.second) {
            const list<Cell>& cellList = col.second;
            for (const Cell& cell : cellList) {
                if (holds_alternative<int>(cell) && get<int>(cell) != 6)
                    break;  
                if (holds_alternative<shared_ptr<Unit>>(cell)) {
                    const shared_ptr<Unit>& unit = get<shared_ptr<Unit>>(cell);
                    if (unit->getType() == UnitType::Worker) {
                        if (unit->getMember() == 'P') {
                            goldTab[(turn_counter-1)%2] += 50;
                        } else {
                            goldTab[turn_counter%2] += 50;
                        }
                    }
                }
            }
        }
    }

}

//function for getting unit power after compared to units
uint Game::getPower(UnitType u1, UnitType u2)
{
    return strengthTable[u1][u2];
}

//function checking if win conditions occurs
bool Game::checkWinCondition()
{
    if (getUnit(0)->getDurability() <= 0) {
        cout << "Player no.1 win by destroy oponent base!\n";
        return true;
    }

    if (getUnit(1)->getDurability() <= 0) {
        cout << "Player no.2 win by destroy oponent base!\n";
        return true;
    }

    if (turn_counter >= MAX_TURNS) {
        int player1 = 0;
        int player2 = 0;

        for (const auto& unit : units) {
            auto model = unit.second;

            if (model->getMember() == 'P')
                ++player2;
            else
                ++player1;
        }

        if (player2 > player1)
            cout << "Player no.2 win by dominating battelfield in units amount !\n";
        else if (player2 < player1)
            cout << "Player no.1 win by dominating battelfield in units amount !\n";
        else
            cout << "Unbelievable, it's a tie!\n";

        return true;
    }

    return false;
}

//function to execute orders from rozkazy.txt file
bool Game::executeOrders(const string & filename)
{
    if (checkWinCondition()) {
            exit(0);
    }
    
    ifstream file(filename, ios::in);
    if (!file) 
        return false;

    string line;
    map<int,actionTuple> unitsAction;

    while (getline(file, line)) {
        istringstream iss(line);
        int id;
        char order;
        iss >> id >> order;

        auto unit = getUnit(id);

        if (unit != nullptr) {
            if (unit->getMember() == 'E')
                return false;
        }

        if (order == 'M') {
            uint x,y;
            iss >> x >> y;
            if (!checkMove(id,x,y,unitsAction))
                return false;
        }
        if (order == 'A') {
            uint id2;
            iss >> id2;
            if(!checkAttack(id,id2,unitsAction))
                return false;
        }
        if (order == 'B') {
            char type;
            iss >> type;
            if(!checkBuild(id,type))
                return false;
        }

        if (checkWinCondition()) {
            exit(0);
        }
    }

    return true;
}

//function checking if move is possible and performs it
//return true if it is, false if not
//function uses map with tumple identificator:
// get<0> informs about attack possibility in actual turn
// get<1> informs about how much move points unit have in actual turn 
bool Game::checkMove(uint id, uint x, uint y, map<int,actionTuple> & actionMap)
{
    auto unit = dynamic_pointer_cast<UnitModel>(Game::getUnit(id));
    if (unit == nullptr)
        return false;

    int distance = calculateDistance(unit->getX(),x,unit->getY(),y);
    cout << "distance : "<< distance << "\n";
    if (actionMap.count(id) == 0)
        actionMap[id] = make_tuple(true, unit->getSpeed());

    int moveLeft = get<1>(actionMap[id]) - distance;

    if (moveLeft < 0)
        return false; 

    actionMap[id] = make_tuple(get<0>(actionMap[id]),moveLeft);
    auto pathObjects = Game::getPath(x,y);

    if (pathObjects == nullptr)
        return false;
    
    for (const auto& object : *pathObjects) {
        if (holds_alternative<int>(object)) {
            int value = get<int>(object);
            if (value == 9)
                return false;
        } else if (holds_alternative<shared_ptr<Unit>>(object)) {
            shared_ptr<Unit> unitOnPath = get<shared_ptr<Unit>>(object);
            if (unitOnPath->getMember() == 'E')
                return false;    
        }

    }
    auto currentPath = Game::getPath(unit->getX(),unit->getY());

    auto iterator = Game::findObjectByAddress(*currentPath,unit);
    
    if(iterator == currentPath->end())
        return false;

    pathObjects->splice(pathObjects->end(), *currentPath, iterator);
    unit->setXY(x,y);

    return true;
}

//function checking if base could accept the order to build unit
//return true if it is, false if not
bool Game::checkBuild(uint id, char ch)
{
    int index = (turn_counter-1)%2;

    if (baseLocker[index] != 0)
        return false;
    
    auto type = static_cast<UnitType>(ch);

    if (!checkChar(type))
        return false;

    uint cost = UnitModel::checkCost(type);
    
    if (goldTab[index] - cost < 0)
        return false;
    
    goldTab[index] -= cost;

    auto unit = dynamic_pointer_cast<UnitBase>(Game::getUnit(id));
    unit->setProductUnit(type);
    baseLocker[index] = UnitModel::checkTime(type);

    return true;
}

//function checking the possibility of an attack and performs it
//return true if attack is possible, false if not
bool Game::checkAttack(uint id, uint id2, map<int,actionTuple> & actionMap)
{
    auto attacker = dynamic_pointer_cast<UnitModel>(Game::getUnit(id));
    auto defender = Game::getUnit(id2);

    if (attacker == nullptr || defender == nullptr)
        return false;
    
    int distance = calculateDistance(attacker->getX(),defender->getX(),
                                      attacker->getY(), defender->getY());

    if (actionMap.count(id) == 0)
        actionMap[id] = make_tuple(true, attacker->getSpeed());

    if (get<0>(actionMap[id]) == false || get<1>(actionMap[id]) == 0)
        return false;

    distance -= attacker->getAttackRange();

    if (distance > 0)
        return false;

    uint power = Game::getPower(attacker->getType(),defender->getType());
    defender->setDurability(defender->getDurability() - power);

    if (defender->getDurability() <= 0) {
        if(!Game::deleteObjectFromMap(defender->getX(),defender->getY(),defender))
            return false;
    }

    actionMap[id] = make_tuple(false, get<1>(actionMap[id])-1);

    return true;
}

//function returning iterator for searching unit
list<Cell>::iterator Game::findObjectByAddress
    (list<Cell>& objectList, const shared_ptr<Unit>& searchObject) {
        auto it = find_if(objectList.begin(), objectList.end(), [&](const Cell& cell) {
            if (holds_alternative<shared_ptr<Unit>>(cell)) {
                const auto& sharedUnit = get<shared_ptr<Unit>>(cell);
                return sharedUnit.get() == searchObject.get();
            }
            return false;
        });

        return it;
}

//function returning pointer for list object on chosen game path
list<Cell>* Game::getPath(uint x, uint y) {
    if (y >= 0 && y < mapBattle.size() && x >= 0 && x < mapBattle[y].size()) {
        return & mapBattle[y][x];
    }
    
    return nullptr;
}

//function calculating game distance for move and attack
uint calculateDistance(uint x1, uint x2, uint y1, uint y2)

{
    return abs(static_cast<int>(x1-x2))+abs(static_cast<int>(y1-y2));
}

//fucntion checking correctness of created unitType
bool checkChar(UnitType type)
{
    switch (type) {
    case UnitType::Knight:
    case UnitType::Swordsman:
    case UnitType::Archer:
    case UnitType::Pikeman:
    case UnitType::Ram:
    case UnitType::Catapult:
    case UnitType::Worker:
        return true;
    default:
        return false;
    }
}

//**********************************************************************************
//helping function section
//**********************************************************************************

void Game::displayMap() {
    for (uint i = 0; i < mapBattle.size(); ++i) {
        for (uint j = 0; j < mapBattle[i].size(); ++j) {
            const list<Cell>& cellList = mapBattle[i][j];
            for (const auto& cell : cellList) {
                if (holds_alternative<int>(cell)) {
                    int value = get<int>(cell);
                    cout << value << " ";
                } else if (holds_alternative<shared_ptr<Unit>>(cell)) {
                    shared_ptr<Unit> unit = get<shared_ptr<Unit>>(cell);
                    int id = unit->getID();
                    cout << id << " ";
                }
            }
        }
        cout << endl;
    }
}


  void Game::displayAllObjects() {
    for (const auto& pair : units) {
        cout << pair.first << " ";
        cout << pair.second->getX() << " ";
        cout << pair.second->getY();
        cout << " ";
        cout << endl;

    }
    }

