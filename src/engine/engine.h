#pragma once

#include <unordered_map>
#include <iostream>
#include <sstream>

#include "table.h"
#include "row.h"

namespace db
{
    class Engine
    {
    private:
        std::unordered_map<std::string, db::Table> tables_;

    public:
        // Engine operations
        Engine();
        ~Engine();

        // Engine operations
        void start();
        void shutdown();
        // void query(std::string);
        void reset();

        // Table operations
        std::optional<Table *> create(std::string);
        bool destroy(std::string);
        std::optional<Table *> get(std::string);

        // Metadata
        void list_table();
        void help();
        void version();
    };
}