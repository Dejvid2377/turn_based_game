#include "libraries.hh"
#include "unitBase.hh"
#include "unitModel.hh"
BOOST_CLASS_EXPORT_GUID(UnitBase, "unitBase")
BOOST_CLASS_EXPORT_GUID(UnitModel, "unitModel")

class Game {
private:
    std::unordered_map<int, std::shared_ptr<Unit>> units;

    friend class boost::serialization::access;
    
    template <class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & units; // Serialize the 'units' member variable
    }

public:
    void addUnit(int id, std::shared_ptr<Unit> unit) {
        units[id] = unit;
    }

    void removeUnit(int id) {
        units.erase(id);
    }

    std::shared_ptr<Unit> getUnit(int id) {
        auto it = units.find(id);
        if (it != units.end()) {
            return it->second;
        }
        return nullptr;
    }

    void printAllUnits() const {
        for (const auto& pair : units) {
            std::cout << "klucz : " << pair.first << " | ";
            std::cout << "ID obiektu : " << pair.second->getID() << std::endl;
        }
    }

};
