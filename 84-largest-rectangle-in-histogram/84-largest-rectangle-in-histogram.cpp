class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int max_area = 0, cur_max = 0;
        stack<int> s;
        int n = heights.size();
        int i = 0;
        while(i < n){
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i++);
            } else {
                int tp = heights[s.top()];
                s.pop();
                cur_max = tp*(s.empty()? i : i - s.top() - 1);
                max_area = max(cur_max, max_area);
            }
        }
        while(!s.empty()){
            int tp = heights[s.top()];
                s.pop();
                cur_max = tp*(s.empty()?i : i - s.top() - 1);
                max_area = max(cur_max, max_area);
        }
        return max_area;
    }
};