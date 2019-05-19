#include <bits/stdc++.h>

using namespace std;

class myheap{
  private:
    long long* A;
    int heapsize;
    void build();
  public:
    myheap(int* src, int size);
    myheap();
    void minheapify(int i);
    long long getmin();
    long long popmin();
    void heapsort();
    void decreasekey(int i, int x, bool flag);
    void insert(int x);
    long long find(int x);
};


void myheap::build(){
  for(int i = heapsize/2; i >= 1; i--){
    minheapify(i);
  }
}

myheap::myheap(int* src, int size){
  A = new long long[111111];
  heapsize = 0;
  for(int i = 1; i <= size; i++){
    A[i] = src[i-1], heapsize++;
  }
  build();
}

myheap::myheap(){
  A = new long long[111111];
  heapsize = 0;
}

void myheap::minheapify(int i){
  int l = i + i;
  int r = i + i + 1;
  int smallest;
  if(l <= heapsize && A[l] < A[i]){
    smallest = l;
  }
  else{
    smallest = i;
  }
  if(r <= heapsize && A[r] < A[smallest]){
    smallest = r;
  }

  if(smallest != i){
    int tmp = A[i];
    A[i] = A[smallest];
    A[smallest] = tmp;
    minheapify(smallest);
  }
}

long long myheap::getmin(){
	return A[1];
}

long long myheap::popmin(){
  if (heapsize < 1)
    return 0;
  int rslt = A[1];
  A[1] = A[heapsize];
  heapsize = heapsize - 1;
  minheapify(1);
  return rslt;
}

void myheap::heapsort(){
  int tmp, ln = heapsize;
  for(int i = heapsize; i >= 2; i--){
    tmp = A[1], A[1] = A[i], A[i] = tmp;
    heapsize--;
    minheapify(1);
  }
}

void myheap::decreasekey(int i, int x, bool flag){
  //if(x > A[i])
    //throw "error";
  if(flag == 0)
    A[i] = x;
  else
    A[i] -= x;

  int tmp;
  while(i > 1 && A[i/2] > A[i]){
    tmp = A[i/2], A[i/2] = A[i], A[i] = tmp;
    i = i/2;
  }
}

void myheap::insert(int x){
  heapsize++;
  A[heapsize] = 3e9;
  decreasekey(heapsize, x, 0);
}

long long myheap::find(int x){
  int ans = 0;
  A[0] = 3e9;
  for(int i = 1; i <= heapsize; i++){
    if(A[i] > x && A[i] < A[ans]){
      ans = i;
    }
  }
  return ans;
}

int T, n, p, x, a[111111];
string s;
long long ans, k;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  myheap X;
  cin >> n;
  for(int i = 1; i <= n; i++){
  	cin >> a[i];
  	X.insert(a[i]);
  }

  for(int i = 1; i < n; i++){
  	k = X.popmin() + X.popmin();
	ans += k;
	X.insert(k);
  }

  cout << ans;

  return 0;
}
