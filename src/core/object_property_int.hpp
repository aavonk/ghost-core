//
// Created by Aaron von Kreisler on 5/6/22.
//

#ifndef GHOST_CORE_OBJECT_PROPERTY_INT_HPP
#define GHOST_CORE_OBJECT_PROPERTY_INT_HPP
#include "object_property_base.hpp"
#include <string>

namespace ghost::core {

class ObjectPropertyInt : public ObjectPropertyBase {
public:
    explicit ObjectPropertyInt(std::string name);
    ObjectPropertyInt(const ObjectPropertyInt& obj);
    ~ObjectPropertyInt() override;

    void* get_value_ref() override;
private:
    int* value;
};
}

#endif //GHOST_CORE_OBJECT_PROPERTY_INT_HPP
