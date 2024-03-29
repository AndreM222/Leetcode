// This is O(n^2) solution
class Solution
{

  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        int total; // The total amount when combined content
        vector<int> curr; // Container for final answer

        // Loop Box One
        for (int i = 0; i < nums.size(); i++)
        {
            // Loop Box Two
            for (int j = i + 1; j < nums.size(); j++)
            {
                // Add two boxes together
                total = nums[i] + nums[j];

                /* If total equals to target then add to current
                and return current content */
                if (total == target)
                {
                    curr.push_back(i);
                    curr.push_back(j);
                    return curr;
                }
            }
        }

        // If no content then return nothing 
        return {};
    }
};

// This is O(n) solution
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> container; // Create hashmap container

        for(int i = 0; i < nums.size(); i++) // Loop through values
        {
            if(container.find(target - nums[i]) != container.end()) // If value found
            {
                return {container[target - nums[i]], i}; // return value using the key
                // Target - the value in current is the value in the hashmap we are looking for
            }

            container[nums[i]] = i; // Else add to hasmap current
        }

        return {}; // If no content then return nothing
    }
};
