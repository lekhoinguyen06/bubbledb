use std::collections::HashMap;
use std::sync::Mutex;
pub struct KVal {
    data: Mutex<HashMap<String, String>>,
}

impl KVal {
    pub fn new() -> Self {
        KVal {
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

pub struct KVec {
    data: Mutex<HashMap<String, Vec<f64>>>,
}

impl KVec {
    pub fn new() -> Self {
        KVec {
            data: Mutex::new(HashMap::new()),
        }
    }

    pub fn get(&self, k: &str) -> Option<Vec<f64>> {
        self.data.lock().ok().and_then(|data| data.get(k).cloned())
    }

    pub fn set(&self, k: String, v: Vec<f64>) {
        if let Ok(mut data) = self.data.lock() {
            data.insert(k, v);
        }
    }
}
