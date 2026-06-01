#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "engine.h"

TEST_CASE("Table::create()")
{
    db::Engine e;

    // Success cases
    CHECK(e.create("abc").has_value() == true);
    CHECK(e.create("123").has_value() == true);
    CHECK(e.create("abc123").has_value() == true);
    CHECK(e.create("abc_123").has_value() == true);

    // Fail cases
    CHECK(e.create("abc").has_value() == false);
    CHECK(e.create("@#$").has_value() == false);
}

TEST_CASE("Table::get()")
{
    db::Engine e;
    e.create("abc");

    CHECK(e.get("abc").has_value() == true);
    CHECK(e.get("abcd").has_value() == false);
}