#include<bits/stdc++.h>
/**/

using namespace std;

long long int solve(string S, string P){
	if( S.length() == 1 ){
		if( S[0] == 'a' ){
			return P[0] - '0';
		}
		if( S[0] == 'b' ){
			return P[1] - '0';
		}
		if( S[0] == 'c' ){
			return P[2] - '0';
		}
		if( S[0] == 'd' ){
			return P[3] - '0';
		}
	} else{
		vector<	string> hash(3);
		long long int idx = 0;
		long long int len = 0;
		for( size_t i = 2; i < S.size(); i++ ){
			hash[idx].push_back(S[i]);
			if( S[i] == '[' ){
				len++;
			} else if( S[i] == ']' ){
				len--;
			}
			if( len == 0 ){
				idx++;
			}
		}
		long long int ret1 = solve(hash[0], P);
		long long int ret2 = solve(hash[1], P);
		if( S[1] == '+' ){
			return ret1 | ret2;
		} else if( S[1] == '*' ){
			return ret1 & ret2;
		} else{
			return ret1 ^ ret2;
		}
	}
}

int main(){
	string S;
	while( cin >> S, S != "." ){
		string P;
		cin >> P;
		long long int hash = solve(S, P);
		long long int count = 0;
		for( long long int i = 0; i <= 9999; i++ ){
			stringstream SS;
			SS << setfill('0') << setw(4) << i;
			string nowS;
			SS >> nowS;
			if( solve(S, nowS) == hash ){
				count++;
			}
		}
		cout << hash << " " << count << endl;
	}
}
