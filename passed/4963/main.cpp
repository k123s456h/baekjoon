#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    int dh[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (1)
    {
        int h, w, answer = 0;
        cin >> w >> h;
        if (h == 0 && w == 0)
        {
            return 0;
        }

        int map[h][w], isvisited[h][w];
        queue<pair<int, int>> q;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
                isvisited[i][j] = 0;
            }
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (isvisited[i][j] == 0 && map[i][j] == 1)
                {
                    isvisited[i][j] = 1;
                    answer++;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        int _h = q.front().first, _w = q.front().second;
                        q.pop();
                        for (int _i = 0; _i < 8; _i++)
                        {
                            int nh = _h + dh[_i];
                            int nw = _w + dw[_i];

                            if (nh < 0 || nh >= h || nw < 0 || nw >= w)
                            {
                                continue;
                            }

                            if (isvisited[nh][nw] == 0 && map[nh][nw] == 1)
                            {
                                isvisited[nh][nw] = 1;
                                q.push(make_pair(nh, nw));
                            }
                        }
                    }
                }
            }
        }

        cout << answer << '\n';
    }
    return 0;
}

/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	21112	10546	7623	49.375%
문제
정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.

한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. 

두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. w와 h는 50보다 작거나 같은 양의 정수이다.

둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.

입력의 마지막 줄에는 0이 두 개 주어진다.

출력
각 테스트 케이스에 대해서, 섬의 개수를 출력한다.

예제 입력 1 복사
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
예제 출력 1 복사
0
1
1
3
1
9
*/