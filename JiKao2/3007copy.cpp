#include <iostream>
#include <cstdio>

using namespace std;
struct S{
	char *data;
	int size;
	S(){
		data = new char[50];
		size = 0;
	}
	S(char* src, int _size){
		data = new char[50];
		size = _size;
		for(int i = 0; i < size; i++){
			data[i] = src[i];
		}
	}
	S(char* src){
		data = new char[50];
		for(int i = 0; ('a' <= src[i] && src[i] <= 'z'); i++){
			data[i] = src[i];
		}
	}
	void insert(char c){
		if('a' <= c && c <= 'z'){
			data[size] = c;
			size++;
		}
	}
	void print(){
		for(int i = 0; i < size; i++)
			cout << data[i];
	}
	void buildsz(){
		size = 0;
		for(int i = 0; i < 50; i++){
			if('a' <= data[i] && data[i] <= 'z')
				size++;
			else
				break;
		}
	}

};


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

S sq, sz;

inline void solve(S s1, S s2, int x){
  
//  cout << x << '\n';
//  s1.print();
//  cout << endl;
//  s2.print();
//  cout << endl;

  T[x].v = s1.data[0];
  if(s1.size == 1){
    return;
  }
  char tmp = s1.data[0];
  S ls1, ls2, rs1, rs2;
  for(int i = 0; i < s2.size; i++){
    if(s2.data[i] == tmp){
      i++;
      while(i < s2.size){
        rs1.insert(s1.data[i]);
        rs2.insert(s2.data[i]);
        i++;
      }
      break;
    }

    ls1.insert(s1.data[i + 1]);
    ls2.insert(s2.data[i]);
  }
  if(ls1.size > 0)
    solve(ls1, ls2, x + x);
  if(rs1.size > 0)
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
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);

	freopen("3007.in", "r", stdin);
	freopen("3007.out", "w", stdout);
	
 	T[1].F = 0;
 	char *sq1 = new char[50];
 	char *sz1 = new char[50];
	cin >> sq1 >> sz1;

	S sq(sq1), sz(sz1);
	sq.buildsz();
	sz.buildsz();

  solve(sq, sz, 1);
 

  for(int i = 1; i <= 10000; i++){
      T[i].L = i + i;
      T[i].R = i + i + 1;
  }

  print(1);

	return 0;
}
