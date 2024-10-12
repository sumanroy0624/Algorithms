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

    for (int i = 0; i < len; i++) {
        hash = (hash * p + (s[i] - 'a' + 1)) % mod;
        if (i < len - 1) pow = (pow * p) % mod; 
    }
    unordered_map<ll, vector<ll>> mp;
    mp[hash].push_back(0);

    ll sp = 0;
    for (ll ep = len; ep < s.size(); ep++) {
        hash = (hash - (s[sp] - 'a' + 1) * pow % mod + mod) % mod; 
        hash = (hash * p + (s[ep] - 'a' + 1)) % mod; 
        sp++;
        if (mp.find(hash) != mp.end()) {
            for (auto index : mp[hash]) {
                if (s.substr(index, len) == s.substr(sp, len)) {
                    return s.substr(sp, len);
                }
            }
        }
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
