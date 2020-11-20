/*
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수
E(1 ≤ E ≤ 100,000)가 주어진다.
다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다.
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다.
C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고,
임의의 두 정점 사이에 경로가 있다.
최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고,
2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, E;
int* parent;
vector<pair<int, pair<int, int>>> Edges; //first: cost / second, third: vertices

int Find(int a)
{
	if (parent[a] == a)
		return a;
	return Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	cin >> V >> E;

	//for grouping
	V++;
	parent = new int[V]; //if V+1 is used, overflow happens
	V--;
	for (int i = 0; i <= V; i++)
	{//initialize, firstly, its parent is itself
		parent[i] = i;
	}

	for (int i = 0; i < E; i++)
	{
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;

		Edges.push_back(make_pair(cost, make_pair(v1, v2)));
	}

	sort(Edges.begin(), Edges.end());

	int result = 0;
	for (auto edge : Edges)
	{
		//cost를 오름차순으로 하여 작은 cost부터 판단
		//같은 parent를 갖고 있지 않으면 Union 실행

		if (Find(edge.second.first) == Find(edge.second.second))
			continue;

		Union(edge.second.first, edge.second.second);
		result += edge.first;
	}

	cout << result << endl;

	delete[]parent;

	return 0;
}