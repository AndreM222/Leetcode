// --------------------------------------------[ Using 3 loops ]--------------------------------------------
// O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> groups;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < nums.size(); j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                long sum = 0;
                while(left < right) {
                    sum = (long)nums[left] + nums[right] + nums[j] + nums[i];

                    if(sum == target) {
                        groups.push_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1])
                            left++;
                        while(left < right && nums[right] == nums[right + 1])
                            right--;
                    } else if(sum < target) left++;
                    else right--;
                }
            }
        }

        return groups;
    }
};
