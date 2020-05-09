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
int uni[nmax]; // if the value is less than 0, node i is a root node, and -uni[i] is the number of node conneced to node[i] including itsself. 
 
int n, m;

// uni_root(n) returns the index of the root node of the node n. 
int uni_root(int n){
    int rootnode;
    if (uni[n]<0) return n;
    rootnode = uni_root(uni[n]);
    // if it found the update of root node, update uni[n]
    // by doing this, the next call returns without deeep recursive search.
    if (rootnode != uni[n]) { uni[n] = rootnode;}
    return rootnode; 
}

// set node a and node b to be the same group. 
// the younger root node of node a and node b  will be the root node of the unified group. 
// * 'younger' means having a smaller node number. 
void union_link(int a, int b){
    int roota,rootb;
    roota = uni_root(a);
    rootb = uni_root(b);
    if (roota == rootb ){
        // if the nodes belong to the same group originally, we have nothing to do. 
        return;
    } else if (rootb > roota ){
        // the root node of the node a become the root node of the node group which the node b belonged to. 
        // we do not update whole uni[x] of nodes which belonged to the node group whose root node was the node rootb.
        uni[roota] += uni[rootb];
        uni[rootb] = roota;
    } else {
        // the root node of the node b become the root node of the node group which the node a belonged to.
        // we do not update whole uni[x] of nodes which belonged to the node group whose root node was the node roota.
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


