class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int j = tokens.size() - 1;
        int score = 0, maxscore = 0;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                i++;
                score++;
                maxscore = max(maxscore,score);
            } else if(power < tokens[i] && score > 0){
                power += tokens[j];
                j--;
                score--;
            } else {
                return 0;
            }
        }
        return maxscore;
    }
};