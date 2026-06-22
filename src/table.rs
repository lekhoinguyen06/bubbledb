use std::collections::HashMap;

use crate::row::Row;

pub struct Table {
    id: String,
    rows: HashMap<String, Row>,
}

impl Table {
    pub fn new(id: &str) -> Self {
        Table {
            id: id.to_string(),
            rows: HashMap::new(),
        }
    }

    pub fn add(&mut self, r: Row) -> Option<Row> {
        self.rows.insert(r.k.clone(), r)
    }

    pub fn get(&self, k: &str) -> Option<&Row> {
        self.rows.get(k)
    }
}
