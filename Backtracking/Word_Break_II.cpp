class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> memo;
        return backtrack(s, dict, memo);
    }

private:
    vector<string> backtrack(const string& s, const unordered_set<string>& dict, unordered_map<string, vector<string>>& memo) {
        if (memo.count(s)) {
            return memo[s];
        }
        
        if (s.empty()) {
            return {""};
        }
        
        vector<string> result;
        
        for (int i = 1; i <= s.length(); ++i) {
            string word = s.substr(0, i);
            if (dict.count(word)) {
                vector<string> suffixWays = backtrack(s.substr(i), dict, memo);
                for (const string& way : suffixWays) {
                    result.push_back(word + (way.empty() ? "" : " ") + way);
                }
            }
        }
        
        return memo[s] = result;
    }
};