/*
<그림 1>과 같이 정사각형 모양의 지도가 있다.
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고,
단지에 번호를 붙이려 한다.
여기서 연결되었다는 것은 어떤 집이 좌우,
혹은 아래위로 다른 집이 있는 경우를 말한다.
대각선상에 집이 있는 경우는 연결된 것이 아니다.
<그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
지도를 입력하여 단지수를 출력하고,
각 단지에 속하는 집의 수를 오름차순으로 정렬하여
출력하는 프로그램을 작성하시오.*/


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
