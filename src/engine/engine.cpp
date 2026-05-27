#include "engine.h"

using namespace db;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::start()
{
    std::cout << "Bubble: Starting database engine..." << std::endl;
}

void Engine::shutdown()
{
    std::cout << "Bubble: Shuting down database engine" << std::endl;
}

void Engine::list()
{
    std::cout << "Tables:" << std::endl;
    for (auto &t : tables_)
    {
        std::cout << t.second.name() << std::endl;
    }
}

void Engine::show(std::string table_name)
{
    Table t = tables_.at(table_name);
    t.list();
}

Table &Engine::create(std::string name)
{
    Table table(name);
    std::pair<std::string, Table> new_table(name, table);
    tables_.insert(new_table);
    return tables_.at(name);
}

void Engine::destroy(std::string name)
{
    tables_.erase(name);
}

void Engine::insert(std::string table_name, std::string query)
{
    Table &t = tables_.at(table_name);

    std::string key, value;
    std::istringstream is(query);
    is >> key >> value;
    db::Row row(key, value);

    t.insert(row);
}

void Engine::erase(std::string table_name, std::string row_name)
{
    Table t = tables_.at(table_name);
    t.erase(row_name);
}