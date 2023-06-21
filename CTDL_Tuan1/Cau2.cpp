//Bài 2: Vi?t chuong trình cài d?t gi?i thu?t tìm ki?m tuy?n tính.
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
int TimTuyenTinh(int a[], int n, int x){
	int i = 0;
	while(x!= a[i] && i<n)
	i++ ;
	if(i<n)
	return i;
	return -1;
}
int main(){
	int a[1000] , n=100 ,x ;
	clock_t t1 ,t2 ;
	float t ;
	t1= clock() ;
	phatSinhMang(a , n);
	xuatMang(a , n);
	printf("\nGia tri can tim: ");
	scanf("%d", &x);
	int vt = TimTuyenTinh(a,n,x);
	printf("Vi tri tim thay:%d", vt);
		t2= clock() ;
	t = (float)(t2-t1)/CLOCKS_PER_SEC ;
	printf("\n Thoi gian lam viec:%f", t);
}
