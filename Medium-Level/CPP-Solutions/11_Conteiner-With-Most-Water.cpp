// O(N)
class Solution {

private:
    int largestArea(vector<int>& wall, int total)
    {
        int area = 0, height = 0, width = 0, tmp = 0;
        int left = 0, right = total - 1;

        // Parse while the walls are at different ends
        while(left != right)
        {
            // Get current width
            width = right - left;

            // Set lower wall for max height possible for water
            if(wall[left] > wall[right])
            {
                height = wall[right];
                right--;
            }
            else
            {
                height = wall[left];
                left++;
            }

            // Set current height for comparison
            tmp = height * width;

            // Set biggest area between last and current area
            area = area > tmp ? area : tmp;
        }

        // Return longest area
        return area;
    }

public:
    int maxArea(vector<int>& height) {
        return largestArea(height, height.size());
    }
};
