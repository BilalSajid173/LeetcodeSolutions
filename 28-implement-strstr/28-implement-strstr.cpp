class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack.length() < needle.length()){
            return -1;
        }
        
        for(int i = 0; i <= haystack.length() - needle.length() ; i++){
            
            if(haystack[i] == needle[0]){
                int j = i;
                int k;
                for(k = 0; k<needle.length(); k++){
                    if(haystack[j] != needle[k]){
                        break;
                    }
                    j++;
                }
                if(k == needle.length()){
                    return i;
                }
            }
        }
        return -1;
    }
};