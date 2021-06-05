#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	int arr[5];
	scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
	sort(arr,arr+3);
    for(int i=0;i<3;i++) printf("%d ",arr[i]);
	return 0;		
}
