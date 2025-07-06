fn find_max_indices(nums: &[i32]) -> Option<i32>{
    if nums.is_empty(){
        return None;
    }

    let mut max = nums[0];

    for &num in nums.iter(){
        if num > max {
            max = num;
        }
    }

    Some(max)
}