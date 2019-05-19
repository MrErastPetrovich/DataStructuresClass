#include <bits/stdc++.h>

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
		data[size] = c;
		size++;
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

void solve(S x1, S x2, int x){
	x1.print();
	
	
}


int main(){
	char *s1, *s2 = new char[50];
	cin >> s1 >> s2;

	S a(s1), b(s2);
	a.buildsz();
	b.buildsz();

   	a.print();
   	cout << endl;
   	a.insert(b.data[0]);
	
	solve(a, b, 1);


	return 0;
}
