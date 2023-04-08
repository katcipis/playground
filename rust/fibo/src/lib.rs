pub fn fib(n: i64) -> i64 {
    fn fibrec(n: i64, a: i64, b: i64) -> i64 {
        if n <= 0 {
            return a;
        }
        fibrec(n - 1, b, a + b)
    }
    fibrec(n, 0, 1)
}

#[cfg(test)]
mod test {
    use super::fib;

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
}
