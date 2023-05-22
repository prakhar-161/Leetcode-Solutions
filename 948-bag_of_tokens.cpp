class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // score, i, j
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size()-1, score = 0, maxscore = 0;
        while(i<=j) {
            if(power >= tokens[i]) {
                power -= tokens[i];
                score += 1;
                maxscore = max(maxscore, score);
                i += 1;
            }
            else if(score >= 1) {
                power += tokens[j];
                score -= 1;
                j -= 1;
            } 
            else {
                break;
            }
        }
        return maxscore;
    }
};