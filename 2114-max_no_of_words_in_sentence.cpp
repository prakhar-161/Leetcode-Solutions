class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(auto sentence : sentences) { 
            int count = 0;
            for(auto word : sentence) {
                if(word == ' ') {
                    count++;
                }
            }
            maxi = max(maxi, count+1);
        }
        return maxi;
    }
};

