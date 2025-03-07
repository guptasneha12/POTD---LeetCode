class Solution {
public:

bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for(int i=left;i<=right;i++){
            if(isprime(i)==true){
                if(!prime.empty() && i-prime.back()<=2){
                    return {prime.back(),i};   // immediate return because min diff between two primes are 2 except {2,3}
                }
                prime.push_back(i);
            }
        }

        int mindiff=INT_MAX;
        vector<int> res={-1,-1};
        for(int i=1;i<prime.size();i++){
            int diff=prime[i]-prime[i-1];
            if(diff<mindiff){
                mindiff=diff;
                res={prime[i-1],prime[i]};
            }
        }
        return res;
    }
};