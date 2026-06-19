// --------------------------------------------[ loop ]--------------------------------------------
// O(n)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> newList;

        for(int curr : nums) {
            if(curr != val) newList.push_back(curr);
        }

        nums = newList;
        return nums.size();
    }
};
