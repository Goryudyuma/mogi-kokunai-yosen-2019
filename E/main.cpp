#include<bits/stdc++.h>
/**/

using namespace std;

vector<vector<long long int>>D;
map<set<long long int>, long long int>memo;

long long int anslet = 0;

long long int solve(set<long long int>S, long long int used, long long int m){
	if( S.size() == 0 ){
		anslet = max(anslet, ( long long int )used);
		return used;
	}
	if( ( S.size() + used ) / 2 * 2 <= anslet ){
		return 0;
	}
	if( memo.count(S) ){
		return memo[S] + used;
	}
	long long int ret = 0;
	auto Scp = S;
	for( auto s : S ){
		if( s <= m ){
			continue;
		}
		Scp.erase(s);
		auto Scpcp = Scp;
		for( auto d : D[s] ){
			Scp.erase(d);
		}
		ret = max(ret, solve(Scp, used + 1, s));
		Scp = Scpcp;
	}
	return memo[S] = ret;
}

int main(){
	long long int N, M;
	while( cin >> N >> M, N || M ){
		anslet = 0;
		memo.clear();
		cerr << N << " " << M << endl;
		D = vector<vector<long long int>>(N);
		for( size_t i = 0; i < M; i++ ){
			long long int u, v;
			cin >> u >> v;
			u--; v--;
			D[u].push_back(v);
		}
		set<long long int>S;
		for( size_t i = 0; i < N; i++ ){
			S.insert(i);
		}
		long long int ans = solve(S, 0, -1) / 2;
		cout << ans << endl;
		for( size_t i = 1; i <= ans; i++ ){
			cout << i << endl;
		}
	}
}
