#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int N, M;
int arr[10];
vector<int> save(10);
vector<vector<int>> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> save[i];
    sort(save.begin(), save.begin()+N);
    fill(arr, arr+N, 1);
    for(int i=0;i<M;i++) arr[i] = 0;
    do{
        vector<int> tmp;
        for(int i=0;i<N;i++)
            if(!arr[i])
                tmp.push_back(save[i]);
        do{
            ans.push_back(tmp);
        }while(next_permutation(tmp.begin(), tmp.end()));
    }while(next_permutation(arr, arr+N));

    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)
    {
        bool result = true;
        if(i>0){
            for(int j=0;j<ans[i].size();j++)
            {
                if(ans[i-1][j] != ans[i][j]) result = false;
            }
        }
        if(i == 0 or !result){
            for(int j=0;j<ans[i].size();j++)
            {
                cout << ans[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
