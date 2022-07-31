class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if( n== 0){
            return true;
        }
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0){
                n--;
            }
            return n==0;
        }
        
        
        for(int i = 0; i < flowerbed.size(); i++){
            if(i == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            if(i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            if(i != 0 && i != flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0){
                flowerbed[i] = 1;
                n--;
            }
            if(n==0){
                break;
            }
        }
        return n==0;
    }
};