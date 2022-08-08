class Solution {
public:
    int count(string s, int i, string t, int j, vector<vector<int>>& cnt) {
	if (j == 0) cnt[i][j] = 1;
	else if (i < j || i == 0) cnt[i][j] = 0; 
	if (cnt[i][j] >= 0) return cnt[i][j];

	cnt[i][j] = count(s, i-1, t, j, cnt) + (s[i-1] == t[j-1] ? count(s, i-1, t, j-1, cnt) : 0);
	return cnt[i][j];
}

int numDistinct(string s, string t) {
	int m = s.size(), n = t.size();
	vector<vector<int>> cnt(m+1, vector<int>(n+1, -1));
	return count(s, m, t, n, cnt);
}
};