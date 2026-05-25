#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

namespace db
{
    class Row
    {
    private:
        std::string key_;
        std::string value_;

    public:
        Row(std::string, std::string);
        ~Row();

        const std::string &key() const;
        const std::string &value() const;
    };

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

    class Table
    {
    private:
        std::string name_;
        std::unordered_map<std::string, Row> rows_;

    public:
        Table(std::string name);
        ~Table();

        const std::string &name() const;
        void list();
        void insert(Row);
        void erase(std::string);
    };

    Table::Table(std::string name) : name_(name) {}

    Table::~Table() {}

    void Table::insert(Row r)
    {
        std::pair<std::string, Row> new_row(r.key(), r);
        rows_.insert(new_row);
    }

    void Table::erase(std::string row_key)
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
            Row row = r.second;
            std::cout << "Key: " << row.key() << " Value: " << row.value() << std::endl;
        }
    }

    class Engine
    {
    private:
        std::unordered_map<std::string, Table> tables_;

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

    Engine::Engine() {}

    Engine::~Engine() {}

    void Engine::start()
    {

        std::cout << "BubbleDB" << std::endl;
        std::cout << "Starting database engine..." << std::endl;
    }

    void Engine::shutdown()
    {
        std::cout << "Shuting down database engine..." << std::endl;
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
        Row row(key, value);

        t.insert(row);
    }

    void Engine::erase(std::string table_name, std::string row_name)
    {
        Table t = tables_.at(table_name);
        t.erase(row_name);
    }
}