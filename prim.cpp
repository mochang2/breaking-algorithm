﻿#include <iostream>
#include <vector>
#include <utility>
#include <queue>

#define limit 2147483647
using namespace std;

long* cost;
vector<pair<int, int>>* adj;
bool* visited; //check whether the vertex is in MST or not

int main()
{
	int V, E;
	//V: # of vertices, E: # of edges
	cout << "input V and E : ";
	cin >> V >> E;
	V++;
	cost = new long[V];
	for (int i = 0; i < V; i++)
	{
		cost[i] = limit;
	}
	visited = new bool[V] {false, };
	V--;
	adj = new vector<pair<int, int>>[V + 1];

	for (int i = 1; i <= E; i++)
	{//각 vertex에 대한 인접한 vertex와 edge의 cost 입력
		int a, b, c;
		//a,b : adjacent vertices, c : cost of edge
		cin >> a >> b >> c;

		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
		//adj[i].first: adjacent vertex, adj[i].second: cost of edge
	}

	/*for (int i = 1; i <= V; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << "vertex: " << adj[i][j].first;
			cout << " cost: " << adj[i][j].second;
			cout << endl;
		}
	}*/

	//1번 정점에서 시작
	cost[1] = 0;
	visited[1] = true;
	for (auto x : adj[1])
	{
		cost[x.first] = x.second;
	}

	int result = 0;
	for (int i = 1; i < V; i++) // V-1번 실행
	{
		int next_MST_vertex = 0; //이번 for문에 MST에 추가될 vertex
		for (int j = 1; j <= V; j++)
		{
			if (visited[j] != true &&
				cost[j] < cost[next_MST_vertex])
			{ //MST와 연결된 edge 중 가장 작은 cost의 vertex를 찾음
				next_MST_vertex = j;
			}//이게 다음에 MST에 추가될 vertex
		}

		//cout << next_MST_vertex << endl;
		visited[next_MST_vertex] = true;
		result += cost[next_MST_vertex];

		for (auto x : adj[next_MST_vertex])
		{//현재의 MST를 통해 cost list 업데이트
			if (visited[x.first] != true
				&& cost[x.first] > x.second)
			{
				cost[x.first] = x.second;
			}
		}
	}

	cout << result << endl;

	delete[] cost;
	delete[] visited;
	delete[] adj;


	/*//using priority queue
	int mst_cost = 0;

	// V는 정점의 갯수
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> > > pq;
	//pair<int,int>를 pair.first가 작은 순서대로 vector에 담은 것이 pq다
	vector<bool> selected(V + 1, false);

	// 1번 정점으로 시작
	selected[1] = true;
	for (auto x : adj[1]) {
		pq.push(x);
	}

	while (!pq.empty()) {
		int current_node = pq.top().second;
		int current_cost = pq.top().first;
		pq.pop();
		//pair.first(cost)가 가장 작은 것을 pq에서 pop

		if (!selected[current_node]) {
			selected[current_node] = true;
			mst_cost += current_cost;

			for (auto x : adj[current_node]) {
			//cost 업데이트
				if (!selected[x.second]) {
					int cost = x.first;
					int index = x.second;
					pq.push(make_pair(cost, index));
				}
			}
		}
	}

	cout << mst_cost << endl;
	*/


	return 0;
}