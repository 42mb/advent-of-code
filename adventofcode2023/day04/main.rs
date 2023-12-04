use std::fs::read_to_string;

fn day4_1() {
    let mut score: i32 = 0;
    let filename = "src/day4_1.prod";

    for input_line in read_to_string(filename).unwrap().lines() {
        let line = input_line.split(':').collect::<Vec<_>>();
        let game = line[1].split('|').collect::<Vec<_>>();

        let numbers_mine: Vec<i32> = game[0]
            .split_whitespace()
            .map(|x| -> i32 { x.parse().unwrap() })
            .collect();
        let numbers_winning: Vec<i32> = game[1]
            .split_whitespace()
            .map(|x| -> i32 { x.parse().unwrap() })
            .collect();

        let mut card_score: i32 = 0;
        let mut is_first_win: bool = true;

        for elem in numbers_mine {
            if numbers_winning.contains(&elem) {
                if is_first_win {
                    card_score = 1;
                    is_first_win = false;
                } else {
                    card_score *= 2;
                }
            }
        }
        score += card_score;
    }
    println!("{}", score);
}

fn main() {
    day4_1(); // result: 22488
}
