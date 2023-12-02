use aho_corasick::AhoCorasick;
use std::{fs::read_to_string, vec};

#[allow(dead_code)]
fn part1() -> i32 {
    let filename: &str = "/home/archi/Projects/adventofcode/2023/day01/src/input_day1_1.prod";
    let mut result: Vec<i32> = vec![];

    for input_line in read_to_string(filename).unwrap().lines() {
        let mut line: Vec<_> = input_line
            .chars()
            .filter(|c: &char| c.is_numeric())
            .collect();

        if line.len() >= 2 {
            line.drain(1..line.len() - 1);
        } else if line.len() == 1 {
            line.push(line[0]); // in the case of "7absbd" the result has to be 77
        }
        let nmb_string: String = line.into_iter().collect();

        if let Ok(parsed_int) = nmb_string.parse::<i32>() {
            result.push(parsed_int);
        } else {
            println!("Conversion to i32 failed");
        }
    }
    let sum: i32 = result.iter().sum();
    //println!("{}", sum);
    return sum;
}

#[allow(dead_code)]
fn part2() -> i32 {
    let filename: &str = "/home/archi/Projects/adventofcode/2023/day01/src/input_day1_2.prod";
    let mut result: Vec<i32> = vec![];

    for input_line in read_to_string(filename).unwrap().lines() {
        //let mut input_line: &str;
        let mut str_nmb: Vec<_> = vec![];

        str_nmb.push(find_number(input_line, false));

        let rev_input_line: &str = &input_line.chars().rev().collect::<String>();
        str_nmb.push(find_number(rev_input_line, true));

        let nmb_string: String = str_nmb.into_iter().collect();

        if let Ok(parsed_int) = nmb_string.parse::<i32>() {
            result.push(parsed_int);
        } else {
            println!("Conversion to i32 failed");
        }
    }
    let sum: i32 = result.iter().sum();
    //println!("{}", sum);
    return sum;
}

fn find_number(input_line: &str, right_to_left: bool) -> &str {
    let patterns = &[
        "ZEROO00OOplaceholder",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ZERO0o0placeholder",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    ];
    let rev_patterns = &[
        "ZEROO00OOplaceholder",
        "eno",
        "owt",
        "eerht",
        "ruof",
        "evif",
        "xis",
        "neves",
        "thgie",
        "enin",
        "ZERO0O0placeholder",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
    ];
    let translation_patterns: Vec<&str> = vec![
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "1", "2", "3", "4", "5", "6", "7",
        "8", "9", "10",
    ];
    let active_pattern: &[&str];
    if right_to_left {
        active_pattern = rev_patterns;
    } else {
        active_pattern = patterns;
    }
    let mut matches = vec![];

    let ac = AhoCorasick::new(active_pattern).unwrap();

    for mat in ac.find_iter(input_line) {
        matches.push(mat.pattern());
        break; //we only need the first number, also if we go through the reversed order
    }

    return translation_patterns[matches[0].as_i32() as usize];
}

fn main() {
    println!("part1: {0}\npart2: {1}", part1(), part2());

    //result p1: 54632
    //result p2: 54019
}
