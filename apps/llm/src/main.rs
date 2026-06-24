#[macro_use]
extern crate rocket;

mod routes;

use routes::chat::chat;

// Route: /
#[get("/")]
fn index() -> &'static str {
    "Hello, world!"
}

#[launch]
fn rocket() -> _ {
    rocket::build().mount("/", routes![index, chat])
}
