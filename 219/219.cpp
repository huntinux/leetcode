/*
   219. Contains Duplicate II

   Total Accepted: 39704 Total Submissions: 140223 Difficulty: Easy

   Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
   */

class Solution {
    public:
        /*
            using hashmap
        */

        // unordered_map is faster than map here.
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> hashmap; // first is the num, second is the num's index
            unordered_map<int, int>::const_iterator it;
            for (int i = 0; i < nums.size(); i ++)
            {
                int key = nums[i];
                it = hashmap.find(key);
                if (it != hashmap.end())
                {
                    if (i - it->second <= k) return true;
                    else
                    {
                        hashmap[key] = i; // update the index
                    }
                }
                else
                {
                    hashmap.insert(make_pair(key, i));
                }
            }
            return false;
        }


        // unordered_map is faster than map here.
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> hashmap; // first is the num, second is the num's index
            unordered_map<int, int>::const_iterator it;
            for (int i = 0; i < nums.size(); i ++)
            {
                it = hashmap.find(nums[i]);
                if (it != hashmap.end())
                {
                    if (i - it->second <= k) return true;
                    else
                    {
                        hashmap[nums[i]] = i; // update the index
                    }
                }
                else
                {
                    hashmap.insert(make_pair(nums[i], i));
                }
            }
            return false;
        }

        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            map<int, int> hashmap; // first is the num, second is the num's index
            map<int, int>::const_iterator it;
            for (int i = 0; i < nums.size(); i ++)
            {
                it = hashmap.find(nums[i]);
                if (it != hashmap.end())
                {
                    if (i - it->second <= k) return true;
                    else
                    {
                        hashmap[nums[i]] = i; // update the index
                    }
                }
                else
                {
                    hashmap.insert(make_pair(nums[i], i));
                }
            }
            return false;
        }
        
        /*
            using hashset 
        */
        // The basic idea is to maintain a set s which contain unique values from nums[i - k] to nums[i - 1], if nums[i] is in set s then return true else update the set.
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_set<int> hashset; // first is the num, second is the num's index
            for (int i = 0; i < nums.size(); i ++)
            {
                if (i > k) hashset.erase(nums[i - k - 1]);
                if (hashset.find(nums[i]) != hashset.end()) return true;
                hashset.insert(nums[i]);
            }

            return false;
        }

};
