//
// Created by Aaron von Kreisler on 5/6/22.
//

#include "gtest/gtest.h"
#include "../src/core/collection.hpp"

TEST(Collection, CreateWorks) {
    auto coll = ghost::core::Collection("collection");
    ghost::core::Property prop = ghost::core::Property("prop", ghost::core::type_Int);

    EXPECT_EQ(coll.get_name(), "collection");
}

TEST(Collection, AddPropertyWorks) {
    auto coll = ghost::core::Collection("collection");
    ghost::core::Property* prop = new ghost::core::Property("prop", ghost::core::type_Int);

    bool res = coll.add_property(prop);

    EXPECT_EQ(res, true);
}


TEST(Collection, CantAddDuplicateProperty) {
    auto coll = ghost::core::Collection("collection");
    auto* prop = new ghost::core::Property("prop", ghost::core::type_Int);

    coll.add_property(prop);
    auto p = coll.get_property("prop");
    EXPECT_NE(p, nullptr);
    EXPECT_EQ(p->name, prop->name);
    EXPECT_FALSE(coll.add_property(prop));
}


//TEST(Collection, CreateNewObject) {
//    auto coll = ghost::core::Collection("collection");
//    auto prop =  ghost::core::Property("prop", ghost::core::type_Int);
//
//    coll.add_property(&prop);
//    std::unique_ptr<ghost::core::Object> obj = coll.new_object();
//
//    auto props = obj->get_properties();
//
//}