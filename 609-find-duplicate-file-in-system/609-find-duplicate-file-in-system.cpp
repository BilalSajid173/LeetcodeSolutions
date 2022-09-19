class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;
        
        for(auto p:paths){
            string dir = "";
            string content = "";
            string filename = "";
            int k = 0;
            for(int i = 0;i<p.length();i++){
                if(p[i] != ' ' && k == 0){
                    dir += p[i];
                } else if(k == 0 && p[i] == ' '){
                    k = 1;
                }
                if(k == 1 && p[i] != ' '){
                    if(p[i] == '('){
                        while(p[i] != ')'){
                            i++;
                            content += p[i];
                        }
                        m[content].push_back(dir + "/" + filename);
                        content = "";
                        filename = "";
                    } else {
                        filename += p[i];
                    }
                }
            }
        }
        for(auto it = m.begin();it != m.end(); it++){
            if(it->second.size() > 1)
            ans.push_back(it->second);
        }
        return ans;
    }
};