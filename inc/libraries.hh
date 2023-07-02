#ifndef LIBRARY_HH
#define LIBRARY_HH

#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>
#include <chrono>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/unordered_map.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/base_object.hpp>


using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::dynamic_pointer_cast;
using std::runtime_error;
using std::list;
using std::chrono::steady_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::unordered_map;
using namespace boost::archive;
using namespace boost::serialization;

#endif
