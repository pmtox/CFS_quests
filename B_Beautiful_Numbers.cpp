#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
void solve(){
	ll X;
	cin >> X;
	vector<int> digits;
	ll s = 0;
	while(X > 0){
		digits.push_back(X % 10);
		s += X % 10;
		X /= 10;
	}
	digits.back() -= 1;
	sort(digits.rbegin(), digits.rend());
	s -= 9;
	int ans = 0;
	for(int d : digits){
		if(s > 0){
			s -= d;
			ans += 1;
		}
	}
	cout << ans << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}