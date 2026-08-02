class Solution {
public:
    int countValidPrefixes(string s) {
        set<string> validPrefixes;
        int count0 = 0 , count1 = 0;
        string prefixStr;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '0'){
                    count0++;
            } else {
                    count1++;
            }
            prefixStr += s[i];
            if(abs(count0-count1) <= 1){
                    validPrefixes.insert(prefixStr);
            }
        }
        return validPrefixes.size();
    }
};