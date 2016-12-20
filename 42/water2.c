/*
使用两个index，分别指向数组的两边，记为left和right。每次比较A[left]和A[rgith],记较小者为min，那么从较小的一边开始，
例如此时A[left]<A[rgith],所以min=A[left], 那么如果A[left+1] < A[left], 那么A[left+1]上面可以存的水量是： A[left+1] - A[left]。
即：A[left+1] - min
一直到A[left+N] < min不满足条件为止
*/
int trap(const int arr[], size_t n)
{
    if(n < 3) return 0;

    int result = 0;
    int left = 0, right = n-1;
    

    while(left < right) {
        if(arr[left] < arr[right]) {
            int min = arr[left];
            left++;
            while(left < right && arr[left] < min) {
                result += min - arr[left];
                left++;
            }
        } else {
            int min = arr[right];
            right--;
            while(left < right && arr[right] < min) {
                result += min - arr[right];
                right--;
            }
        }
    }
    return result;
}





/*
WRONG SOLUTION!  SEE: http://shmilyaw-hotmail-com.iteye.com/blog/2289919

时间：O(n) 空间：O(1)

相比于第一种算法，空间复杂度降低

由两边往中间计算。 两个index，left和right
如果 A[left] > A[right] 那么 A[right] 这个柱子可以装多少水呢？ 如果他的右边最大值为right_max， 那么它可以装 right_max - A[right]，当然， right_max要大于A[right],否则该柱子不能装水。

初始状态， right_max = A[n-1], left_max = A[0]
*/



int trap(int arr[], size_t n)
{
	if(n < 3) return 0;

	int right_max = arr[n-1], left_max = arr[0];
	int left = 0, right = n - 1, result = 0;

	while(left < right) {

		if(arr[left] > arr[right]) {
			right_max = max(arr[right], right_max);
			result += right_max - arr[right];
			right--;
		} else {
			left_max = max(arr[left], left_max);
			result += left_max - arr[left];
			left++;
		}
	}
	return result;
}
