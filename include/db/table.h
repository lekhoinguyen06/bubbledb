#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

#include "row.h"

namespace db
{
    class Table
    {
    private:
        std::string name_;
        std::unordered_map<std::string, db::Row> rows_;

    public:
        Table(std::string name);
        ~Table();

        const std::string &name() const;
        void list();
        void insert(Row);
        void erase(std::string);
    };
}