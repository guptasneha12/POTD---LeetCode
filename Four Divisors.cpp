class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ts=0;
        for(int num:nums){
            int cnt=0;  // for no. of divisors
            int sum=0;  // for sum of divisors
            // using square root method
            for(int i=1;i*i<=num;i++){
                if(num%i==0){
                    int j=num/i;
                    cnt++;
                    sum+=i;
                    if(i!=j){
                        cnt++;
                        sum+=j;
                    }
                    if(cnt>4) break;
                }
            }
            if(cnt==4){
                ts+=sum;
            }
        }
        return ts;
    }
};