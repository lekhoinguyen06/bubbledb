struct Val {
    data: String,
}

impl Val {
    fn new(data: String) -> Self {
        Val { data }
    }

    fn get(&self) -> &str {
        &self.data
    }
}
