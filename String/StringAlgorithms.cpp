#include <iostream>
#include <vector>
using namespace std;

vector<int> MP(string S){
  int l = S.length();
  vector<int> A(l+1);
  A[0] = -1;
  int j = -1;
  for(int i = 0; i < l; ++i){
    while(j >= 0 && S[i] != S[j]) j = A[j];
    ++j;
    A[i+1] = j;
  }
  return A;
}

vector<int> KMP(string S){
  int l = S.length();
  vector<int> A(l+1);
  A[0] = -1;
  int j = -1;
  for(int i = 0; i < l; ++i){
    while(j >= 0 && S[i] != S[j]) j = A[j];
    ++j;
    if(i < l && S[i+1] == S[j]) A[i+1] = A[j];
    else A[i+1] = j;
  }
  return A;
}

vector<int> Manacher(string S){
  int c = 0, n = S.length();
  vector<int> R(n,1);
  for(int i = 0; i < n; ++i){
    int l = c - (i - c);
    if(i + R[l] < c + R[c]){
      R[i] = R[l];
    }else{
      int j = c + R[c] - i;
      while(i - j >= 0 and i + j < n and S[i-j] == S[i+j]) ++j;
      R[i] = j;
      c = i;
    }
  }
  return R;
}

vector<int> Z_algorithm(string S){
  int c = 0, n = S.length();
  vector<int> Z(n,0);
  for(int i = 1; i < n; ++i){
    int l = i - c;
    if(i + Z[l] < c + Z[c]){
      Z[i] = Z[l];
    }else{
      int j = max(0, c + Z[c] - i);
      while(i + j < n && S[j] == S[i+j]) ++j;
      Z[i] = j;
      c = i;
    }
  }
  Z[0] = n;
  return Z;
}

int main(){
  string S;
  cin >> S;
  vector<int> mp = MP(S), kmp = KMP(S), manacher = Manacher(S), Z = Z_algorithm(S);
  cout << "MP" << endl;
  for(auto &x : mp) cout << x << " ";cout << endl;
  cout << "KMP" << endl;
  for(auto &x : kmp) cout << x << " ";cout << endl;
  cout << "Manacher" << endl;
  for(auto &x : manacher) cout << x << " ";cout << endl;
  cout << "Z-algorithm" << endl;
  for(auto &x : Z) cout << x << " ";cout << endl;
  return 0;
}
