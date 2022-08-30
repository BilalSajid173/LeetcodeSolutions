class Solution {
public:
    string convertToTitle(int columnNumber) {
        if(columnNumber <= 26){
            char ch = columnNumber + 'A' - 1;
            string s = "";
            s += ch;
            return s;
        }
        int rem = columnNumber % 26;
        int quotient = columnNumber / 26;
        char ch = 'A' + rem - 1;
        if(rem == 0) ch = 'Z';
        string s = "";
        s += ch;
        if(rem == 0) return convertToTitle(quotient - 1) + s;
        return convertToTitle(quotient) + s;
    }
};