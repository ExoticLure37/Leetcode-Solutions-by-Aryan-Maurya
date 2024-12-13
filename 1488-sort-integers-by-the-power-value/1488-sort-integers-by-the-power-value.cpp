class Solution {
public:
	int getKth(int lo, int hi, int k) {
		vector<pair<int, int>>v;
		for (int i = lo; i <= hi; i++)
		{
			int ans = 0;
			int x = i;
			while (x != 1)
			{
				if (x % 2)
				{
					x = 3 * x + 1;
				}
				else
				{
					x = x / 2;
				}
				ans++;
			}
			v.push_back({ans, i});
		}
		sort(v.begin(), v.end());
		return v[k - 1].second;
	}
};