#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

vector <int> times;
vector <vector <int> > graph;

array <long long, 1001> cache;

long long dp(int dest){
	
	if(graph[dest].empty()){
		return times[dest];
	}
	
	long long &ret = cache[dest];
	
	if(ret != -1){
		return ret;
	}
	
	ret = 0;
	
	for(auto v : graph[dest]){
		ret = max(ret, dp(v));
	}
	
	return ret += times[dest];
	
}

int main(){
	
	int t= 0;
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		
		int n = 0;
		int k = 0;
		
		scanf("%d %d", &n, &k);
		
		times.clear();
		times = vector<int>(n+1, 0);
		
		graph.clear();
		graph = vector< vector<int> >(n+1);
		
		cache.fill(-1);
		
	for(int j=1; j<=n; j++){
		scanf("%d", &times[j]);
	}
	
	for(int j=0; j<k; j++){
		
		int x = 0;
		int y = 0;
		
		scanf("%d %d", &x, &y);
		
		graph[y].push_back(x);
	}
		
		int dest = 0;
		
	scanf("%d", &dest);
		
		printf("%lld\n", dp(dest));
		
	}
	
	return 0;
}