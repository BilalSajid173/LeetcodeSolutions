class Solution {
public:
    int maximumSwap(int num) {
        string x = to_string(num);
        for(int i = 0;i<x.length();i++){
            if((int)x[i] - '0' != 9){
                int k = i;
                for(int j = i + 1;j< x.length();j++){
                    if((int)x[j] >= (int)x[k] && (int)x[j] != (int)x[i]){
                        k = j;
                    }
                }
                if(k!= i){
                        swap(x[i],x[k]);
                        return stoi(x);
                }
            }
        }
        return num;
    }
};