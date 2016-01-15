
// ���ֲ��ң������Ѿ������������ʣ�ÿ���ų�һЩ�����ܵ�Ԫ�ء�
// low��high��mid
// ���nums[mid] > nums[high] ��ô������ұ�(������mid) low = mid + 1
// ���nums[mid] < nums[high] ��ô�������ߣ�����mid�� high = mid 
// ���nums[mid] = nums[high] ��ô�������ȷ�����ı�, ���ǿ��Խ�nums[high]ɾ�� high = high - 1 
int findMin(int* nums, int numsSize) 
{
    int low = 0, high = numsSize - 1, mid = 0;

    while(low < high)
    {
        mid = (low + high) / 2;
        if (nums[mid] > nums[high])
            low = mid + 1;
        else if (nums[mid] < nums[high])
            high = mid;
        else
            high -= 1;
    }

    return nums[low];
}

