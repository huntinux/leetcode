/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
// 快排
// start: 22:09
// end: 22:39
// 注意快排退化成冒泡的情况
class Solution {
public:
    // 直接用left作为pivot，对于极端case会退化成冒泡排序
    int partition_v1(vector<int>& nums, int left, int right) {
        int pivot_value = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= pivot_value) right--;
            if (left < right) nums[left++] = nums[right];
            while (left < right && nums[left] <= pivot_value) left++;
            if (left < right) nums[right--] = nums[left];
        }
        nums[left] = pivot_value;
        return left;
    }

    // https://leetcode.cn/problems/sort-an-array/solution/pai-xu-shu-zu-by-leetcode-solution/
    // 这个写法更加简洁
    // 数组分成3部分：[sorted | unsorted | pivot]
    // 过程就是不断把 unsorted 中的数据与pivot比较，如果比pivot小，就放到sorted数组的后面即可
    // 为了避免快排退化成冒泡，这里需要随机选取pivot的初始位置。
    // 还有一个极端的测试用例是 5万个2...
    // 需要对与pivot相等的情况再优化下: 三路排序
    // https://blog.51cto.com/greyfoss/5468611
    void SelectMedianOfThread(vector<int>& nums, int left, int mid, int right) {
        if (nums[left] > nums[mid]) std::swap(nums[left], nums[mid]);
        if (nums[mid] > nums[right]) std::swap(nums[mid], nums[right]);
        if (nums[left] > nums[mid]) std::swap(nums[left], nums[mid]);
    }
    int partition_v2(vector<int> &nums, int left, int right) {
        int pivot_index = rand() % (right - left + 1) + left;
        //int pivot_index = left + ((right - left) >> 1);
        //SelectMedianOfThread(nums, left, pivot_index, right);
        std::swap(nums[pivot_index], nums[right]);
        int pivot = nums[right];
        int i = left, j = left;
        while (j < right) {
            if (nums[j] < pivot) {
                std::swap(nums[i++], nums[j++]);
            } else {
                j++;
            }
        }
        std::swap(nums[i], nums[right]);
        return i;
    }

    // 三路快排
    std::pair<int, int> partition_v3(vector<int> &nums, int left, int right) {
        int pivot_index = rand() % (right - left + 1) + left;
        std::swap(nums[pivot_index], nums[left]);
        int pivot = nums[left];
        int i = left + 1;
        int lt = left;
        int gt = right + 1;
        while (i < gt) {
            if (nums[i] < pivot) {
                std::swap(nums[i++], nums[++lt]);
            } else if (nums[i] > pivot) {
                std::swap(nums[i], nums[--gt]);
            } else {
                i++;
            }
        }
        std::swap(nums[left], nums[lt]);
        return {lt, gt};
    }


   //三路快排：分为小于，等于，大于三部分
    void quicksort(vector<int> &arr, int low, int high) {
        if (low >= high) return;
        int randidx = low + rand() % (high - low + 1);
        swap(arr[low], arr[randidx]);
        
        int pivot = arr[low];
        int lt = low, gt = high+1, i = low + 1;
        while (i < gt) {
            if (arr[i] < pivot) {
                swap(arr[lt+1], arr[i]);
                lt++;
                i++;
            } else if (arr[i] > pivot) {
                swap(arr[i], arr[gt-1]);
                gt--;
            } else {
                i++;
            }
        }
        swap(arr[low], arr[lt]);
        quicksort(arr, low, lt - 1);
        quicksort(arr, gt, high);
    }

    // 随机选取pivot的位置，并和left交换，这样后面逻辑和partition_v1保持一致
    int partition(vector<int>& nums, int left, int right) {
        int pivot = rand() % (right - left + 1) + left;
        std::swap(nums[left], nums[pivot]);
        int pivot_value = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= pivot_value) right--;
            if (left < right) nums[left++] = nums[right];
            while (left < right && nums[left] <= pivot_value) left++;
            if (left < right) nums[right--] = nums[left];
        }
        nums[left] = pivot_value;
        return left;
    }
    void quick_sort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        // 常规快排无法快速处理有大量重复元素的情况
        //int pivot = partition(nums, left, right);
        //int pivot = partition_v2(nums, left, right);
        //quick_sort(nums, left, pivot - 1);
        //quick_sort(nums, pivot + 1, right);

        // 三路快排，中间是相等元素，不用再排序
        auto [lt, gt] = partition_v3(nums, left, right);
        quick_sort(nums, left, lt - 1);
        quick_sort(nums, gt, right);
    }

    // begin: 22: 41
    // end: 22: 54
    // 堆排序
    // 堆其实是一个完全二叉树，底层用数组存储
    // 大根堆：根节点大于左右子节点
    // 假设有n个节点，第一个非叶子节点下标为 n/2 - 1
    // 首先建堆，从第一个非叶子结点开始调整，使其满足堆堆性质即可 (自下而上)
    // 最后排序，每次将根节点和最后一个节点交换，然后自上而下调整即可
    void adjust(vector<int>& nums, int n, int i) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < n && nums[l] > nums[largest]) largest = l;
        if (r < n && nums[r] > nums[largest]) largest = r;

        if (largest != i) {
            std::swap(nums[i], nums[largest]);
            adjust(nums, n, largest);
        }
    }

    void heap_sort(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; --i) {
            adjust(nums, n, i);
        }
        for (int i = n - 1; i >= 0; --i) {
            std::swap(nums[0], nums[i]);
            adjust(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        {
        srand(time(NULL));
        quick_sort(nums, 0, nums.size() - 1);
        //quicksort(nums, 0, nums.size() - 1);
        }
        //heap_sort(nums);
        return nums;
    }
};
// @lc code=end

