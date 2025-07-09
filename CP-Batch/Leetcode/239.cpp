class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> d;
        multiset<int> ms;
        int l=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ms.insert(nums[i]);
            if(i-l+1 == k){
                d.push_back(*ms.rbegin());
                ms.erase(ms.find(nums[l++]));
            }
        }
        return d;
    }
};