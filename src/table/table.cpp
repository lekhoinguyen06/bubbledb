#include "table.h"

using namespace db;

Table::Table(std::string name) : name_(name) {}

Table::~Table() {}

bool Table::insert(std::string k, std::string v)
{
    auto [it, inserted] = rows_.emplace(k, Row(k, v));
    return inserted;
}

bool Table::erase(std::string row_key)
{
    return rows_.erase(row_key) > 0;
}

bool Table::replace(std::string k, std::string v)
{
    auto it = rows_.find(k);
    if (it == rows_.end())
        return false;
    it->second = Row(k, v);
    return true;
}

std::optional<Row *> Table::get(std::string k)
{
    auto it = rows_.find(k);
    if (it == rows_.end())
        return nullptr;
    return &it->second;
}

const std::string &Table::name() const
{
    return name_;
}

void Table::list()
{
    std::cout << "Table: " << name_ << std::endl;
    for (auto &r : rows_)
    {
        db::Row row = r.second;
        std::cout << "Key: " << row.key() << " Value: " << row.value() << std::endl;
    }
}

void Table::describe()
{
    std::cout << "string, string" << std::endl;

    // Implement std::type_trait in Schema milestone to print Schema type
}
