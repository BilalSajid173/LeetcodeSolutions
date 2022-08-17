class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s;
        string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto word:words){
            string x = "";
            for(int i = 0;i<word.length();i++){
                x += arr[word[i] - 'a'];
            }
            s.insert(x);
        }
        return s.size();
    }
};