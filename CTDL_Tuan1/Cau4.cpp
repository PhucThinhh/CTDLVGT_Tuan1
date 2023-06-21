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
int TimTuyenTinh(int a[], int n, int x , int &ss){
	int i = 0; ss =ss+2 ;
	while(x!= a[i] && i<n){
	i++ ;
	ss =ss + 2 ;
	}
	if(i<n)
	return i;
	return -1;
}

int TimNhiPhan(int a[], int n, int x, int &ss){
	int left = 0 , right = n-1 , mid, flag = 0; ss=0 ;
	while (left <= right){
			mid = (left + right)/2 ;
			ss++;
		if(a[mid] == x){
			ss=ss+1;
			printf("Vi tri tim thay: %d ",mid);
			return mid;
		}
		else if(a[mid] < x){
			ss=ss+1;
			left = mid + 1 ;   
		}
		
		else {	
		ss=ss+1;
		right = mid -1 ;
		}
	}
	printf ("Khong tim thay!!!");
	return -1 ;
}
int main(){
	int a[1000] , n=100 ,x,ss=0;
	clock_t t1 , t2 ;
	float t ;
	t1 = clock();
	phatSinhMang(a , n);
	InterchangeSort(a , n);
	xuatMang(a , n);
	printf("\nTim tuyen tinh!!!");
	printf("\nGia tri can tim: ");
	scanf("%d", &x);
	int vt = TimTuyenTinh(a,n,x,ss);
	printf("Vi tri tim thay:%d", vt);
	printf("\nSo lan so sanh :%d", ss);
	printf("\n");
	printf("\nTim nhi phan!!!");
	printf("\nGia tri can tim: ");
	scanf("%d", &x);
	TimNhiPhan(a,n,x,ss);
	printf("\nSo lan so sanh :%d", ss);
	t2 = clock();
	t = (float)(t2-t1)/CLOCKS_PER_SEC;
	printf("\nThoi gian lam viec la: %f", t);
}
