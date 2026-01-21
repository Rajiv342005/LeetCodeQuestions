class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 0;
        unordered_map<double, int> freq;
        for (int i = 0; i < n; i++) {
            freq.clear();
            int vertical = 0;
            int currMax = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[j][0] == points[i][0]) {
                    vertical++;
                } else {
                    double slope =
                        (double)(points[j][1] - points[i][1]) /
                        (points[j][0] - points[i][0]);
                    freq[slope]++;
                    currMax = max(currMax, freq[slope]);
                }
            }
            currMax = max(currMax, vertical);
            ans = max(ans, currMax + 1);
        }
        return ans;
    }
};
