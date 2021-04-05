#include <iostream>
using namespace std;

int M,K,map[8][8];
int ans[8][8],R[8],C[8],cur;
int spR[8],spC[8],newMap[8][8],newR[8],newC[8],pest[8][8];

int main(){
    cin>>M>>K;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>map[i][j];
            map[i][j]-=M;
            R[i]+=map[i][j];
            C[j]+=map[i][j];
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cur=R[i]+C[j]-map[i][j];
            if(cur%2){
                ans[i][j]=1;
                spR[i]++; spC[j]++;
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            newMap[i][j]=spR[i]+spC[j]-ans[i][j];
            newR[i]+=newMap[i][j];
            newC[j]+=newMap[i][j];
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cur=newR[i]+newC[j]-newMap[i][j];
            if((R[i]+C[j]-map[i][j]-cur)%4)pest[i][j]=1;
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(ans[i][j])
                cout<<(pest[i][j]?'-':'+')<<" ";
            else
                cout<<". ";
        }
        cout<<"\n";
    }
}
