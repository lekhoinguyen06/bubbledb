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
        void start();
        void shutdown();
        // void query(std::string);
        // void reset();
        // void help();
        // void version();

        // Table operations
        Table &create(std::string);
        void list();
        void show(std::string);
        void destroy(std::string);
        // Table &get(std::string);
    };
}