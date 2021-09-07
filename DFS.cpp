#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int x){
	visited[x] = true;
	cout << x << " ";
	for(int i=0; i<graph[x].size(); i++){
		int y = graph[x][i];
		if(!visited[y])
			dfs(y);
	}
}


int main(){
	
	graph[0].push_back();
	graph[1].push_back({2,3,8});

	dfs(1);

	return 0;
}
