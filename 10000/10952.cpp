#include <stdio.h>

int main(){
	int N;
	while(1){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==b && a==0) break;
		else printf("%d\n",a+b);
	}
}
