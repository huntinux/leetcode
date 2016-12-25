
// see 33

bool search(int* nums, int numsSize, int target) {
    
    int left = 0, right = numsSize - 1, middle;

    while(left <= right) {
        middle = (left + right) / 2;
        if(target == nums[middle]) return true;
        if(nums[left] < nums[middle]) {
            if(target >= nums[left] && target < nums[middle])            
                right = middle - 1;
            else
                left = middle + 1;
                
        } else if(nums[left] > nums[middle]){
            if(target > nums[middle] && target <= nums[right])            
                left = middle + 1;
            else
                right = middle - 1;
        } else { // 忽略left
            left++;
        }
    }
    return false; 
}
