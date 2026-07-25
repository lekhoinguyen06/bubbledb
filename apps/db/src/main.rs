#[macro_use]
extern crate rocket;

use kv::Store;
use rocket::State;

#[post("/kv/<key>/<value>")]
fn set(key: String, value: String, store: &State<Store>) -> String {
    store.set(key, value);
    "Value set successfuly".to_string()
}

#[get("/kv/<key>")]
fn get(key: String, store: &State<Store>) -> String {
    match store.get(&key) {
        Some(value) => value,
        None => "Key not found".to_string(),
    }
}

#[launch]
fn rocket() -> _ {
    rocket::build()
        .manage(Store::new())
        .mount("/", routes![set, get])
}
