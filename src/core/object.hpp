//
// Created by Aaron von Kreisler on 5/6/22.
//

#ifndef GHOSTDB_OBJECT_HPP
#define GHOSTDB_OBJECT_HPP
#include <string>
#include <map>

#include "object_property_base.hpp"

namespace ghost::core {

/**
 * Think of an Object like a Row in a RDBMS.
 *
 */
class Object {
public:
    /**
     * Adds a property to this objects property list
     * @param prop the Object Property to register
     * @return true if successful, false if property with same name exists.
     */
    bool register_property(ObjectPropertyBase* prop);
    bool set(std::string property, int value);

    [[nodiscard]] std::map<std::string, ObjectPropertyBase*> get_properties() const { return m_properties; };
private:
    std::map<std::string, ObjectPropertyBase*> m_properties;
};

} // namespace
#endif //GHOSTDB_OBJECT_HPP
