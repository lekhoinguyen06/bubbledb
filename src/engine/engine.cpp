#include "engine.h"

using namespace db;

Engine::Engine() {}

Engine::~Engine() {}

void Engine::start()
{
    std::cout << "Bubble: Starting database engine..." << std::endl;
}

void Engine::reset()
{
    std::cout << "Bubble: Reset database" << std::endl;
}

void Engine::shutdown()
{
    std::cout << "Bubble: Shuting down database engine" << std::endl;
}

void Engine::list_table()
{
    std::cout << "Tables:" << std::endl;
    for (auto &t : tables_)
    {
        std::cout << t.second.name() << std::endl;
    }
}

void Engine::help()
{
    std::cout << "Usage: db [command]\n"
                 "\n"
                 "Commands:\n"
                 "  -h, --help       Show this help message\n"
                 "  -v, --version    Show version\n"
                 "\n"
                 "Table operations:\n"
                 "  create <name>    Create a table\n"
                 "  get <name>       Get a table\n"
                 "  destroy <name>   Destroy a table\n"
                 "  list             List all tables\n"
                 "\n"
                 "Row operations:\n"
                 "  insert <key> <value>     Insert a row\n"
                 "  get <key>                Get a row\n"
                 "  erase <key>              Erase a row\n"
                 "  replace <key> <value>    Replace a row\n";
}

void Engine::version()
{
    std::cout << "0.1.0";
}

std::optional<Table *> Engine::create(std::string name)
{
    Table table(name);
    std::pair<std::string, Table> new_table(name, table);
    tables_.insert(new_table);
    return &tables_.at(name);
}

bool Engine::destroy(std::string name)
{
    size_t r = tables_.erase(name);

    if (r == 0)
        return false;
    return true;
}

// void Engine::insert(std::string table_name, std::string query)
// {
//     Table &t = tables_.at(table_name);

//     std::string key, value;
//     std::istringstream is(query);
//     is >> key >> value;
//     db::Row row(key, value);

//     t.insert(row);
// }

// void Engine::erase(std::string table_name, std::string row_name)
// {
//     Table t = tables_.at(table_name);
//     t.erase(row_name);
// }