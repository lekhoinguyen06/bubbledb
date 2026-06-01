#include "row.h"

using namespace db;

Row::Row(std::string key_, std::string value_) : key_(key_), value_(value_) {}

Row::~Row() {}

const std::string &Row::key() const
{
    return key_;
}

const std::string &Row::value() const
{
    return value_;
}