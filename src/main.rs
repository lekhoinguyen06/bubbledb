use colored::Colorize;

use crate::row::Row;
use crate::table::Table;

mod row;
mod table;

fn main() {
    println!("{}{}", "Bubble".bold(), "DB".bold().bright_magenta());

    let mut a = Table::new("a");
    let b = Row::zeros("b", "Hello world!");
    let c = Row::zeros("c", "I am Nguyen");

    a.add(b);
    a.add(c);

    match a.get("a") {
        Some(r) => println!("{}", r.value),
        None => println!("Not found"),
    }

    match a.get("b") {
        Some(r) => println!("{}", r.value),
        None => println!("Not found"),
    }

    match a.get("c") {
        Some(r) => println!("{}", r.value),
        None => println!("Not found"),
    }
}
