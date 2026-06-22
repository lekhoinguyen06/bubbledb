// Manage: rows

use crate::row::Row;

pub struct Table {
    id: String,
    rows: Option<Vec<Row>>,
}

impl Table {
    pub fn new(id: &str) -> Self {
        Table {
            id: id.to_string(),
            rows: None,
        }
    }

    pub fn add(&mut self, r: Row) {
        match &mut self.rows {
            Some(rows) => rows.push(r),
            None => self.rows = Some(vec![r]),
        }
    }

    pub fn get(&self, k: &str) -> Option<&Row> {
        match &self.rows {
            Some(rows) => rows.iter().find(|&x| x.k == k),
            None => None,
        }
    }
}
