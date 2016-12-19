/*
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
