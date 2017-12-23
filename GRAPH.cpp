/* Graph Traversal Algorithms */
// Checks if whole graph can be colored using only 2 colors
vi G[MAX];
int color [MAX];
bool bipartite_check(int x)
{
	int i, j, k;
	queue<int> q;
	q.push(x);
	color[x] = 1;
	while(!q.empty()){
		x = q.front(); q.pop();
		j = G[x].size();
		for(i = 0; i < j; i++){
			k = G[x][i];
			if(color[k] == color[x])return false;
			if(!color[k]){
				color[k] = 3 - color[x]; q.push(k);
			} 
		} 
	}
	return true;
}
// Bellman Ford
void bellman_ford(int x)
{
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[x] = 0;
	for (int i = 1; i <= n-1; i++) {
	    for (auto e : edges) {
	       int a, b, w;
	       tie(a, b, w) = e;
	       distance[b] = min(distance[b], distance[a]+w);
	    }
	}
}
// Dijkstra
void dijkstra(int x)
{
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[x] = 0;
	q.push({0,x});
	while (!q.empty()) {
	    int a = q.top().second; q.pop();
	    if (processed[a]) continue;
	    processed[a] = true;
	    for (auto u : adj[a]) {
	       int b = u.first, w = u.second;
	       if (distance[a]+w < distance[b]) {
	           distance[b] = distance[a]+w;
	           q.push({-distance[b],b});
	       }
		} 	
	}
}
// Floyd Warshall
void floyd_warshall(int n)
{
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= n; j++) {
	       if (i == j) distance[i][j] = 0;
	       else if (adj[i][j]) distance[i][j] = adj[i][j];
	       else distance[i][j] = INF;
		} 
	}
	for (int k = 1; k <= n; k++) {
	    for (int i = 1; i <= n; i++) {
	       for (int j = 1; j <= n; j++) {
	           distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
			} 
		}
	}
}