//
// Created by Aaron von Kreisler on 5/6/22.
//

#include "property.hpp"

ghost::core::Property::Property(std::string n, PropertyType t)
        :name(std::move(n)), type(t)
{

}

