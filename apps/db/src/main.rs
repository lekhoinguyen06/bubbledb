#[macro_use]
extern crate rocket;

use kv::{KVal, KVec};
use rocket::State;
use rocket::serde::json::Json;
use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize)]
struct KVecReqBody {
    data: Vec<f64>,
}

#[post("/kvec/<key>", format = "json", data = "<req>")]
fn set_vector(key: String, req: Json<KVecReqBody>, vec_store: &State<KVec>) -> String {
    vec_store.set(key, req.data.clone());
    "Vector set successfuly".to_string()
}

#[get("/kvec/<key>")]
fn get_vector(key: String, vec_store: &State<KVec>) -> String {
    match vec_store.get(&key) {
        Some(vec) => serde_json::to_string(&vec).unwrap(),
        None => "Vector not found".to_string(),
    }
}

#[post("/kval/<key>/<value>")]
fn set(key: String, value: String, store: &State<KVal>) -> String {
    store.set(key, value);
    "Value set successfuly".to_string()
}

#[get("/kval/<key>")]
fn get(key: String, store: &State<KVal>) -> String {
    match store.get(&key) {
        Some(value) => value,
        None => "Key not found".to_string(),
    }
}

#[launch]
fn rocket() -> _ {
    rocket::build()
        .manage(KVal::new())
        .manage(KVec::new())
        .mount("/", routes![set, get, set_vector, get_vector])
}
