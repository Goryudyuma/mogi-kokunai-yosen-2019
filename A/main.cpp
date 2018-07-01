#include<bits/stdc++.h>
/**/

using namespace std;

int main(){
	string S;
	while( cin>>S,S=="HEISEI" ){
		long long int y, m, d;
		cin >> y >> m >> d;
		if( y>31||(y==31&&m>4)||(y==31&&y==4&&d>30) ){
			cout << "? " << y - 30 << " " << m << " " << d << endl;
		} else{
			cout << "HEISEI" << " " << y << " " << m << " " << d << endl;
		}
	}
}
