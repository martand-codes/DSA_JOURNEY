/*
------------------------------------------------------------
Problem : Encode and Decode Strings (LeetCode 271)
Pattern : String Encoding / Length-Prefix Encoding / Parsing

Time Complexity :
Encode : O(N)
Decode : O(N)

Space Complexity : O(N)

Idea:
Encode a list of strings into a single string using
length-prefix encoding.

For every string:
- Append its length followed by a '#' delimiter.
- Append the original string immediately afterward.
- Repeat the process for every string in the input.

During decoding:
- Traverse the encoded string using an index.
- Find the '#' delimiter to identify the length prefix.
- Convert the length prefix into an integer.
- Extract exactly that many characters after '#'.
- Append the extracted string to the decoded vector.
- Advance the index past the extracted string.

Key Insight:
Length-prefix encoding makes the representation
unambiguous, even when strings contain '#' or other
special characters.

The decoder uses the stored length to determine exactly
where each string ends instead of relying on delimiters
inside the actual string content.

N represents the total number of characters processed
across all input strings, including encoding metadata.

Both encoding and decoding take linear time relative
to the total encoded or decoded data size.

------------------------------------------------------------
*/

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string = "";
        
        for (const string& s : strs) {
            encoded_string += to_string(s.length()) + "#" + s;
        }
        
        return encoded_string;
    }
    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int i = 0;       
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, length);
            decoded_strs.push_back(word);
            i = j + 1 + length;
        }
        
        return decoded_strs;
    }
};