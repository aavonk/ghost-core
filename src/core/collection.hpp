//
// Created by Aaron von Kreisler on 5/6/22.
// Collection is synonymous to a Table in an RDBMS. The properties of a Collection
// are similar to columns.
//

#ifndef GHOSTDB_COLLECTION_HPP
#define GHOSTDB_COLLECTION_HPP

#include "property.hpp"
#include "object.hpp"
#include <string>
#include <memory>
#include <map>
#include <utility>

namespace ghost::core {

class Collection {
    typedef std::map<std::string, Property*> PropertyList;
public:
    Collection() = default;
    explicit Collection(std::string name)
            :m_name(std::move(name)) { };
    ~Collection();

    /**
     *  Adds a property to this collection. Returns true if successful and false if otherwise.
     *  The operation will fail if the properties name already exists in the collection.
     *  Should only be used during collection creatio
     */
    bool add_property(Property* property);

    /**
     *     gets a property from the collections' property list. If one is not found by the name
     *     provided,a nullptr is returned.
     */
    Property* get_property(std::string property_name);
    std::string get_name() { return m_name; }

    std::unique_ptr<Object> new_object();

private:
    std::string m_name;
    PropertyList m_properties;
};
}
#endif //GHOSTDB_COLLECTION_HPP
