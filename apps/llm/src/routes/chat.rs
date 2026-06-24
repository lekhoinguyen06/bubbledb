use reqwest::Client;
use rocket::serde::{Deserialize, json::Json};

// Route: /chat
#[derive(Deserialize)]
#[serde(crate = "rocket::serde")]
pub struct ChatReq {
    prompt: String,
}

const LLM_API_URL: &str = "http://localhost:11434/api/chat";

#[post("/chat", data = "<body>")]
pub async fn chat(body: Json<ChatReq>) -> Json<serde_json::Value> {
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
