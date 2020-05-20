#include <cstdio>
void swap(int *a, int *b){int *tmp = a; a=b; b=tmp; }
void sort(int a[][2], int low, int high){
    if(low >= high) return;

    int pivot = low, start=low+1, idx=high;
    for( ; start<high; start++){
        if( a[start][1] > a[pivot][1] ){
            swap( a[start], a[--idx] );
        }else if( a[start][1] == a[pivot][1] && a[start][0] > a[pivot][0] ){
            swap( a[start], a[--idx] );
        }
    }
    swap( a[--idx], a[pivot] );

    sort(a, low, idx-1);
    sort(a, idx+1, high);
}
int main(void){
    int n; scanf("%d", &n);
    int array[n][2] = {0, };

    for(int i=0; i<n; i++) scanf("%d %d", &array[i][0], &array[i][1]);

    sort(array, 0, n-1);

    for(int i=0; i<n; i++) printf("%d %d\n", &array[i][0], &array[i][1]);

    return 0;
}


/* 
문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 y좌표가 증가하는 순으로, y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.

예제 입력 1 복사
5
0 4
1 2
1 -1
2 2
3 3
예제 출력 1 복사
1 -1
1 2
2 2
3 3
0 4
 */