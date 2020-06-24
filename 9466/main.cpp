#include <iostream>
using namespace std;
int find(int graph[], int root, int key, int size){
    while(size--){
        if(root == key){
            return root;
        }
        root = graph[root];
    }
    return -1;
}
int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int stud, answer = 0;
        cin >> stud;
        int graph[stud + 1] = {
            0,
        };
        bool isvisited[stud + 1] = {
            false,
        };
        answer = stud;

        for (int i = 1; i <= stud; i++)
        {
            cin >> graph[i];
        }

        for (int i = 1; i <= stud; i++)
        {
            if( isvisited[i] == false ){
                isvisited[i] = true;
                
                int cycleroot, cnt=1;
                int next = graph[i];
                if(i == next){
                    answer--;
                    continue;
                }

                while ( ( cycleroot = find(graph, i, next, cnt++) ) == -1 )
                {
                    if(isvisited[next]){
                        cycleroot = 0;
                        break;
                    }
                    next = graph[next];
                }
                if(cycleroot == 0){
                    continue;
                }
                do{
                    isvisited[cycleroot] = true;
                    cycleroot = graph[cycleroot];
                    answer--;
                } while (cycleroot != next && isvisited[cycleroot] == false);
            }
        }

        cout << answer << '\n';
    }
    return 0;
}
/*
어느 노드에서 시작하던 끝은 무조건 사이클

시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
3 초	256 MB	22113	5113	3291	24.685%
문제
이번 가을학기에 '문제 해결' 강의를 신청한 학생들은 텀 프로젝트를 수행해야 한다. 
프로젝트 팀원 수에는 제한이 없다. 심지어 모든 학생들이 동일한 팀의 팀원인 경우와 같이 한 팀만 있을 수도 있다. 
프로젝트 팀을 구성하기 위해, 모든 학생들은 프로젝트를 함께하고 싶은 학생을 선택해야 한다. (단, 단 한 명만 선택할 수 있다.) 
혼자 하고 싶어하는 학생은 자기 자신을 선택하는 것도 가능하다.

학생들이(s1, s2, ..., sr)이라 할 때, r=1이고 s1이 s1을 선택하는 경우나, s1이 s2를 선택하고, s2가 s3를 선택하고,..., sr-1이 sr을 선택하고, sr이 s1을 선택하는 경우에만 한 팀이 될 수 있다.

예를 들어, 한 반에 7명의 학생이 있다고 하자. 
학생들을 1번부터 7번으로 표현할 때, 선택의 결과는 다음과 같다.

1	2	3	4	5	6	7
3	1	3	7	3	4	6
위의 결과를 통해 (3)과 (4, 7, 6)이 팀을 이룰 수 있다. 1, 2, 5는 어느 팀에도 속하지 않는다.

주어진 선택의 결과를 보고 어느 프로젝트 팀에도 속하지 않는 학생들의 수를 계산하는 프로그램을 작성하라.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스의 첫 줄에는 학생의 수가 정수 n (2 ≤ n ≤ 100,000)으로 주어진다. 
각 테스트 케이스의 둘째 줄에는 선택된 학생들의 번호가 주어진다. (모든 학생들은 1부터 n까지 번호가 부여된다.)

출력
각 테스트 케이스마다 한 줄에 출력하고, 각 줄에는 프로젝트 팀에 속하지 못한 학생들의 수를 나타내면 된다.

예제 입력 1 복사
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8
예제 출력 1 복사
3
0

1 7 3 1 3 7 3 4 6
3

1 6
2 3 4 5 6 2
output : 1

1 5
2 5 4 5 2
output : 3

1 6
1 3 4 3 2 6
output : 2

1 13
2 4 5 2 4 1 8 9 10 11 9 10 10
output : 8

1 10
2 5 7 1 6 8 8 3 5 10
output : 6

1 10
2 7 10 5 3 3 9 10 6 3
output : 8

1 6
2 1 1 2 6 3
output : 4
*/