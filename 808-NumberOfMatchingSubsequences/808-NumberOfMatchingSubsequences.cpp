// Last updated: 6/29/2026, 10:22:13 AM
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map< char, vector<int>> idxMp;

        for(int i = 0; i < s.length(); i++) {
            idxMp[s[i]].push_back(i);
        }

        const auto isValid = [&](string &word) -> bool {
            int currIdx = -1;
            for(int i = 0; i < word.length(); i++) {
                char ch = word[i];

                auto idx = upper_bound(idxMp[ch].begin(), idxMp[ch].end(), currIdx) - idxMp[ch].begin();
                if (idx == idxMp[ch].size()) return false;
                currIdx = idxMp[ch][idx];
            }
            return true;
        };

        int cnt = 0;
        for(auto &w : words) {
            cnt += isValid(w) ? 1 : 0;
        }
        return cnt;
    }
};

// time complexity of this question is  O(words.length() * words[i] * log(s))