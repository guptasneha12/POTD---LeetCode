class Solution {
public:
    // traverse from right to left
    vector<int> nextsmallestright(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSR(n);
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                NSR[i] = n;
            } else {
                while (!st.empty() && height[st.top()] >= height[i])
                    st.pop();
                if (st.empty())
                    NSR[i] = n;
                else
                    NSR[i] = st.top();
            }
            st.push(i);
        }
        return NSR;
    }

    // traverse from left to right
    vector<int> nextsmallestleft(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSL(n);
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1;
            } else {
                while (!st.empty() && height[st.top()] >= height[i])
                    st.pop();
                if (st.empty())
                    NSL[i] = -1;
                else
                    NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }

    int findmaxarea(vector<int>& height) {
        int n = height.size();
        vector<int> right = nextsmallestright(height);
        vector<int> left = nextsmallestleft(height);
        vector<int> width(n);
        for (int i = 0; i < n; i++) {
            width[i] = right[i] - left[i] - 1;
        }
        int max_area = 0;
        for (int i = 0; i < n; i++) {
            int area = height[i] * width[i];
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int maxarea = 0;
        // store the cummulative height for each row
        vector<int> height(c);
        // for first row store height
        for (int i = 0; i < c; i++) {
            height[i] =
                (matrix[0][i] == '1') ? 1 : 0; // for storing integer 0 and 1
        }

        maxarea =
            findmaxarea(height); // this return max area for first row only
        // now start from row 1
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            maxarea = max(maxarea, findmaxarea(height));
        }
        return maxarea;
    }
};