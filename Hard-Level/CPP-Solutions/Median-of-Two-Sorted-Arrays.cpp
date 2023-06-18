// Solution 1: Own sorting algorithm
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid;
        vector<int> list;

        mid = (nums1.size() + nums2.size()) / 2; // Find Mid Point

        // Sort the two vectors untill one is empty
        while (nums1.size() > 0 && nums2.size() > 0)
        {
            if(nums1[0] < nums2[0])
            {
                list.push_back(nums1[0]); // Add first element
                nums1.erase(nums1.begin()); // Erase first element added
            }
            else
            {
                list.push_back(nums2[0]); // Add first element
                nums2.erase(nums2.begin()); // Erase first element added
            }
        }

        // Sort vector 1 remaining ones
        while (nums1.size() > 0)
        {
            list.push_back(nums1[0]); // Add first element
            nums1.erase(nums1.begin()); // Erase first element added
        }

        // Sort vector 2 remaining ones
        while (nums2.size() > 0)
        {
            list.push_back(nums2[0]); // Add first element
            nums2.erase(nums2.begin()); // Erase first element added
        }

        // if greater then 1 and total is odd then
        if (list.size() % 2) return list[mid];

        // Else return average of the two middle ones
        return (double)(list[mid] + list[mid - 1]) / 2;
    }
};

// Solution 2: With Sorting function
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid;
        vector<int> list;

        // Add to list vector
        for (int i : nums1) list.push_back(i);
        for (int i : nums2) list.push_back(i);

        sort(list.begin(), list.end()); // O(NlogN)

        mid = list.size() / 2;

        // if greater then 1 and total is odd then return middle
        if (list.size() % 2) return list[mid];
        
        // Else return average of the two middle ones
        return (double)(list[mid - 1] + list[mid]) / 2;
    }
};
