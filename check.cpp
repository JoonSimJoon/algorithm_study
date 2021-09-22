#include <time.h>
#include <math.h>
#include <stdio.h>
#define ll long long
ll x = 100000;
ll y = -100001;
ll sum =0,z;

int main(){
    int  i;
    double start, end;

    //for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;    
    for(i = 0;i<100000;i++){
        z=abs(x);
        sum++;
    }

    //for 루프 끝난 시간
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("time complexity :%lf\n", (end-start));
}