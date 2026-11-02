class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int length = words.front().length();
        vector<int> list;
        unordered_map<string, int> map;

        for(string word : words) map[word]++;

        for(int i = 0; i < length; ++i) {
            unordered_map<string, int> visited;
            int total = 0;

            for(int j = i; j + length <= s.length(); j += length) {
                string curr = s.substr(j, length);
                auto str = map.find(curr);
                if (str == map.end()) {
                    visited.clear();
                    total = 0;
                    continue;
                }

                visited[curr]++;
                total++;
                while(visited[curr] > str->second) {
                    visited[s.substr(j - (total - 1) * length, length)]--;
                    total--;
                }

                if(total == words.size())
                    list.push_back(j - (total - 1) * length);
            }
        }
        return list;
    }
};
