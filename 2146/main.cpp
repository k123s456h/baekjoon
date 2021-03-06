#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {0, -1, 1, 0},
    dy[4] = {-1, 0, 0, 1};
int map[100][100];
bool isVisited[100][100];


int main(void)
{
  

  int n;
  cin >> n;
  int color = 1;
  int answer = __INT_MAX__;

  queue<pair<int, int>> borders[n + 1];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
      isVisited[i][j] = false;
    }
  }

  for(int i=0;i<n;i++){
    for (int j = 0; j < n;j++){
      
    }
  }

  return 0;
}

/*
입력
첫 줄에는 지도의 크기 N(100이하의 자연수)가 주어진다. 
그 다음 N줄에는 N개의 숫자가 빈칸을 사이에 두고 주어지며, 0은 바다, 1은 육지를 나타낸다. 
항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.

출력
첫째 줄에 가장 짧은 다리의 길이를 출력한다.

예제 입력 1 
10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
예제 출력 1 
3


1 1 1 9 0 0 7 1 1 1
1 1 1 1 9 0 0 7 1 1
1 9 1 1 9 0 0 7 1 1
9 9 1 1 1 9 0 0 7 1
0 0 9 1 9 0 0 0 7 1
0 0 0 9 0 0 0 0 7 1
0 0 0 0 8 8 0 0 0 7
0 0 0 8 1 1 8 0 0 0
0 0 0 8 1 1 1 8 0 0
0 0 0 0 8 8 8 0 0 0

1 1 1 9 9 0 7 1 1 1
1 1 1 1 9 9 0 7 1 1
1 9 1 1 9 9 0 7 1 1
9 9 1 1 1 9 9 0 7 1
9 9 9 1 9 9 0 0 7 1
0 0 9 9 9 0 0 0 7 1
0 0 0 9 8 8 0 0 0 7
0 0 0 8 1 1 8 0 0 0
0 0 0 8 1 1 1 8 0 0
0 0 0 0 8 8 8 0 0 0
*/