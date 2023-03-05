// Inspired from SICP lectures :-)
// This is very closure heavy and inneficient, but it is a good exercise to:
// - understand the overall algorithm (guess + avg dampener + fixed point searching)
// - check how dynamic closures are used/defined in Rust

pub fn sqrt(x: f64) -> f64 {
    let dampened_guesser = avg_damp(move |y| x / y);
    let find_fixed_point = fixed_point(dampened_guesser);
    let initial_guess = 1.0;

    find_fixed_point(initial_guess)
}

// Why returning the closure is different than taking it as parameter ?
// - https://doc.rust-lang.org/rust-by-example/fn/closures/input_parameters.html
// - https://doc.rust-lang.org/book/ch19-05-advanced-functions-and-closures.html#returning-closures
// - https://doc.rust-lang.org/reference/types/closure.html

fn fixed_point<F: Fn(f64) -> f64 + 'static>(f: F) -> Box<dyn Fn(f64) -> f64> {
    Box::new(move |x| {
        let mut x = x;
        for _ in 1..10000 {
            let next = f(x);
            if next == x {
                return x;
            }
            x = next;
        }
        // Ugly hack =P
        panic!("fixed point failed to converge")
    })
}

fn avg_damp<F: Fn(f64) -> f64 + 'static>(f: F) -> Box<dyn Fn(f64) -> f64> {
    Box::new(move |x| (f(x) + x) / 2.0)
}

#[cfg(test)]
mod test {
    use super::sqrt;

    #[test]
    fn test_sqrt() {
        assert_eq!(sqrt(1.0), 1.0);
        assert_eq!(sqrt(4.0), 2.0);
        assert_eq!(sqrt(9.0), 3.0);
        assert_eq!(sqrt(16.0), 4.0);
        assert_eq!(sqrt(25.0), 5.0);
    }
}
