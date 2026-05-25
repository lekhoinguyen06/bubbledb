#include "db/engine.h"

int main()
{
    db::Engine engine;
    engine.start();
    engine.create("users");
    engine.list();
    engine.create("products");
    engine.list();
    engine.insert("users", "benz 18");
    engine.insert("users", "david 20");
    engine.show("users");
    engine.shutdown();
    return 0;
}