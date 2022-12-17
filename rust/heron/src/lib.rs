// Inspired from SICP lectures :-)

pub fn sqrt(x: f64) -> f64 {
    let dampener = avg_damp(move |y| x / y);
    let find_fixed_point = fixed_point(dampener);
    let guess = 1.0;

    find_fixed_point(guess)
}

// Why returning the close is different than taking it as parameter ?
// - https://doc.rust-lang.org/rust-by-example/fn/closures/input_parameters.html
// - https://doc.rust-lang.org/book/ch19-05-advanced-functions-and-closures.html#returning-closures

fn fixed_point<F>(f: F) -> Box<dyn Fn(f64) -> f64>
where
    F: Fn(f64) -> f64,
{
    Box::new(|x| x)
}

fn avg_damp<F>(f: F) -> Box<dyn Fn(f64) -> f64>
where
    F: Fn(f64) -> f64 + 'static,
{
    Box::new(move |x| f(x) + x / 2.0)
}

#[cfg(test)]
mod test {
    use super::sqrt;

    #[test]
    fn test_sqrt() {
        assert_eq!(sqrt(4.0), 2.0);
        assert_eq!(sqrt(16.0), 4.0);
    }
}
