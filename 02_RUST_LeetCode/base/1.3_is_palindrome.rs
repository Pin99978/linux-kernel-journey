impl Solution {
    pub fn is_palindrome(s: String) -> bool {
    
        let cleaned: Vec<char> = s
            .chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase())
            .collect();
            
        if cleaned.is_empty() {
            return true; // an empty cleaned string is a valid palindrome
        }       
        let mut l_ptr = 0;
        let mut r_ptr = cleaned.len() -1 ;



        while l_ptr < r_ptr {
            if cleaned[l_ptr] != cleaned[r_ptr] {
                return false;
            }
            l_ptr += 1;
            r_ptr -= 1;
        }

        true
    }
}