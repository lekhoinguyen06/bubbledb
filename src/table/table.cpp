#include "table.h"

using namespace db;

Table::Table(std::string name) : name_(name) {}

Table::~Table() {}

bool Table::insert(std::string k, std::string v)
{
    try
    {
        Row r(k, v);
        std::pair<std::string, db::Row> new_row(r.key(), r);
        rows_.insert(new_row);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

bool Table::erase(std::string row_key)
{
    rows_.erase(row_key);
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
