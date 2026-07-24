class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> ans;
        unordered_set<int> optiNums;
        for(int i = 0; i<nums.size(); i++){
            optiNums.insert(nums[i]);
        }
        unordered_set<int> preAns;
        for(int val : optiNums){
            for(int val1 : optiNums){
                preAns.insert(val^val1);
            }
        }
        for(int val : preAns){
            for(int val1 : optiNums){
                ans.insert(val^val1);
            }
        }
        return ans.size();
    }
};