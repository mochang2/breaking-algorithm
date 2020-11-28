/*
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. 
(1≤V≤20,000, 1≤E≤300,000) 모든 정점에는 1부터 V까지 
번호가 매겨져 있다고 가정한다. 
둘째 줄에는 시작 정점의 번호 K(1≤K≤V)가 주어진다. 
셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 
세 개의 정수 (u, v, w)가 순서대로 주어진다. 
이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. 
u와 v는 서로 다르며 w는 10 이하의 자연수이다. 
서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 
있음에 유의한다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#define MAX 300001
using namespace std;
int V, E, startvertex;
vector<pair<int, int>>* adj;

struct Compare
{
	bool operator()(pair<int, int> t, pair<int, int> u)
	{
		return t.first > u.first;
	}
};

int main()
{
	cin >> V >> E;
	cin >> startvertex;

	adj = new vector<pair<int,int>>[V + 1];
	//adj.first: cost, adj.second: destination vertex

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		adj[u].push_back(make_pair(w, v));
	}

	vector<int> d(V + 1, MAX);//currently found min cost 
	//from startvertex to destination(using relaxation)

	priority_queue<pair<int,int>,vector<pair<int,int>>,
		Compare> pq;
	//pq 구성원의 first: d, second: id of vertex

	d[startvertex] = 0;
	pq.push(make_pair(d[startvertex], startvertex));

	while (!pq.empty())
	{
		int current_d = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		for (auto x : adj[vertex])
		{
			if (x.first + current_d < d[x.second])
			{
				d[x.second] = x.first + current_d;
				pq.push(make_pair(d[x.second], x.second));
			}
		}
	}

	for (int i = 1; i <= V; i++) 
	{
		if (d[i] != MAX) 
			printf("%d\n", d[i]);
		
		else 
			printf("INF\n");
	}

	return 0;
}