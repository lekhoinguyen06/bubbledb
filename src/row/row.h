#pragma once

#include <string>

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

        // void set(std::string, Row);
        // Row &get(std::string);
    };
}