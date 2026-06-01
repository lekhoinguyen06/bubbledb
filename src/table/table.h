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

        // Row operations
        bool insert(std::string, std::string);
        bool erase(std::string);
        bool replace(std::string, Row);
        std::optional<Row *> get(std::string);

        // Metadata
        void list();
        void describe();
    };
}