//
// Created by Aaron von Kreisler on 5/6/22.
//

#include "collection.hpp"
#include "object_property_int.hpp"

#include <memory>

namespace ghost::core {

bool Collection::add_property(Property* prop)
{
    if (m_properties.contains(prop->name)) {
        return false;
    }
    m_properties.insert(std::make_pair(prop->name, prop));
    return true;
}

Property* ghost::core::Collection::get_property(std::string property_name)
{
    if (m_properties.contains(property_name)) {
        return m_properties.at(property_name);
    }
    return nullptr;
}
Collection::~Collection()
{
    std::map<std::string, Property*>::iterator it;
    for (it = m_properties.begin(); it!=m_properties.end(); it++) {
        delete it->second;
    }

}
std::unique_ptr<Object> Collection::new_object()
{
    // For each Property in the collections property list (schema), we want
    // to create a new ObjectProperty (think of it like adding a new Column to a row)
    // for that specific data type e.g. Int, String.


    /**
     * ColumnBase:
     *  - name,
     *  - data_size bytes -> get, set on construction
     *  - data / value
     */

    /**
     * Algorithm:
     * For each property in property list:
     *   - property.get_type();
     *   switch(type)
     *   case: type_Int:
     *       obj.AddColumn(new ObjectPropertyInt(property.get_name()))
     *   case: type_String:
     *       obj.AddColumn(new ObjectPropertyString(property.get_name()));
     *
     *
     * collection.SaveItemToCache() or collection.AddItem() <- will save to cache / file later
     * When we save the object to the cache (memory addresses), we will need to get an obj, and
     *  then for each property write its data to memory & set offset of next item from the obj.get_size() method.
     *
     *  for each property in obj:
     *       - memcpy(destination + property.get_offset(), data, data.size());
     *
     */

    std::unique_ptr<Object> obj = std::make_unique<Object>();

    std::map<std::string, Property*>::iterator it;
    for (it = m_properties.begin(); it!=m_properties.end(); it++) {
        Property* p = it->second;
        switch (p->type) {
        case type_Int:obj->register_property(new ObjectPropertyInt(p->name));
            break;
        }
    }

    return obj;
}

} // namespace


/**
 * // schema is passed in from the query engine layer. No need to check it.
 * // It will be heavily verified prior to getting to the core layer.
 * // API for creating a new collection example:
 *  * --------------------------------------------------------------------------------
 * assert(schema.num_properties() > 0)
 *
*  Collection* col = new Collection("foods");
 * for (int i = 0; i < schema.num_properties(); i++{
 *  col.register_property(schema.property_at(i))
 * }
 *
 * col.register_new_page_buffer(new ghost::core::PageBuffer(stuff))
 *
 * --------------------------------------------------------------------------------
 *
 * API for adding an object to a collection
 *
 * query engine layer will need to get the collection name out of the query and get the
 * schema for that Collection from somewhere (e.g. schema registry). The query engine will validate
 * the correct types, etc and pass to the core layer, where we will insert the object to the
 * page cache and later write to disk.
 *
 *
 * Object* obj = new Object;
 * for every item in the query {
 *  obj->register_property(item);
 * }
 *
*/