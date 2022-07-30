class Solution {
public:
    string addBinary(string a, string b)
    {
        string s = ""; //result string
        
        int c = 0, i = a.size() - 1, j = b.size() - 1; //c=carry, i=last index of string a, j=last index of string b
        while(i >= 0 || j >= 0 || c == 1)  // i==0 || j==0 means run loop till we cover both strings completely and c==1 states even if we covered both strings but carry still remains
        {
            c += i >= 0 ? a[i --] - '0' : 0; // carry=carry+ int value of a[i] (subtracting ascii value of '0' from a[i] gives integer value of carry)
            c += j >= 0 ? b[j --] - '0' : 0; // carry=carry + int value of b[j]
            s = char(c % 2 + '0') + s;  //  c%2 means insert 0 if carry==0  or carry==2 (1+1) because ('1'+'1'=0 in binary) else insert 1 ('0'+'1'=1). Adding '0' to convert in ascii from integer 
            c /= 2; //if c==2 or 3, there is a carry i.e 1 otherwise no carry (3 in case if prev c=1 and a[i]=1 and b[i]=1)
        }
        // no need to reverse the string since we have inserted new characters at the beginning not end.
        return s;
    }
};