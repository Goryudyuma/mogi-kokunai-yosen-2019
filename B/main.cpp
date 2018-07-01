#include<bits/stdc++.h>
/**/

using namespace std;

int main(){
	long long int n, l, r;
	while( cin >> n >> l >> r, n || l || r ){
		vector<long long int>A(n);
		for( size_t i = 0; i < n; i++ ){
			cin >> A[i];
		}
		A.push_back(1);
		long long int ans = 0;
		for( long long int x = l; x <= r; x++ ){
			for( size_t i = 0; i <= n; i++ ){
				if( x%A[i] == 0 ){
					if( i % 2 == 0 ){
						ans++;
					}
					break;
				}
			}
		}
		cout << ans << endl;
	}
}
