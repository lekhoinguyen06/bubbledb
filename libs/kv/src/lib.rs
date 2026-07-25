use std::collections::HashMap;
use std::sync::Mutex;
pub struct Store {
    data: Mutex<HashMap<String, String>>,
}

impl Store {
    pub fn new() -> Self {
        Store {
            data: Mutex::new(HashMap::new()),
        }
    }

    pub fn get(&self, k: &str) -> Option<String> {
        self.data.lock().ok().and_then(|data| data.get(k).cloned())
    }

    pub fn set(&self, k: String, v: String) {
        if let Ok(mut data) = self.data.lock() {
            data.insert(k, v);
        }
    }
}
