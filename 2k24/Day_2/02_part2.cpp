#include <bits/stdc++.h>
using namespace std;

bool isOK(vector<int>a ) {
   int n = (int)a.size() ;
  bool ok = true ;
  bool inc = true ;
  bool dec = true ;
 int diff = 0 ;
 for(int i = 0  ; i< n-1 ; i++){
     diff = a[i] - a[i+1] ;
     if(diff < 0 ) inc = false ;
     if(diff > 0) dec = false ;
     if( 1 > abs(diff) || abs(diff) > 3) ok = false ;
  }

  return ok && (inc || dec) ;
}
int main() {

  int cnt = 0;
  int N = 1000;
  while(N--) {
    vector<int> a;

    while (true) {
      int x;
      scanf("%d", &x);
      a.push_back(x);
      char c;
      scanf("%c", &c);
      if (c == '\n')
        break;
    }
    bool anyOK = false ;
    auto consider = [&](int i ){
        vector<int> b = a ;
        b.erase(b.begin() + i);
        if(isOK(b))anyOK = true;

    };
    int n = (int)a.size() ;
    consider(0);
    int diff = 0 ;
    for(int i = 0 ; i < n - 1 ; i++ ){
        diff = a[i] - a[i+1] ;
        if(1> abs(diff) || 3 < abs(diff)){
            consider(i) ;
            consider(i+1) ;
            break ;
        }
        if(i+2 < n) {
            int diff2 = a[i+1] - a[i+2] ;
            if((diff > 0) != (diff2 > 0)){
                consider(i);
                consider(i+1);
                consider(i+2);
                break ;
            }
        }
    }

    if(anyOK) cnt+=1 ;

  }

  cout << cnt << '\n';

  return 0;
}
