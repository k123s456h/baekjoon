#include<cstdio>
int max(int a, int b){return a>b ? a : b;}
int main(void){
    int n; scanf("%d", &n);
    int p[n+1] = {0, }, dp[n+1] = {0, };
    for(int i=1; i<=n; i++) scanf("%d", &p[i]);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], dp[i-j] + p[j]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}

/* 

예를 들어, 카드팩이 총 4가지 종류가 있고, P1 = 1, P2 = 5, P3 = 6, P4 = 7인 경우에 민규가 카드 4개를 갖기 위해 지불해야 하는 금액의 최댓값은 10원이다. 2개 들어있는 카드팩을 2번 사면 된다.

P1 = 5, P2 = 2, P3 = 8, P4 = 10인 경우에는 카드가 1개 들어있는 카드팩을 4번 사면 20원이고, 이 경우가 민규가 지불해야 하는 금액의 최댓값이다.

마지막으로, P1 = 3, P2 = 5, P3 = 15, P4 = 16인 경우에는 3개 들어있는 카드팩과 1개 들어있는 카드팩을 구매해 18원을 지불하는 것이 최댓값이다.

p[i]: i개 카드가 든 팩의 가격.
dp[i]: i개의 카드를 골랐을 때 금액의 최댓값.

n개의 카드를 고를 때 마지막에:
p1을 고른다 하면 dp[n-1] + p[1];
p2를 고른다 하면 dp[n-2] + p[2];
...
pn을 고른다 하면 dp[n-n] + p[n];
따라서 dp[n]은 위 값 중에서 최댓값을 고르면 된다.
*/