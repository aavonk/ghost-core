//
// Created by Aaron von Kreisler on 5/6/22.
//

#ifndef GHOST_CORE_OBJECT_PROPERTY_BASE_HPP
#define GHOST_CORE_OBJECT_PROPERTY_BASE_HPP

#include <cstring>
#include "property.hpp"

namespace ghost::core {
// Similar to the Collection level `Property` class, except that this will hold the
// metadata related to the property, and the data it holds.
// Abstract class.
class ObjectPropertyBase {
public:
    virtual ~ObjectPropertyBase()= default;
    virtual PropertyType get_type() { return type;};
    virtual std::string get_name() { return name;};
    virtual size_t get_size()  { return size;};


    virtual void* get_value_ref() = 0;

protected:
    PropertyType type;
    size_t size;
    size_t offset;
    std::string name;

    // The position of the property in the object. Might be useful for calculating the offset for mem storage
    // but would require the object keep an ordered data structure of properties, so we can calulate
    // a properties offset based off the sum of its previous items in the list.
    unsigned short int position;

};

}// namespace
#endif //GHOST_CORE_OBJECT_PROPERTY_BASE_HPP
