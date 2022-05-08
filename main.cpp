#include <iostream>
#include <map>

#include "src/core/collection.hpp"
#include "src/core/object_property_int.hpp"

using namespace ghost::core;

int main()
{
    Collection* col = new Collection("foods");

    // Build the collections "schema"
    auto amountProperty = Property("amount", ghost::core::type_Int);
    col->add_property(&amountProperty);

    auto countProperty = Property("count", ghost::core::type_Int);
    col->add_property(&countProperty);

    // Create a new empty object that is schema-aware
    std::unique_ptr<Object> obj = col->new_object();

    obj->set("amount", 100);
    obj->set("count", 500);
    std::cout << "Hello, " << col->get_name() << " collection" << std::endl;

    std::map<std::string, ObjectPropertyBase*>::iterator it;
    for (it = obj->get_properties().begin(); it!=obj->get_properties().end(); it++) {
        void* v = it->second->get_value_ref();
        int t;
        t = *(int*)v ;
        std::cout<<"Property: "<< it->first<<" with value: "<<t<<"\n";
    }
        return 0;
}
