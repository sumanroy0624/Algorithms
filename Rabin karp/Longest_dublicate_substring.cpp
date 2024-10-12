/*

Problem Link: https://leetcode.com/problems/longest-duplicate-substring/
Reference Video : https://youtu.be/dcOSQjhfBcQ?si=-mRjlxVe5wzG_5QU

*/
#define ll long long
ll mod=1e9+7;
class Solution {
public:
   string f(string &s, ll len) {
	ll p = 31;
	ll pow = 1;
	ll hash = 0;
	for (int i = len - 1; i >= 0; i--) {
		hash = (hash + (s[i] - 'a' + 1) * pow) % mod;
		if (i > 0)pow = (pow * p) % mod;
	}
	ll sp = 0;
	ll ep = len;
	unordered_map<int, vector<int>>mp;
	mp[hash].push_back(0);
	while (ep < s.size()) {
		hash = ((hash - (s[sp] - 'a' + 1) * pow) % mod + mod) % mod;
		hash = (hash * p) % mod;
		hash = (hash + (s[ep] - 'a' + 1)) % mod;
		sp++;
		for (auto it : mp[hash]) {
			if (s.substr(it, len) == s.substr(sp, len)) {
				return s.substr(sp, len);
			}
		}
		ep++;
		mp[hash].push_back(sp);
	}
	return "-1";
}


string longestDupSubstring(string s) {
	ll n = s.size();
	ll l = 0;
	ll r = n;
	string ans = "";
	while (l <= r) {
		ll mid = (l + r) >> 1;
		string str = f(s, mid);
		if (str != "-1") {
			ans = str;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}
};
