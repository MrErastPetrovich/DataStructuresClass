#include <iostream>
#include <cstdio>
#include <cstring> 
 
using namespace std;

template <class TF, class TS>
struct pairr{
	TF first;
	TS second;
};

int T, cnt = 0, uc = 0, x;
pairr <int, pairr<int, int> > a[100101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("1038.in", "r", stdin);
	//freopen("1038.out", "w", stdout);

	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		a[i].first = i;
		a[i].second.first = i-1;
		a[i].second.second = i+1;
	}

	a[T].second.second = 1;
	a[1].second.first = T;
	if(T == 2)
	{
		cout << a[2].first;
		return 0;
	}

	    cin >> x;
	    x = x % T;
	    if(!x) x = T;
	//for(int j = 1; j < T; j++){
		for(int i = 1; ;)
		{
			cnt++;
			if(cnt == x)
			{
				cnt = 0;
				a[a[i].second.first].second.second = a[i].second.second;
				a[a[i].second.second].second.first =  a[i].second.first;
				uc++;
				if(uc == T - 1)
				{
					cout << a[a[i].second.second].first;
					break;
				}
				cin >> x;
				x = x % (T - uc);
				if(!x) x = T - uc;
			}
			i = a[i].second.second;
		}		
	//}

	return 0;
}
