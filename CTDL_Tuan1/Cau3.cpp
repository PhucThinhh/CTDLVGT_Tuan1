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
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void InterchangeSort(int a[], int n){   
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if(a[i] > a[j]) 
                Swap(a[i], a[j]);
}
int TimNhiPhan(int a[], int n, int x){
	int left = 0 , right = n-1 , mid, flag = 0;
	while (left <= right){
		mid = (left + right)/2 ;
		if(a[mid] == x){
			printf("Vi tri tim thay: %d ",mid);
			flag = 1;
			break ;
		}
		else if(a[mid] < x)
		left = mid + 1 ;
		else 
		right = mid -1 ;
	}
	if(flag == 0)
	printf ("Khong tim thay!!!");
}
int main(){
	int a[1000] , n=100 ,x ;
	clock_t t1,t2 ;
	float t ;
	t1 = clock();
	phatSinhMang(a , n);
	InterchangeSort(a , n);
	xuatMang(a , n);
	printf("\nGia tri can tim: ");
	scanf("%d", &x);
	TimNhiPhan(a,n,x);
	t2=clock();
	t =(float)(t2-71)/CLOCKS_PER_SEC ;
	printf("\nThoi gian lam viec la :%f", t);
	
}
