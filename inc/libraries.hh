#ifndef LIBRARY_HH
#define LIBRARY_HH

#define MAP_FILE "mapa.txt"
#define STATUS_FILE "status.txt"

#include <iostream>
#include <algorithm>
#include <list>
#include <memory>
#include <stdexcept>
#include <chrono>
#include <unordered_map>
#include <vector>
#include <variant>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::find;
using std::string;
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;
using std::runtime_error;
using std::list;
using std::vector;
using std::variant;
using std::ifstream;
using std::ios;
using std::chrono::steady_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::unordered_map;
using std::istringstream;

// using namespace boost::archive;
// using namespace boost::serialization;
// #include <boost/archive/text_oarchive.hpp>
// #include <boost/archive/text_iarchive.hpp>
// #include <boost/serialization/unordered_map.hpp>
// #include <boost/serialization/shared_ptr.hpp>
// #include <boost/serialization/export.hpp>
// #include <boost/serialization/base_object.hpp>
// #include <boost/serialization/vector.hpp>
// #include <boost/serialization/list.hpp>
// #include <boost/serialization/variant.hpp>

#endif
