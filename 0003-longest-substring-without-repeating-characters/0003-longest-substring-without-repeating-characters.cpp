class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int length = 0;
    int first = 0;
    int second = 0;
    vector<int> nums(256, 0); // handle all ASCII chars

    while (second < s.size()) {
        if (nums[s[second]] == 0) {
            nums[s[second]]++;
            second++;
            length = max(length, second - first);
        } else {
            while (first < second && nums[s[second]] != 0) {
                nums[s[first]] = 0;
                first++;
            }
            nums[s[second]]++;
            second++;
        }
    }
    return length;
    }

};