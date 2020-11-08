/*
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 
프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 
정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는
경우 종료한다. 정점 번호는 1번부터 N번까지이다.

첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 
탐색을 시작할 정점의 번호 V가 주어진다. 
다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 
어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
입력으로 주어지는 간선은 양방향이다.

첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. 
V부터 방문된 점을 순서대로 출력하면 된다.
*/
//https://www.acmicpc.net/board/view/24356 여기하고 
//https://www.acmicpc.net/board/view/27269 여기 있는 반례도 전부 통과

#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void addEdge(vector<int> [], int, int);
void printGraph(vector<int> [], int);
void DFS(vector<int> [], int, int []);
void BFS(vector<int> [], int, int []);

int main()
{
	int n = 0, m = 0, v = 0;
	//n: # of vertices m: # of edges, v: start vertex

	cin >> n >> m >> v;
	cout << "n = " << n << endl;
	cout << "m = " << m << endl;
	cout << "v = " << v << endl;

	int* visited = new int[n + 1]();
	vector<int>* adj = new vector<int>[n + 1]();
	
	for (int i = 1; i < m + 1; i++)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		addEdge(adj, x, y);
	}
	for (int i = 1; i < n + 1; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	//printGraph(adj, n); //show adjacent vertices

	cout << "DFS start\n";
	DFS(adj, v, visited);
	//reset
	for (int i = 1; i < n + 1; i++)
	{
		visited[i] = 0;
	}
	cout << "\nBFS start\n";
	BFS(adj, v, visited);


	delete[] adj;
	delete[] visited;


	return 0;
}


void addEdge(vector<int> adj[], int x, int y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}
void printGraph(vector<int> adj[], int V) {
	for (int i = 1; i < V + 1; i++) {
		cout << i;
		for (auto x : adj[i])
			cout << "->" << x;
		cout << endl;
	}
}

void DFS(vector<int> adj[], int criteria_row, int visited[])
{		//criteria_row : adj[i]
	if (visited[criteria_row] == 1)
		return;
	//else: visited == 0(false)
	visited[criteria_row] = 1;
	cout << /*"I visited " <<*/ criteria_row << " ";

	for (auto x : adj[criteria_row])
	{
		if (visited[x] != 1)
		{
			DFS(adj, x, visited);
		}
	}

}
void BFS(vector<int> adj[], int first, int visited[])
{
	queue<int> Q;
	Q.push(first);
	visited[first] = 1;
	cout << /*"I visited " <<*/ first << " ";
	
	while (!Q.empty()) //while Q is not empty
	{
		int currentNode = Q.front();
		Q.pop();

		for (auto x : adj[currentNode]) {
			if (visited[x] != 1)
			{
				cout << /*"I visited " <<*/ x << " ";
				visited[x] = 1;
				Q.push(x);
			}
		}	
	}
}