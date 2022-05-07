#include <iostream>
#include "src/core/collection.hpp"

int main()
{
    ghost::core::Collection *col = new ghost::core::Collection("foods");
    auto prop = ghost::core::Property("int", ghost::core::type_Int);
    col->add_property(&prop);
    std::cout << "Hello, " << col->get_name()<< " collection"<< std::endl;
    return 0;
}
