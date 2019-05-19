#include <iostream>
 
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	//freopen("a.in", r, stdin);
	//freopen("a.out", "w", stdout);
 
	int n, m, k, ans = -1;
	cin >> n >> m >> k;
	for(int round = k; round > 0; --round){
		ans = (ans + m) % (n - round + 1);
	}
	cout << ans + 1;
 
 
 
 
 
 
 
	return 0;
}