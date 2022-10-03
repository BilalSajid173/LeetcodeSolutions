class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalCost = 0, curSum = neededTime[0], maxVal = neededTime[0];
        for(int i = 1;i < colors.size();i++){
            if(colors[i] == colors[i-1]){
                curSum += neededTime[i];
                maxVal = max(maxVal, neededTime[i]);
            } else {
                curSum -= maxVal;
                totalCost += curSum;
                curSum = neededTime[i];
                maxVal = neededTime[i];
            }
        }
        return totalCost + (curSum - maxVal);
    }
};