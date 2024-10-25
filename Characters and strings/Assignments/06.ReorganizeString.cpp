// leetcode 767. Reorganize String
// https://leetcode.com/problems/reorganize-string/


class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }

        // Find the most frequent character
        char most_freq_char;
        int max_freq = 0;
        for (int i = 0; i < 26; i++) {
            if (hash[i] > max_freq) {
                max_freq = hash[i];
                most_freq_char = i + 'a';
            }
        }

        // If the most frequent character cannot fit within the string without repeating
        if (max_freq > (s.size() + 1) / 2) {
            return "";
        }

        int index = 0;
        // Place the most frequent character at even indices
        while (max_freq > 0) {
            s[index] = most_freq_char;
            index += 2;
            max_freq--;
        }

        hash[most_freq_char - 'a'] = 0;

        // Place the remaining characters
        for (int i = 0; i < 26; i++) {
            while (hash[i] > 0) {
                if (index >= s.size()) index = 1; // Move to odd index if even indices are filled
                s[index] = i + 'a';
                index += 2;
                hash[i]--;
            }
        }

        return s;
    }
};
