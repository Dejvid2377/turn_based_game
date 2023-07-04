#ifndef INT_SERIALIZATION_HPP
#define INT_SERIALIZATION_HPP

#include "libraries.hh"

namespace boost {
namespace serialization {
    template <typename Archive>
    void save(Archive& ar, const int& value, const unsigned int version) {
        ar & value;
    }

    template <typename Archive>
    void load(Archive& ar, int& value, const unsigned int version) {
        ar & value;
    }

    template <typename Archive>
    void serialize(Archive& ar, int& value, const unsigned int version) {
        boost::serialization::split_free(ar, value, version);
    }
}
}

#endif
