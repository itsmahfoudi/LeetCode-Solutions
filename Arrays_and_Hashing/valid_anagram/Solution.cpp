class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int occurences[26] = {0};
        for (char ch : s) {
            occurences[ch - 'a'] += 1;
        }
        for (char ch : t) {
            --occurences[ch - 'a'];
            if (occurences[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
