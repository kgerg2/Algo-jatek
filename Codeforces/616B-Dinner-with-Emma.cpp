#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n, m, i, j;
    cin >> n >> m;
    int l[n][m], l2[m];
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> l[i][j];
        }
    }
    for(i=0; i<n; i++){
        l2[i] = *min_element(l[i], l[i] + m);
    }
    cout << *max_element(l2, l2 + n);
    return 0;
}