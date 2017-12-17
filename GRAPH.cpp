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
			} } }
	return true;
}
// Dijkstra