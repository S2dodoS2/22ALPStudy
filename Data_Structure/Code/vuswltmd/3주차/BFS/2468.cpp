#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iterator>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
#define X first
#define Y second
int board[102][102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1,  0, -1};

int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int mx = 0;
	int WH = 0; //물의 높이고 1~mx번 반복할것임
	int nummx = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			
			if (mx < board[i][j])
			{
				mx = board[i][j];
			}
		}
	}

	while (1)
	{
		if (WH > mx)
		{
			break;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] <= WH)
				{
					board[i][j] = -1;
				}
			}
		}

		queue<pair<int, int>> Q;
		int num = 0; //안전지대의 수
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] != -1 && vis[i][j] == 0)
				{
					Q.push({ i, j });
					vis[i][j] = 1;
					num++;
				}

				while (!Q.empty())
				{
					auto cur = Q.front(); Q.pop();

					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						if (vis[nx][ny] != 0 || board[nx][ny] == -1) continue;

						vis[nx][ny] = 1;

						Q.push({ nx, ny });
					}
				}
			}
		}


		if (nummx < num)
		{
			nummx = num;
		}

		WH++;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				vis[i][j] = 0;
			}
		}
	}

	cout << nummx;
}