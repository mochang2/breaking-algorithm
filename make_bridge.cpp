#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define max 10 //cannot exceed max cost

int N, M;
int country[12][12];
bool visited[12][12] = { false, };
vector<pair<int, int>> displaying_islands[7];
//2<=섬의 갯수<=6
//displaying_islands.first: row, displaying_islads.second: column

vector<pair<int, int>> adj[7];
//adj[].first: cost, adj[].second: adjacent vertex

int cost[7];
int num_of_islands = 0;
int dx[4] = { 0,1,0,-1 }; //up, right, down, left
int dy[4] = { -1,0,1,0 };

template <class T1, class T2, class Pred = std::less<T2> >
struct sort_pair_second {
	bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
		Pred p;
		return p(left.second, right.second);
	}
};

void calculate_number_of_islands(int row, int column)
{
	visited[row][column] = true;
	country[row][column] = num_of_islands;

	displaying_islands[num_of_islands].push_back(make_pair(row, column));

	for (int k = 0; k < 4; k++)
	{
		int newY = row + dy[k];
		int newX = column + dx[k];

		if (newY >= 1 && newY <= N && newX >= 1 && newX <= M)
		{
			if (country[newY][newX] && visited[newY][newX] == false)
			{
				calculate_number_of_islands(newY, newX);
			}
		}
		
	}
}

int main()
{
	//initialize
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			country[i][j] = 0;
		}
	}

	cout << "input N and M: ";
	cin >> N >> M;
	cout << "input a country: " << endl;
	for (int i = 1; i <= N; i++)
	{//input country
		for (int j = 1; j <= M; j++)
		{
			cin >> country[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (country[i][j] && !visited[i][j])
			{//calculate # of islands in a country
				num_of_islands++;
				calculate_number_of_islands(i, j);
			}
		}
	}

	//cout << "# of islands: " << num_of_islands << endl;

	//for (int i = 1; i <= N; i++)
	//{//check the country
	//	for (int j = 1; j <= M; j++)
	//	{
	//		cout << country[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//for (int i = 1; i <= displaying_islands[1].size(); i++)
	//{//check displaying_islands
	//	cout << "(" << displaying_islands[1][i-1].first << ", "
	//		<< displaying_islands[1][i-1].second << ")" << endl;
	//}

	////E = num_of_islands - 1, V = num_of_islands
    ////가능한 모든 edge 구하기
	for (int i = 1; i <= 6; i++)
	{//island_number = i;
		if (displaying_islands[i].size() >= 1)
		{
			for (int j = 0; j < displaying_islands[i].size(); j++)
			{
				int cost;
				int row;
				int column;
				int adj_island_number;

				for (int k = 0; k < 4; k++)
				{
					cost = 0;
					row = displaying_islands[i][j].first;
					column = displaying_islands[i][j].second;
					adj_island_number = -1;

					while (row >= 1 && row <= N 
						&& column >= 1 && column <= M)
					{
						row += dy[k];
						column += dx[k];
						cost++;

						if (country[row][column] != 0 &&
							country[row][column] != i)
						{
							adj_island_number = country[row][column];
							break;
						}
						else if(country[row][column] == i)
						{
							break;
						}
					}
					//거리가 1보다는 커야됨
					if (adj_island_number != -1)
					{//adj update
						adj[i].push_back(make_pair(cost - 1,
							adj_island_number));						
					}
				}
			}
		}
	}

	//adj에서 cost가 1인 다리 삭제
	for (int i = 1; i <= 6; i++)
	{//island_number = i;
		if (displaying_islands[i].size() >= 1)
		{
			for (int j = 0; j < displaying_islands[i].size(); j++)
			{
				vector<pair<int, int>>::iterator iter;
				for (iter = adj[i].begin(); iter != adj[i].end();)
				{
					if ((*iter).first == 1)
						iter = adj[i].erase(iter);
					else
						++iter;
				}
			}
		}
	}

	for (int i = 1; i <= 6; i++)
	{//adj를 vertex를 기준으로 정렬
		sort(adj[i].begin(), adj[i].end(), sort_pair_second<int,int>());
	}

	/*for (int i = 1; i <= 6; i++)
	{
		if (adj[i].size() >= 1)
		{
			for (int j = 0; j < adj[i].size(); j++)
			{
				cout << "cost: " << adj[i][j].first;
				cout << " vertex: " << adj[i][j].second << endl;
			}
		}
		cout << endl;
	}*/

    //initialize cost
	for (int i = 0; i < 7; i++)
	{
		cost[i] = max;
	}

	bool* selected;
	num_of_islands++;
	selected = new bool[num_of_islands] {false, };
	num_of_islands--;

	//1번에서부터 시작
	cost[1] = 0;
	selected[1] = true;
	for (auto x : adj[1])
	{
		if(cost[x.second] > x.first)
			cost[x.second] = x.first;
	}

	int result = 0;
	for (int i = 1; i < num_of_islands; i++) // num_of_islands-1번 실행
	{
		int next_MST_vertex = 0; //이번 for문에 MST에 추가될 vertex
		for (int j = 1; j <= num_of_islands; j++)
		{
			if (selected[j] != true &&
				cost[j] < cost[next_MST_vertex])
			{ //MST와 연결된 edge 중 가장 작은 cost의 vertex를 찾음
				next_MST_vertex = j;
			}//이게 다음에 MST에 추가될 vertex
		}

		//cout << "include " << next_MST_vertex << endl;
		selected[next_MST_vertex] = true;
		//cout << "plus " << cost[next_MST_vertex] << endl;
		if (cost[next_MST_vertex] != 10)
			result += cost[next_MST_vertex];

		for (auto x : adj[next_MST_vertex])
		{//현재의 MST를 통해 cost list 업데이트
			if (selected[x.second] != true
				&& cost[x.second] > x.first)
			{
				cost[x.second] = x.first;
			}
		}
	}

	bool flag = true;
	for (int i = 1; i <= num_of_islands; i++)
	{
		if (!selected[i])
		{
			cout << -1 << endl;
			flag = false;
			break;
		}
	}
	if (flag)
		cout << result << endl;

	return 0;
}