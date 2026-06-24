#[macro_use]
extern crate rocket;

mod routes;

use routes::chat::chat;
use routes::embed::embed;

// Route: /
#[get("/")]
fn index() -> &'static str {
    "Hello, world! This is BubbleDB."
}

#[launch]
fn rocket() -> _ {
    rocket::build().mount("/", routes![index, chat, embed])
}
