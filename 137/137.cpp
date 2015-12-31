/* Given an array of integers, every element appears three times except for one. Find that single one.


Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
*/

class Solution {
public:

 
    // hashmap : map 40ms
    int singleNumber(vector<int>& nums) {
        map<int, int> hashmap;

        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++)
        {
            if (hashmap.find(*it) != hashmap.end())
                hashmap[*it]++;
            else
                hashmap.insert(make_pair(*it, 1));
        }

        map<int, int>::iterator mit;
        for (mit = hashmap.begin(); mit != hashmap.end(); mit++)
        {
            //cout << mit->first << ":" << mit->second << endl;
            if (mit->second == 1) 
                return mit->first;
        }
    }
   
    // unordered_map 24ms
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++)
        {
            if (hashmap.find(*it) != hashmap.end())
                hashmap[*it]++;
            else
                hashmap.insert(make_pair(*it, 1));
        }

        unordered_map<int, int>::iterator mit;
        for (mit = hashmap.begin(); mit != hashmap.end(); mit++)
        {
            //cout << mit->first << ":" << mit->second << endl;
            if (mit->second == 1) 
                return mit->first;
        }
    }

    // unordered_map 24ms
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++)
        {
            if (hashmap.find(*it) != hashmap.end())
            {
                if (++hashmap[*it] == 3)
                    hashmap.erase(*it);
            }
            else
                hashmap.insert(make_pair(*it, 1));
        }
        return hashmap.begin()->first;
    }

    

};
