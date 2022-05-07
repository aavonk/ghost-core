//
// Created by Aaron von Kreisler on 5/6/22.
//

#ifndef GHOSTDB_PROPERTY_HPP
#define GHOSTDB_PROPERTY_HPP

#include <string>
#include <utility>

namespace ghost::core {

enum PropertyType {
  type_Int,
  type_String,
};

/** A Property is an individual schema item that belongs to a collection. It is  used
 * to tell the Collection that the property with name x is of type y. Properties are on the
 * collection level & not the object level.
 */
class Property {
public:
    Property(std::string n, PropertyType t);
    std::string name;
    PropertyType type;
};
}
#endif //GHOSTDB_PROPERTY_HPP
