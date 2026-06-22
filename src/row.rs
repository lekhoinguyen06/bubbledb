// Task: store a row

pub struct Row {
    pub k: String,
    pub index: [f64; 384],
    pub entity: [f64; 384],
    pub relate: [f64; 384],
    pub target: [f64; 384],
    pub value: String,
}

impl Row {
    pub fn new(
        k: String,
        index: [f64; 384],
        entity: [f64; 384],
        relate: [f64; 384],
        target: [f64; 384],
        value: String,
    ) -> Self {
        Row {
            k,
            index,
            entity,
            relate,
            target,
            value,
        }
    }

    pub fn zeros(k: &str, value: &str) -> Self {
        Row {
            k: k.to_string(),
            index: [0.0; 384],
            entity: [0.0; 384],
            relate: [0.0; 384],
            target: [0.0; 384],
            value: value.to_string(),
        }
    }
}
