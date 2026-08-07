class Solution {
public:
    int n;
    int t[1001][1001];
    static bool wordSort(string &word1 , string &word2){
        return word1.size() < word2.size();
    }
    bool isPred(string &prevWord , string &currWord){
        int M = prevWord.size();
        int N = currWord.size();
        if(M>=N || N-M != 1){
            return false;
        }
        int i = 0, j = 0;
        while(i<M && j<N){
            if(prevWord[i] == currWord[j]){
                i++;
            }
            j++;
        }
        return i == M;
    }
    int lis(vector<string> &words, int prevIdx , int currIdx){
        if(currIdx == n){
            return 0;
        }
        if(prevIdx != -1 && t[prevIdx][currIdx] != -1){
            return t[prevIdx][currIdx];
        }
        int taken = 0 , notTaken = 0;
        if(prevIdx == -1 || isPred(words[prevIdx],words[currIdx])){
            taken = 1+lis(words,currIdx,currIdx+1);
        }
        notTaken = lis(words,prevIdx,currIdx+1);
        if(prevIdx != -1){
            t[prevIdx][currIdx] = max(taken,notTaken);
        }
        return max(taken,notTaken);
    }
    int longestStrChain(vector<string>& words) {
        memset(t,-1,sizeof(t));
        n = words.size();
        sort(words.begin(),words.end(),wordSort);
        return lis(words,-1,0);
    }
};