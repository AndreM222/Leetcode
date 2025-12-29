// --------------------------------------------[ Using Loops and Two Points ]--------------------------------------------
// O(N^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;

        sort(nums.begin(), nums.end());

        int second, third, total;

        for(int first = 0; first < nums.size(); first++)
        {
            if(first > 0 && nums[first] == nums[first - 1]) continue;

            second = first + 1;
            third = nums.size() - 1;
            while(second < third)
            {
                total = nums[first] + nums[second] + nums[third];

                if(total > 0) third--;
                else if(total < 0) second++;
                else {
                    sums.push_back({nums[first], nums[second], nums[third]});
                    second++;

                    while(nums[second] == nums[second - 1] && second < third) second++;
                }
            }

        }

        return sums;
    }
};

// --------------------------------------------[ Using Hashmaps and Difference of Two Points ]--------------------------------------------
// O(N^3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> sets;

        sort(nums.begin(), nums.end());

        for(int curr : nums)
        {
            if(sets.find(curr) == sets.end())
            {
                sets[curr] = 1;
                continue;
            }

            sets[curr]++;
        }

        vector<vector<int>> sums;
        unordered_map<int, int> memory;
        unordered_set<string> sumHistory;
        int first, second, third;

        for(int i = 0; i < nums.size(); i++)
        {
            first = nums[i];
            memory = sets;
            memory[first]--;

            for(int j = 0; j < nums.size(); j++)
            {
                second = nums[j];

                if(memory[second] > 0)
                {
                    memory[second]--;
                    third = -1 * (first + second);

                    if(memory.find(third) != memory.end())
                    {
                        if(memory[third] <= 0) continue;

                        string currLine = to_string(first) +
                                        "," + to_string(second) +
                                        "," + to_string(third);

                        if(sumHistory.find(currLine) != sumHistory.end()) continue;

                        sumHistory.insert(currLine);

                        sums.push_back({first, second, third});
                    }
                }
            }

            sets[first]--;
        }

        return sums;
    }
};
