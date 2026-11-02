class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto finder = find(nums.begin(), nums.end(), target);
        if (finder != nums.end()) return distance(nums.begin(), finder);
        
        return -1;
    }
};
