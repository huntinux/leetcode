public class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set s = new HashSet();
        for(int i = 0; i < nums.length; i++)
        {
            boolean r = s.add(nums[i]);
            if (!r)
                return true;
        }
        return false;
    }
}
