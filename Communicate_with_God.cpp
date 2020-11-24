/*
첫째 줄에 우주신들의 개수(N<=1,000) 
이미 연결된 신들과의 통로의 개수(M<=1,000)가 주어진다.
두 번째 줄부터 N개의 줄에는 황선자를 포함하여 
우주신들의 좌표가 (0<= X<=1,000,000), (0<=Y<=1,000,000)가 주어진다. 
그 밑으로 M개의 줄에는 이미 연결된 통로가 주어진다. 
번호는 위의 입력받은 좌표들의 순서라고 생각하면 된다. 
좌표는 정수이다.

첫째 줄에 만들어야 할 최소의 통로 길이를 출력하라.
출력은 소수점 둘째짜리까지 출력하여라.
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int* parent;
int find_parent(int a)
{
	if (parent[a] == a)
		return a;
	return parent[a] = find_parent(parent[a]);
}

void union_vertices(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main()
{
	int N, M; //N: # of vertices, M: # of already connected edges
	cin >> N >> M;

	N++;
	parent = new int[N]; //to avoid error(new int[N+1]) in vs code
	N--;

	for (int i = 0; i <= N; i++)
	{//initialize parents array
		parent[i] = i;
	}

	vector<pair<unsigned int, pair<long long, long long>>> coordinates;
	//first: unique id for each vertex, first.first: x, first.second:y
	for (unsigned int i = 1; i <= N; i++)
	{
		long long x, y;
		cin >> x >> y;

		coordinates.push_back(make_pair(i, make_pair(x, y)));
	}

	for (int i = 0; i < M; i++)
	{//to get already connected vertices
		int v1, v2;
		cin >> v1 >> v2;

		union_vertices(v1, v2);
	}

	vector<pair<double, pair<unsigned int, unsigned int>>> edges;
	//first: length between vertices, second: id of vertices
	for (int i = 0; i < N - 1; i++)
	{//calculate the lengths
		for (int j = i + 1; j < N; j++)
		{
			unsigned int v1, v2;
			v1 = coordinates[i].first;
			v2 = coordinates[j].first;

			if (find_parent(v1) != find_parent(v2))
			{
				double length; //변수를 이렇게 따로 안 나누면 오류가 남
				double length1 = pow(coordinates[i].second.first - coordinates[j].second.first, 2);
				double length2 = pow(coordinates[i].second.second - coordinates[j].second.second, 2);
				length = sqrt(length1 + length2);

				edges.push_back(make_pair(length, make_pair(v1, v2)));
			}
		}
	}	

	//sort lengths of edges in increasing order
	sort(edges.begin(), edges.end());

	/*for (int i = 0; i <= N; i++)
	{
		cout << find_parent(i) << " ";
	}
	cout << endl;

	for (int i = 0; i < edges.size(); i++)
	{
		cout << "(" << edges[i].second.first << ", "
			<< edges[i].second.second << ") -> length: "
			<< edges[i].first << endl;
	}*/

	double result = 0; //result
	for (auto x : edges)
	{
		if (find_parent(x.second.first) == find_parent(x.second.second))
			continue;
		union_vertices(x.second.first, x.second.second);
		result += x.first;
	}

	printf("%.2f", result);

	return 0;
}
