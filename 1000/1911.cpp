#include <iostream>
#include <cmath>
#include <algorithm>


using namespace std;

 

int N, L, Ans;

pair<int, int> Puddles[10000];

 

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

 

    cin >> N >> L;

    for (int i = 0; i < N; ++i)

        cin >> Puddles[i].first >> Puddles[i].second;

 

    sort(Puddles, Puddles + N);

    

    int s = 0;

    for (int i = 0; i < N; ++i)   {
        s = max(Puddles[i].first, s);
        int diff = Puddles[i].second - s;
        int count = (diff + L - 1) / L;

        Ans += count;
        s += count * L;
    }
    cout << Ans;
}

