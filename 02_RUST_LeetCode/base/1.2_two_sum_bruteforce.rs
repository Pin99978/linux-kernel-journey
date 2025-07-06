fn two_sum_brute_force(nums: &[i32], target: i32) -> Option<(usize, usize)> {
    let n = nums.len();

    for i in 0..n {
        for j in i+1..n {
            if nums[i] + nums[j] == target {
                return Some((i, j));
            }
        }
    }

    None
}