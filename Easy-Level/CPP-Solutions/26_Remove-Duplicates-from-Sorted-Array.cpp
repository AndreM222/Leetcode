// --------------------------------------------[ loop ]--------------------------------------------
// O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> newArr;

        for(int curr : nums) {
            if(newArr.size() > 0 && newArr.back() == curr) continue;

            newArr.push_back(curr);
        }

        nums = newArr;
        return nums.size();
    }
};
