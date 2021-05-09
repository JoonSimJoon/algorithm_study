#include <cstdio>
using namespace std;
 
int N, sum = 0, answer;
int money[100001];
void check(int m, int start, int end) {
    while(start<=end) {
        int limit = (start+end)/2, mn=0, flag=0;
        int nowMoney = 0;
        for(int i=0; i<N; i++) {
            if(money[i] > limit) {
                flag = 1;
                break;
            }
            if(money[i] > nowMoney) {
                nowMoney = limit;
                mn++;
            }
            else if((m-mn) == (N-i)) {
                nowMoney = limit;
                mn++;
            }
            nowMoney -= money[i];
        }
        if(flag == 1) {
            start = limit+1;
        }
        else if(mn == m) {
            answer = limit;
            end = limit-1;
        }
        else if(mn > m) {
            start = limit+1;
        }
        else {
            end = limit-1;
        }
    }
}
 
int main() {
    int M, minValue=10000;
    scanf("%d %d", &N, &M);
 
    for(int i=0; i<N; i++) {
        scanf(" %d", &money[i]);
        sum += money[i];
        if(money[i]  < minValue) {
            minValue = money[i];
        }
    }
    check(M, minValue, sum+1);
    printf("%d\n", answer);
}
