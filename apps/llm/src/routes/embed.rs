use reqwest::Client;
use rocket::serde::{Deserialize, json::Json};

// Route: /embed
#[derive(Deserialize)]
#[serde(crate = "rocket::serde")]
pub struct EmbedReq {
    prompt: String,
}

const LLM_API_URL: &str = "http://localhost:11434/api/embeddings";

#[post("/embed", data = "<body>")]
pub async fn embed(body: Json<EmbedReq>) -> Json<serde_json::Value> {
    let client = Client::new();
    client
        .post(LLM_API_URL)
        .json(&serde_json::json!(
            {
                "model": "nomic-embed-text",
                "prompt": body.prompt,
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
