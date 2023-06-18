// Solution 1: Own sorting algorithm
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid;
        vector<int> list; // Temporary List

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

        // if odd then return middle
        if (list.size() % 2) return list[mid];

        // else return average of the two middle ones
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

// Solution 3: Same as solution 1 but use variables for counter instead of delete elements from the vectors
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid, l1, l2, m1, m2;
        vector<int> list; // Temporary List

        l1 = l2 = 0; // Current Index

        m1 = nums1.size(); // Max loop
        m2 = nums2.size(); // Max loop

        mid = (m1 + m2) / 2;

        // Sort the two vectors untill one is empty
        while (m1 > l1 && m2 > l2)
        {
            if(nums1[l1] < nums2[l2])
            {
                list.push_back(nums1[l1]); // Add element from index
                l1++;
            }
            else
            {
                list.push_back(nums2[l2]); // Add element from index
                l2++;
            }
        }

        // Sort vector 1 remaining ones
        while (m1 > l1)
        {
            list.push_back(nums1[l1]); // Add element from index
            l1++;
        }

        // Sort vector 2 remaining ones
        while (m2 > l2)
        {
            list.push_back(nums2[l2]); // Add element from index
            l2++;
        }

        // if odd then return middle
        if (list.size() % 2) return list[mid];

        // if odd then return middle
        return (double)(list[mid] + list[mid - 1]) / 2;
    }
};
