//
// Created by Aaron von Kreisler on 5/6/22.
//

#include "object.hpp"

namespace ghost::core {

bool Object::register_property(ObjectPropertyBase* prop)
{
    if (m_properties.contains(prop->get_name())) {
        return false;
    }

    m_properties.insert(std::pair<std::string, ObjectPropertyBase*>(prop->get_name(), prop));
    return true;

}
bool Object::set(std::string property, int value)
{
    assert(!m_properties.empty());

    if (!m_properties.contains(property)) return false;

    ObjectPropertyBase* p = m_properties.at(property);
    if (p->get_type()!=type_Int) return false;

    void* val = p->get_value_ref();
    *(int*)val = value;

    return true;
}

}// namespace
