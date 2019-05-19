#include <iostream>
#include <cstdio>
#include <cstring> 
 
using namespace std;
 
template <class T>
class stck{
	private:
		T* data;
		int crntsz;
		int mxsz;
		void doubleSpace();
	public:
		stck();
		//~stck();
		bool empty() const;
		void pop();
		T top() const;
		void push(const T &src);
		int size() const;
};
 
 
template <class T>
void stck<T>::doubleSpace()
{
	T* tmp = new T[mxsz*2];
	for(int i = 1; i <= crntsz; i++){
		tmp[i-1] = data[i-1];
	}
	delete data;
	data = tmp;
}
 
template <class T>
stck<T>::stck()
{
	crntsz = 0;
	mxsz = 500000;
	data = new T[mxsz];
}
 
template <class T>
bool stck<T>::empty() const
{
	return (crntsz == 0);
}
 
template <class T>
void stck<T>::pop()
{
	if(empty() == 0){
		crntsz--;
    }
}
 
template <class T>
T stck<T>::top() const
{
	if(empty() == 0){
		return data[crntsz-1];
    }
}
 
template <class T>
void stck<T>::push(const T &src)
{
	if(crntsz > mxsz)
		doubleSpace();
	data[crntsz] = src;
	crntsz++;
}
 
template <class T>
int stck<T>::size() const
{
	return crntsz;
}
 
int n, a[1111], cur, used[1111];
stck <int> C;
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	//freopen("4161.in", r, stdin);
	//freopen("4161.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		used[a[i]]++;
		if(used[a[i]] > 1 || (a[i] > n || a[i] < 0)){
			cout << "No";
			return 0;
		}
	}
 
	cur = 1;
	for(int i = 1; i <= n; i++){
		
		if(!C.empty() && C.top() == a[i]){
			C.pop();
		}
		else{
			while(cur != a[i]){
				C.push(cur);
				cur++;
				if(cur > n ){
					cout << "No";
					return 0;
				}
			}
			cur++;
		}
	}
 
	cout << "Yes";
 
	return 0;
}