use std::env;

#[cfg(windows)]
#[link(name = "soltys_math_lib")]
extern "C" {
    fn sm_is_prime(n: i64) -> i32;
}

fn main() {
    let path = env::current_dir().unwrap();
    println!("The current directory is {}", path.display());
    let mut is_prime = unsafe { sm_is_prime(21) };
    println!("is 21 prime?: {}", is_prime == 1);
    is_prime = unsafe { sm_is_prime(37) };
    println!("is 37 prime?: {}", is_prime == 1);
}
