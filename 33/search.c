/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
4 5 6 7 0 1 2 
6 7 0 1 2 4 5

如果A[left] < A[middle] 说明左半部分是正常的升序
如果A[left] > A[middle] 说明右半部分是正常的升序


0 1 2 3
1 2 3 0
2 3 0 1
3 0 1 2


*/

// 如果有重复元素呢？ 看82题
int search(int* nums, int numsSize, int target) {
    
    int left = 0, right = numsSize - 1, middle;

    while(left <= right) {
        middle = (left + right) / 2;
        if(target == nums[middle]) return middle;
        if(nums[left] <= nums[middle]) { // 注意等号
            if(target >= nums[left] && target < nums[middle])            
                right = middle - 1;
            else
                left = middle + 1;
                
        } else {
            if(target > nums[middle] && target <= nums[right])  // 注意等号          
                left = middle + 1;
            else
                right = middle - 1;
        }
    }
    return -1; 
}


