/*
Prolem Link-> https://www.spoj.com/problems/NAJPF/
Reference Video -> https://youtu.be/gNDIOqdAJiw?si=HAsVxART54YUT0d0
*/

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	ll mod = 1e9 + 7;
	ll p = 31;
	ll pow = 31;
	ll sum = s2[0] - 'a' + 1;
	for (int i = 1; i < s2.size(); i++) {
		sum = (sum + (s2[i] - 'a' + 1) * pow) % mod;
		pow = (pow * p) % mod;
	}
	ll n = s1.size();
	vector<ll>powers(n);
	vector<ll>pref(n);
	powers[0] = 1;
	pref[0] = s1[0] - 'a' + 1;
	pow = p;
	for (int i = 1; i < n; i++) {
		pref[i] = (pref[i - 1] + (s1[i] - 'a' + 1) * pow) % mod;
		powers[i] = pow;
		pow = (pow * p) % mod;
	}
	ll sp = 0, ep = s2.size() - 1;
	vector<ll>ans;
	while (ep < s1.size()) {
		ll val = pref[ep];
		if (sp > 0) {
			val = (val - pref[sp - 1] + mod) % mod;
		}
		if (val == (sum * powers[sp]) % mod) {
			ans.push_back(sp + 1);
		}
		ep++;
		sp++;
	}
	if (!ans.size()) {
		cout << "Not Found" << endl;
		return;
	}
	cout << ans.size() << endl;
	pv(ans);


}
