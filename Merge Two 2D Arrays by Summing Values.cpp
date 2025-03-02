class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int left=0,right=0;
        int n=nums1.size();
        int m=nums2.size();
        while(left<n && right<m){
           
            if(nums1[left][0]==nums2[right][0]){
                int sum=nums1[left][1]+nums2[right][1];
                ans.push_back({nums1[left][0],sum});
                left++;
                right++;
            }
            else if(nums1[left][0]>nums2[right][0]){
             ans.push_back({nums2[right][0],nums2[right][1]});
             right++;
            }
            else{
                ans.push_back({nums1[left][0],nums1[left][1]});
                left++;
            }
            
        }
     
        while(left<n){
           ans.push_back(nums1[left]);
           left++; 
        }
        while(right<m){
            ans.push_back(nums2[right]);
            right++;
        }
        return ans;
      
    }
};