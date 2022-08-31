class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        for(int i = 0;i<path.length();i++){
            if(path[i] != '/'){
                int x = i;
                while(i<path.length() && path[i] != '/'){
                    i++;
                }
                string str = path.substr(x,i-x);
                if(str == ".." && !s.empty()) s.pop();
                else if(str != "." && str != ".."){
                    s.push(str);
                }
            }
        }
        if(s.empty()){
            return "/";
        }
        string ans = "";
        while(!s.empty()){
            string x = s.top();
            s.pop();
            ans = "/" + x + ans;
        }
        return ans;
    }
};