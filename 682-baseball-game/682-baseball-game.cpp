class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i = 0;i<ops.size();i++){
            if(ops[i] == "+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.push(x);
                s.push(x+y);
            } else if(ops[i] == "D"){
                int x = s.top();
                s.push(2*x);
            } else if(ops[i] == "C"){
                s.pop();
            } else {
                int x = stoi(ops[i]);
                s.push(x);
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};