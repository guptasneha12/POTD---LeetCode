class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        // base case
        if (i == m || j == n) {
            return -1e9;
        }
        // if already visited
        if (dp[i][j] != -1e9) {
            return dp[i][j];
        }
        int val = nums1[i] * nums2[j];
        int takeij = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1);
        int takei = solve(nums1, nums2, i, j + 1);
        int takej = solve(nums1, nums2, i + 1, j);
        return dp[i][j] = max({val, takeij, takei, takej});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        dp.assign(m, vector<int>(n, -1e9));
        return solve(nums1, nums2, 0, 0);
    }
};