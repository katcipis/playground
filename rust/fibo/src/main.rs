use fibo::fibt;

fn main() {
    println!("{}", fibt(10000000000000));
    // This one causes stack overflow (naive)
    //println!("{}", fib(10000000000000));
}
