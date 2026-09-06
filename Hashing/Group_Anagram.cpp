/*
------------------------------------------------------------
Problem : Group Anagrams (LeetCode 49)
Pattern : Hash Map + Canonical Representation

Time Complexity  : O(N * K log K)
Space Complexity : O(N * K)

Where:
    N = number of strings
    K = maximum length of a string


Idea:

Anagrams contain exactly the same characters with the same
frequencies, just arranged in different orders.

Therefore, if we sort every string, all anagrams produce the
same sorted string.

Example:

    "eat" → "aet"
    "tea" → "aet"
    "ate" → "aet"

Therefore:

    "aet" → ["eat", "tea", "ate"]


Algorithm:

1. Create a hash map:

       unordered_map<string, vector<string>> mp;

   The key will be the sorted version of a string.

2. For every string:

       string sortedStr = s;
       sort(sortedStr.begin(), sortedStr.end());

3. Use the sorted string as the key:

       mp[sortedStr].push_back(s);

4. Every key now represents one complete anagram group.

5. Iterate through the hash map and move each group's
   vector into the final result.


Example:

    Input:

        ["eat", "tea", "tan", "ate", "nat", "bat"]

    Sorted representations:

        eat → aet
        tea → aet
        tan → ant
        ate → aet
        nat → ant
        bat → abt

    Hash Map:

        "aet" → ["eat", "tea", "ate"]
        "ant" → ["tan", "nat"]
        "abt" → ["bat"]

    Result:

        [
            ["eat", "tea", "ate"],
            ["tan", "nat"],
            ["bat"]
        ]


Key Insight:

We don't need to compare every pair of strings.

Instead, create a common "signature" for every anagram.

Here, the signature is:

    sorted string

If two strings have the same signature, they belong to
the same anagram group.


Alternative Optimization:

Instead of sorting each string, we can count the frequency
of each of the 26 lowercase English letters.

For example:

    "eat"

    a → 1
    e → 1
    t → 1

This frequency array can be used as the hash-map key.

That approach reduces the string-processing cost from:

    O(K log K)

to approximately:

    O(K)


Current Solution:

    Simple
    Correct
    Easy to understand
    O(N * K log K)

Optimized frequency-counting solution:

    O(N * K)

------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            mp[sortedStr].push_back(s);
        }
        vector<vector<string>> result;
        for (auto pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};