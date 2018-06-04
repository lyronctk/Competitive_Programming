/*
 ID: lyronct1
 LANG: C++11
 TASK: fence6
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
#include <functional>
#define ll long long
#define pii pair<int, int>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct fence{
	int length;
	vector<int> nodes[2];
};

fence adj[100+5];
int N, dist[2][100+5];
int find(int edge, int target){
	for(int n : adj[edge].nodes[0])
		if(n == target)
			return 0;
	return 1;
}
int minCycle(int i){
	// printf("minCycle(%d)\n", i);
	fill(dist[0], dist[0]+100, INT_MAX); //[node#][edge#]
	fill(dist[1], dist[1]+100, INT_MAX);
	dist[0][i] = 0;

	int temp = adj[i].length;
	adj[i].length = -1; //delete edge

	   //< length , < edge# , node# > >   - note: second pair is reverse of dist
	pair<int, pii > p;
	pii x; int y, z; //second pair, next edge, which node of next edge
	priority_queue<pair<int,pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > q;
	q.push({0, {i, 0}});
	while(!q.empty()){
		p = q.top();
		// printf("at | { %d , {%d, %d} }\n", p.first, p.second.first, p.second.second);
		q.pop();
		x = p.second;
		for(int j=0; j<adj[x.first].nodes[x.second].size(); j++){
			y = adj[x.first].nodes[x.second][j];
			// printf("consider: %d\n", y);
			z = (find(y, x.first)+1)%2;
		  // printf("!find(%d, %d) = %d\n", y, x.first,z); 
			if(adj[y].length != -1 && p.first + adj[y].length < dist[z][y]){
				dist[z][y] = p.first + adj[y].length;
				for(int k=0; k<adj[y].nodes[z].size(); k++)
					dist[find(adj[y].nodes[z][k], y)][adj[y].nodes[z][k]] = dist[z][y];
				// printf("push {%d, {%d, %d}}\n", dist[z][y], y, z);
				q.push({dist[z][y], {y, z}});
			}
		}
		// printf("   *\n");
	}
	adj[i].length = temp;
	// printf("^ %d ^-----\n", dist[1][i]+adj[i].length);
	if(dist[1][i] == INT_MAX) return INT_MAX;
	return dist[1][i]+adj[i].length;
}
int main(){
  // freopen("in.txt", "r", stdin);

  freopen("fence6.in", "r", stdin);
  freopen("fence6.out", "w", stdout);
  
  scanf("%d", &N);
  for(int i=1; i<=N; i++){
  	int S, L, N1, N2, num;
  	scanf("%d %d %d %d", &S, &L, &N1, &N2);

  	adj[S].length = L;
  	for(int j=0; j<N1; j++){
  		scanf("%d", &num);
  		adj[S].nodes[0].push_back(num);
  	}
  	for(int j=0; j<N2; j++){
  		scanf("%d", &num);
  		adj[S].nodes[1].push_back(num);
  	}
  }

  // printf("find(%d, %d) = %d\n\n", 9, 8, find(9, 8)); 

  // for(int i=1; i<=N; i++){
  // 	printf("%d: | (%d) | ", i, adj[i].length);
  // 	for(int n : adj[i].nodes[0])
  // 		printf("%d ", n);
  // 	printf("| ");
  // 	for(int n : adj[i].nodes[1])
  // 		printf("%d ", n);
  // 	printf("\n");
  // }
  // printf("----\n");

  int ans=INT_MAX;
  for(int i=1; i<=N; i++){
  	ans = min(ans, minCycle(i));
  }
  printf("%d\n", ans);
}