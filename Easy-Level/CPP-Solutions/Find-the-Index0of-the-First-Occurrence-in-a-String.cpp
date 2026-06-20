// --------------------------------------------[ use find function ]--------------------------------------------
// O(n * m)
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

// --------------------------------------------[ loop ]--------------------------------------------
// O(n)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sentenceLength = needle.length();
        int length = haystack.length() - sentenceLength + 1;

        if(haystack == needle) return 0;

        for(int i = 0; i < length; i++)
            if(haystack.substr(i, sentenceLength) == needle)
                return i;

        return -1;
    }
};
