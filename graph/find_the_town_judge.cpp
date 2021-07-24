class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    
        if(n == 1){
            return 1;
        }
        vector<int> in(n+1, 0);
        vector<int> out(n+1, 0);
        for(int i = 0; i<trust.size();i++){
            out[trust[i][0]]++;
            in[trust[i][1]]++;
        } 
        
        for(int j = 0; j<n+1; j++){
            if(out[j] == 0  && in[j] == n-1){
                return j;
            }
        }
        return -1;
        
    }
};