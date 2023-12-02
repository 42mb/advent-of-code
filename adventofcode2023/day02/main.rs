use std::cmp;
use std::fs::read_to_string;

fn day2_1() -> i32 {
    struct RGB {
        red: i32,
        green: i32,
        blue: i32,
    }

    impl RGB {
        fn set_to_zero(&mut self) {
            self.red = 0;
            self.green = 0;
            self.blue = 0;
        }
    }

    let mut color = RGB {
        red: 0,
        green: 0,
        blue: 0,
    };
    let color_limit = RGB {
        red: 12,
        green: 13,
        blue: 14,
    };

    let filename = "src/day2_1.prod";
    let mut result: i32 = 0;
    let mut game_counter: i32 = 0;

    for input_line in read_to_string(filename).unwrap().lines() {
        let mut game_is_valid = true;
        game_counter += 1;
        let game_set =
            &input_line[input_line.find(":").unwrap_or(input_line.len()) + 2..input_line.len()];
        let grab_set: Vec<&str> = game_set.split(";").collect();
        for grab in grab_set {
            let color_split: Vec<&str> = grab.split(",").collect();
            for mut color_element in color_split {
                color_element = color_element.trim();

                let color_pair: Vec<&str> = color_element.split(" ").collect();

                if color_pair[1].contains("red") {
                    color.red += color_pair[0].parse::<i32>().unwrap();
                }
                if color_pair[1].contains("blue") {
                    color.blue += color_pair[0].parse::<i32>().unwrap();
                }
                if color_pair[1].contains("green") {
                    color.green += color_pair[0].parse::<i32>().unwrap();
                }
            }

            if color.red > color_limit.red
                || color.blue > color_limit.blue
                || color.green > color_limit.green
            {
                game_is_valid = false;
            }
            color.set_to_zero();
        }

        if game_is_valid {
            result += game_counter;
        }
    }
    //println!("{}", result);
    return result;
}

fn day2_2() -> i32 {
    struct RGB {
        red: i32,
        green: i32,
        blue: i32,
    }

    impl RGB {
        fn set_to_zero(&mut self) {
            self.red = 0;
            self.green = 0;
            self.blue = 0;
        }
        fn product(&self) -> i32 {
            return self.red * self.green * self.blue;
        }
    }

    let mut color = RGB {
        red: 0,
        green: 0,
        blue: 0,
    };

    let mut color_max = RGB {
        red: 0,
        green: 0,
        blue: 0,
    };

    let filename = "src/day2_2.prod";
    let mut result: i32 = 0;

    for input_line in read_to_string(filename).unwrap().lines() {
        let game_set =
            &input_line[input_line.find(":").unwrap_or(input_line.len()) + 2..input_line.len()];
        let grab_set: Vec<&str> = game_set.split(";").collect();
        for grab in grab_set {
            let color_split: Vec<&str> = grab.split(",").collect();
            for mut color_element in color_split {
                color_element = color_element.trim();

                let color_pair: Vec<&str> = color_element.split(" ").collect();

                if color_pair[1].contains("red") {
                    color.red += color_pair[0].parse::<i32>().unwrap();
                }
                if color_pair[1].contains("blue") {
                    color.blue += color_pair[0].parse::<i32>().unwrap();
                }
                if color_pair[1].contains("green") {
                    color.green += color_pair[0].parse::<i32>().unwrap();
                }

                color_max.red = cmp::max(color.red, color_max.red);
                color_max.green = cmp::max(color.green, color_max.green);
                color_max.blue = cmp::max(color.blue, color_max.blue);
            }

            color.set_to_zero();
        }

        result += color_max.product();

        color_max.set_to_zero();
    }
    //println!("{}", result);
    return result;
}

fn main() {
    println!("Part1:  {0}\nPart2: {1}", day2_1(), day2_2());

    //part1:  2795
    //part2: 75561
}
