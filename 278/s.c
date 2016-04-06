/*
278. First Bad Version
Total Accepted: 38794 Total Submissions: 174518 Difficulty: Easy

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    
	int start = 1, end = n, mid;

	while(start < end)
	{
		//mid = (start + end) / 2; // overflow
		mid = start + (end - start) / 2;
		if(isBadVersion(mid))
		{
            end = mid;
		}
		else
		{
			start = mid + 1;
		}

	}
	return end;
}

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);
int firstBadVersion(int n) {
    
	int start = 1, end = n, mid;

	while(start < end)
	{
		//mid = (start + end) / 2; // overflow
		mid = start + (end - start) / 2;
		if(isBadVersion(mid))
		{
			if(isBadVersion(mid - 1))
			{
				end = mid - 1;
			}
			else
			{
				return mid;
			}

		}
		else
		{
			start = mid + 1;
		}

	}
	return end;
}
