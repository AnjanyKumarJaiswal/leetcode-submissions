class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int activeCount = count(begin(s),end(s),'1');

        vector<int> zero_block;

        int i = 0;
        while(i<=n){
            if(s[i] == '0'){
                int strt_idx = i;
                while(i<=n && s[i] == '0'){
                    i++;
                }
                zero_block.push_back(i-strt_idx);
            } else {
                i++;
            }
        }
        int maxPair = 0;
        for(int i = 1; i<zero_block.size(); i++){
            int tmpPair = zero_block[i-1]+zero_block[i];
            maxPair = max(maxPair,tmpPair);
        }
        return activeCount+maxPair;
    }
};