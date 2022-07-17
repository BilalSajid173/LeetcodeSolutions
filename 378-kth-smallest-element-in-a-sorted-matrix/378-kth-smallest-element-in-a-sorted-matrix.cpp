class Solution {
    
public:
    typedef pair<int, pair<int, int>> p;

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix[0].size();
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> x;
        for (int j = 0; j < n; j++)
        {
            x.push_back(0);
        }
        v.push_back(x);
    }
    int ans;
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({matrix[0][0], {0, 0}});
    while (k > 0)
    {
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        if ((i + 1) <= n - 1 && v[i + 1][j] == 0)
        {
            pq.push({matrix[i + 1][j], {i + 1, j}});
            v[i + 1][j] = 1;
        }
        if ((j + 1) <= n - 1 && v[i][j + 1] == 0)
        {
            pq.push({matrix[i][j + 1], {i, j + 1}});
            v[i][j + 1] = 1;
        }
        ans = pq.top().first;
        pq.pop();
        k--;
    }

    return ans;
}

};