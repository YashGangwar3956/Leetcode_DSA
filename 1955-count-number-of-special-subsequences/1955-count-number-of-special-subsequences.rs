
impl Solution {
    pub fn count_special_subsequences(nums: Vec<i32>) -> i32 {
        let m: i64 = 1_000_000_007;

        let mut a: i64 = 0;
        let mut b: i64 = 0;
        let mut c: i64 = 0;

        for x in nums {
            match x {
                0 => {
                    a = (2 * a + 1) % m;
                }
                1 => {
                    b = (2 * b + a) % m;
                }
                2 => {
                    c = (2 * c + b) % m;
                }
                _ => {}
            }
        }

        c as i32
    }
}

