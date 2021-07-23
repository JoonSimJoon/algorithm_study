#include <iostream>
 
using namespace std;
 
int coins[11];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int N, total;
    cin >> N >> total;
 
    for(int i = 0; i < N; i++)
        cin >> coins[i];
 
    int result = 0;
 
    for(int i = 1; i <= N; i++){
        result += total / coins[N-i];
        total %= coins[N-i];
        if(total == 0)
            break;
    }
    cout << result;
 
    return 0;
}
