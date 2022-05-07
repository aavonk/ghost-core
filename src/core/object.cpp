//
// Created by Aaron von Kreisler on 5/6/22.
//

#include "object.hpp"

namespace ghost::core {

bool Object::register_property(ObjectPropertyBase* prop)
{
    if(m_properties.contains(prop->get_name())) {
        return false;
    }

    m_properties.insert(std::pair<std::string, ObjectPropertyBase*>(prop->get_name(), prop));
    return true;

}


}// namespace
