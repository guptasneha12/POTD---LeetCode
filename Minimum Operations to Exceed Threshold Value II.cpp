class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //use priority queue
        priority_queue<long long,vector<long long>,greater<>> pq(nums.begin(),nums.end());
        int res=0;
        while(pq.top()<k){
            long long a=pq.top();
            pq.pop();
            long long b=pq.top();
            pq.pop();
            pq.push(2*a+b);
            res++;
        }
        return res;
    }
};