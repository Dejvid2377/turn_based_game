#include "../inc/unitModel.hh"
#include "../inc/unit.hh"
#include "../inc/unitBase.hh"

int main() {
  steady_clock::time_point begin = steady_clock::now();
  //unique_ptr<UnitModel> aa(new UnitModel(UnitType::Knight));
  //cout << aa->getCounter() << endl;
  
  UnitBase* obj1 = UnitBase::getInstance();
  UnitBase* obj2 = UnitBase::getInstance();

  if (obj1 != nullptr)
    cout << "obj1" << endl;

  if (obj2 != nullptr)
    cout << "obj2" << endl;

  steady_clock::time_point end = steady_clock::now();
  duration<double> elapsed_seconds = end - begin;
  std::cout << "Czas wykonania: " << elapsed_seconds.count() << " sekundy" << std::endl;
  return 0;
}