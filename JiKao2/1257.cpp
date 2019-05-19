#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
  int L;
  int R;
  int F;
  node(int l = 0, int r = 0, int f = -1){
    L = l, R = r, F = f;
  }
};

node T[511111];

int m, t, f, l, r, x;

inline void print(int x){
  if(x == 0)
    return;

  cout << x << " ";
  print(T[x].L);
  print(T[x].R);

  return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("1038.in", "r", stdin);
	//freopen("1038.out", "w", stdout);


	cin >> m;
  T[1].F = 0;
  for(int i = 1; i <= m; i++){
    cin >> t;
    if(t == 1){
      cin >> f >> l >> r;
      if((T[f].F == -1) || (T[f].L != 0 && T[f].R != 0) || (T[l].F != -1) || (T[r].F != -1) || (l == r)){
        cout << "Error!" << '\n';
        continue;
      }
      T[f].L = l;
      T[f].R = r;
      T[l].F = f;
      T[r].F = f;
      cout << "Ok!" << '\n';
    }
    if(t == 2){
      cin >> x;
      if(T[x].F == -1){
        cout << "Error!" << '\n';
        continue;
      }
      cout << T[x].F << " " << T[x].L << " " << T[x].R << '\n';
    }
    if(t == 3){
      cin >> x;
      if(x == 1 || T[x].F == -1){
        cout << "Error!" << '\n';
        continue;
      }
      l = T[T[x].F].L;
      r = T[T[x].F].R;
      T[T[x].F].L = r;
      T[T[x].F].R = l;
      if(x != l)
        cout << l << '\n';
      else
        cout << r << '\n';
    }
  }

  print(1);

	return 0;
}
