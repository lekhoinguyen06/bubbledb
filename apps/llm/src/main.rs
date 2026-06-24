#[macro_use]
extern crate rocket;

use reqwest::Client;
use rocket::serde::{Deserialize, Serialize, json::Json};

// Route: /chat
#[derive(Deserialize)]
#[serde(crate = "rocket::serde")]
struct ChatReq {
    prompt: String,
}

const LLM_API_URL: &str = "http://localhost:11434/api/chat";

#[post("/chat", data = "<body>")]
async fn chat(body: Json<ChatReq>) -> Json<serde_json::Value> {
    let client = Client::new();
    client
        .post(LLM_API_URL)
        .json(&serde_json::json!(
            {
                "model": "gemma3:270m",
                "messages": [{"role": "user", "content": body.prompt}],
                "stream": false
            }
        ))
        .send()
        .await
        .unwrap()
        .json::<serde_json::Value>()
        .await
        .unwrap()
        .into()
}

// Route: /
#[get("/")]
fn index() -> &'static str {
    "Hello, world!"
}

#[launch]
fn rocket() -> _ {
    rocket::build().mount("/", routes![index, chat])
}
