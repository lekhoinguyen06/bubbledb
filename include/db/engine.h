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
        Engine();
        ~Engine();
        void start();
        void shutdown();
        Table &create(std::string);
        void list();
        void show(std::string);
        void destroy(std::string);
        void insert(std::string, std::string);
        void erase(std::string, std::string);
        // Row *get();
        // void set();
    };
}