class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        // iota is used to fill array from 0 to n-1
        iota(indices.begin(), indices.end(),
             0); // this will fill indices from 0 to n-1;

        auto lambda = [&](int i, int j) { return positions[i] < positions[j]; };
        // sort positions as per their no. in line
        sort(indices.begin(), indices.end(), lambda);
        vector<int> res;
        stack<int> st;
        for (int& curridx : indices) {
            // if curridx is at right then push it into stack
            if (directions[curridx] == 'R') {
                st.push(curridx);
            } else {
                while (!st.empty() && healths[curridx] > 0) {
                    int topidx = st.top();
                    if (healths[curridx] > healths[topidx]) {
                        st.pop();
                        healths[curridx] -= 1;
                        healths[topidx] = 0;
                    } else if (healths[curridx] < healths[topidx]) {
                        healths[curridx] = 0;
                        healths[topidx] -= 1;
                    } else {
                        st.pop();
                        healths[curridx] = 0;
                        healths[topidx] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                res.push_back(healths[i]);
            }
        }
        return res;
    }
};