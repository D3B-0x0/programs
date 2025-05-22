use std::io;

fn main() {
    println!("Simple Calculator");

    loop {
        println!("Enter expression (e.g., 2 + 3), or 'q' to quit:");

        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");

        let input = input.trim();

        if input == "q" {
            break;
        }

        let parts: Vec<&str> = input.split_whitespace().collect();

        if parts.len() != 3 {
            println!("Invalid input. Please use the format 'number operator number'.");
            continue;
        }

        let num1: f64 = match parts[0].parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid number: {}", parts[0]);
                continue;
            }
        };

        let operator = parts[1];

        let num2: f64 = match parts[2].parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid number: {}", parts[2]);
                continue;
            }
        };

        let result = match operator {
            "+" => num1 + num2,
            "-" => num1 - num2,
            "*" => num1 * num2,
            "/" => {
                if num2 == 0.0 {
                    println!("Cannot divide by zero.");
                    continue;
                }
                num1 / num2
            }
            _ => {
                println!("Invalid operator: {}", operator);
                continue;
            }
        };

        println!("Result: {}", result);
    }

    println!("Goodbye!");
}
