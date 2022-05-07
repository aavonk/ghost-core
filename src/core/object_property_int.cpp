//
// Created by Aaron von Kreisler on 5/6/22.
//

#include "object_property_int.hpp"

#include <utility>

namespace ghost::core {

ObjectPropertyInt::ObjectPropertyInt(std::string n)
{
    // initialize base class members;
    size = sizeof(int);
    type = type_Int;
    name = std::move(n);
}
ObjectPropertyInt::~ObjectPropertyInt()
{
    delete value;
}
ObjectPropertyInt::ObjectPropertyInt(const ObjectPropertyInt& obj)
        :ObjectPropertyBase(obj)
{
    size = obj.size;
    type = obj.type;
    name = obj.name;
    // allocate new ptr to hold data
    value = new int;
    *value = *obj.value;
}



void* ObjectPropertyInt::get_value_ref()
{
    // return the address of the value pointer. TODO: This might need to drop the address of operator
    return &value;
}

}


