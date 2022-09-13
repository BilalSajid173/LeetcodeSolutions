class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        for(int i = 0;i<data.size();i++){
            if(data[i] < 128) continue;
            else if(data[i] >=128 && data[i] < 192) return false;
            else if(data[i] >= 192 && data[i] < 224){
                if(data[i+1] >=128 && data[i+1] < 192){
                    i++;
                    continue;
                }
                else return false;
            }
            else if(data[i] >= 224 && data[i] < 240){
                if(data.size() - i >= 2){
                    for(int j = i+1;j<=i+2;j++){
                    if(data[j] < 128 || data[j] >= 192) return false;
                }
                i+=2;
                } else return false;
            }
            else if(data[i] >= 240 && data[i] < 248){
                if(data.size() - i >= 3){
                    for(int j = i+1;j<=i+3;j++){
                    if(data[j] < 128 || data[j] >= 192) return false;
                }
                i+=3;
                } else return false;
            } else return false;
        }
        return true;
    }
};