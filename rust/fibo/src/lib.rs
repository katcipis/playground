pub fn fib(n: i64) -> i64 {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

pub fn fibt(n: i64) -> i64 {
    if n == 0 {
        return 0;
    }
    if n == 1 {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

#[cfg(test)]
mod test {
    use super::{fib, fibt};

    const TESTCASES: &[(i64, i64)] = &[
        (0, 0),
        (1, 1),
        (2, 1),
        (3, 2),
        (4, 3),
        (5, 5),
        (6, 8),
        (7, 13),
        (8, 21),
        (9, 34),
        (10, 55),
    ];

    #[test]
    fn test_fib() {
        for tcase in TESTCASES.iter() {
            let n = tcase.0;
            let want = tcase.1;

            let got = fib(n);

            assert_eq!(want, got);
        }
    }

    #[test]
    fn test_fibt() {
        for tcase in TESTCASES.iter() {
            let n = tcase.0;
            let want = tcase.1;

            let got = fibt(n);

            assert_eq!(want, got);
        }
    }
}
