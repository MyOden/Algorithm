// ARC032 B
// Use Union Find 

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using P = pair<int,int>;
typedef long long ll;

const int nmax=100010;
const int alone = -1; 
int N,M;
int uni[nmax];
 
int n, m;

int uni_root(int n){
    int rootnode;
    if (uni[n]<0) return n;
    rootnode = uni_root(uni[n]);
    if (rootnode != uni[n]) { uni[n] = rootnode;}
    return rootnode; 
}
void union_link(int a, int b){
    int roota,rootb;
    roota = uni_root(a);
    rootb = uni_root(b);
    if (roota == rootb ){
        return;
    } else if (rootb > roota ){
        uni[roota] += uni[rootb];
        uni[rootb] = roota;
    } else {
        uni[rootb] += uni[roota];
        uni[roota] = rootb;
    }

}

int main() {
    int i,j; 
    int a,b;
    int ans=0;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m ;
    rep(i,n) uni[i]= alone;

    rep(i,m){
        cin >> a >> b;
        union_link(a,b);
    }
    ans = 0;
    rep(i,n){
        if (uni[i] < 0){
            ans ++;
        }
    }
    cout << ans -1 << endl;
        
}


