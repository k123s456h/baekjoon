#include <iostream>
using namespace std;
int fibo(int n){
    if(n==0) return 0;
    else if(n==1 || n==2) return 1;
    else if(n==3) return 2;
    else if(n==4) return 3;
    else if(n==5) return 5;
    else if(n==6) return 8;
    return fibo(n-1) + fibo(n-2);
}
int main(void){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}