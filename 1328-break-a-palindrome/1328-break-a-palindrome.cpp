class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() == 1) return "";
        for (int i = 0;i<palindrome.size();i++){
            if(palindrome[i] != 'a' && (i != palindrome.size()/2)){
                palindrome[i] = 'a';
                return palindrome;
            } else if(palindrome[i] != 'a' && (i == palindrome.size()/2)){
                break;
            }
        }
        int len = palindrome.size();
        palindrome[len-1] = 'b';
        return palindrome;
    }
};