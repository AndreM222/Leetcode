class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size() - 1;
        int bigIndex = length - 1;

        while (bigIndex >= 0 && nums[bigIndex] >= nums[bigIndex + 1])
            bigIndex--;

        if(bigIndex >= 0) {
            while (nums[length] <= nums[bigIndex]) length--;

            int curr = nums[length];
            nums[length] = nums[bigIndex];
            nums[bigIndex] = curr;
        }

        reverse(nums.begin() + bigIndex + 1, nums.end());
    }
};
