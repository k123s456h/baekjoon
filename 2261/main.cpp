#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void combine(vector<pair<int,int>> points, int xlow, int xhigh){

}

int solve(vector<pair<int,int>> points, int x_low, int x_high){
    if(x_high)
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    long long int smallest = LLONG_MAX;
    cin >> n;
    vector<pair<int ,int>> points;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end(), [](pair<int,int> a, pair<int,int> b) -> bool {
        if(a.first == b.first){
            return a.second < b.second;
        }else{
            return a.first < b.first;
        }
    });



    cout << smallest << '\n';
}

/*
문제
2차원 평면상에 n개의 점이 주어졌을 때, 이 점들 중 가장 가까운 두 점을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 n(2 ≤ n ≤ 100,000)이 주어진다. 다음 n개의 줄에는 차례로 각 점의 x, y좌표가 주어진다. 
각각의 좌표는 절댓값이 10,000을 넘지 않는 정수이다. 같은 점이 여러 번 주어질 수도 있다.

출력
첫째 줄에 가장 가까운 두 점의 거리의 제곱을 출력한다.

예제 입력 1 복사
4
0 0
10 10
0 10
10 0
예제 출력 1 복사
100
*/