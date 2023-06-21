#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void phatSinhMang(int a[] , int n){
	srand(time(NULL));
	for(int i=0 ;i < n ; i++)
	a[i]=rand()%100; 
}
void xuatMang(int a[], int n){
	for (int i=0 ; i<n ; i++)
	printf("%d ", a[i]);
}
int main(){
	int a[1000] , n=100 ;
	clock_t t1 ,t2 ;
	float t ;
	t1= clock() ;
	phatSinhMang(a , n);
	xuatMang(a , n);
	t2= clock() ;
	t = (float)(t2-t1)/CLOCKS_PER_SEC ;
	printf("\n Thoi gian lam viec:%f", t);
	
}
