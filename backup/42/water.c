/*
   Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

   For example,
   Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
   */

/*
 
  一个柱子上面能盛多少水，和它两边的最大值有关。设当前柱子高为h，它左边的最大值为max_left, 右边的最大值为max_right, 那么该柱子能盛的水量是：
min(max_left, max_right) - h
当然如果结果小于0， 应该置为0
 */

#include <stdio.h>
#include <malloc.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int trap(const int arr[], size_t n)
{
	if(n < 3) return 0;

	int result = 0, i;
	int *max_left  = malloc(n * sizeof(int));
	int *max_right = malloc(n * sizeof(int));

	max_left[0] = 0;
	for(i = 1; i < n; i++) {
		max_left[i] = max(arr[i-1], max_left[i-1]);
	}
	max_right[n - 1] = 0;
	for(i = n - 2; i >= 0; i--) {
		max_right[i] = max(arr[i+1], max_right[i+1]);
	}

	for(i = 0; i < n; i++) {
		int h = min(max_left[i], max_right[i]) - arr[i];
		result = result + ((h > 0) ? h : 0);
	}
	free(max_left);
	free(max_right);
	return result;
}
