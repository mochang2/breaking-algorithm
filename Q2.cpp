////DFS using recursive
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
////(dcolumn, drow)-> up, right, down, left separately
//int dcolumn[4] = { 0,1,0,-1 };
//int drow[4] =	 { -1,0,1,0 };
//string arr[25];
//bool visited[25][25] = { false, };
//vector<int> result;
//int area;
//
//void dfs(int row, int column, int n)
//{
//	visited[row][column] = true;
//	area++;
//
//	for (int k = 0; k < 4; k++)
//	{
//		int newRow = row + drow[k];
//		int newColumn = column + dcolumn[k];
//
//		if (newRow >= 0 && newRow < n && newColumn >= 0 && newColumn < n)
//		{
//			if (arr[newRow][newColumn] == '1' && visited[newRow][newColumn] == false)
//			{
//				dfs(newRow, newColumn, n);
//			}
//		}
//	}
//}
//
//int main()
//{
//	int i = 0, j = 0;
//	int n = 0;
//	//cout << "input the size N : ";
//	cin >> n;
//	//cout << "\n";
//	
//	for (i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (arr[i][j] == '1' && visited[i][j] == false)
//			{
//				area = 0;
//				dfs(i, j, n);
//				result.push_back(area);
//			}
//		}
//	}
//
//	sort(result.begin(), result.end());
//
//	cout << result.size() << endl;
//	for (i = 0; i < result.size(); i++)
//	{
//		cout << result[i] << endl;
//	}
//
//	return 0;
//}


////BFS using queue
//#include <cstdio>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//queue<pair<int, int>> q;
//vector<int> vc;
//
//int map[26][26]{};
//int dx[] = { -1,1,0,0 };
//int dy[] = { 0,0,1,-1 };
//
//int main()
//{
//	int n;
//	scanf_s("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf_s("%1d", &map[i][j]);
//		}
//	}
//
//	int area;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (map[i][j] == 1)
//			{
//				area = 0;
//				map[i][j] = 0;
//				q.push(make_pair(i, j));
//
//				while (!q.empty())
//				{
//					area++;
//					pair<int, int> now = q.front();
//					q.pop();
//					for (int k = 0; k < 4; k++)
//					{
//						if (now.first + dy[k] < 0 ||
//							now.first + dy[k] >= n ||
//							now.second + dx[k] < 0 ||
//							now.second + dx[k] >= n)
//						{
//							continue;
//						}
//						if (map[now.first + dy[k]][now.second + dx[k]] == 1)
//						{
//							map[now.first + dy[k]][now.second + dx[k]] = 0;
//							q.push(make_pair(now.first + dy[k],
//								now.second + dx[k]));
//						}
//					}
//				}
//				vc.push_back(area);
//			}
//		}
//	}
//
//	printf("%d\n", vc.size());
//
//	sort(vc.begin(), vc.end());
//
//	for (int i = 0; i < vc.size(); i++)
//	{
//		printf("%d\n", vc[i]);
//	}
//
//	return 0;
//}
