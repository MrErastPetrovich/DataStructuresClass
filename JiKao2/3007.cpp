#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct node{
  int L;
  int R;
  int F;
  char v = '1';
  node(int l = 0, int r = 0, int f = -1){
    L = l, R = r, F = f;
  }
};
node T[511111];

string sq, sz;

int cnt = 1;

inline void solve(string s1, string s2, int x){
  cout << x << endl;
  cout << s1 << " " << s2 << endl;
  //cout << ls1 << " " << ls2 << endl;
  //cout << rs1 << " " << rs2 << endl;
  cout << "_____" << endl;

  T[x].v = s1[0];
  if(s1.size() == 1){
    return;
  }
  char tmp = s1[0];
  string ls1, ls2, rs1, rs2;
  for(int i = 0; i < s2.size(); i++){
    if(s2[i] == tmp){
      i++;
      while(i < s2.size()){
        rs1 += s1[i];
        rs2 += s2[i];
        i++;
      }
      break;
    }

    ls1 += s1[i + 1];
    ls2 += s2[i];
  }
  if(ls1.size() > 0)
    solve(ls1, ls2, x + x);
  if(rs1.size() > 0)
    solve(rs1, rs2, x + x + 1);
}

inline void print(int x){
  if(T[x].v == '1')
    return;
  print(T[x].L);
  print(T[x].R);
  cout << T[x].v;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("3007.in", "r", stdin);
	freopen("3007.out", "w", stdout);

  T[1].F = 0;

  cin >> sq >> sz;
  solve(sq, sz, 1);

  for(int i = 1; i <= 10000; i++){
      T[i].L = i + i;
      T[i].R = i + i + 1;
  }

  print(1);

	return 0;
}
