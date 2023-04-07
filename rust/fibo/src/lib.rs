pub fn fib(_n: i64) -> i64 {
    return 0;
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
        (9, 55),
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
