class Solution {
public:
    static bool compare(vector<int> v1, vector<int> v2){
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int i = 0;
        int sum = 0;
        while(truckSize > 0 && i < boxTypes.size()){
            if(truckSize > boxTypes[i][0]){
                sum += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            } else {
                sum += truckSize* boxTypes[i][1];
                truckSize = 0;
            }
            i++;
        }
        return sum;
    }
};