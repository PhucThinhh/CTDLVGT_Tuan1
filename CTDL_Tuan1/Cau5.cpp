#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void phatSinhMang(int a[] , int n){
	srand(time(NULL));
	for(int i=0 ;i < n ; i++)
	a[i]=rand()%100; 
}
void XuatMang(int a[], int N) {
    printf("Mang: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int TimTuyenTinh(int a[], int N, int X) {
    for (int i = 0; i < N; i++) {
        if (a[i] == X) {
            return i;  
        }
    }
    return -1;  
}

int TimNhiPhan(int a[], int N, int X) {
    int left = 0;
    int right = N - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (a[mid] == X) {
            return mid;  
        } else if (a[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  
}

int TimNhiPhan2(int a[], int N, int X) {
    int left = 0;
    int right = N - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (a[mid] == X) {
            return mid;  
        } else if (a[mid] > X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;  
}

bool KiemTraTang(int a[], int N) {
    for (int i = 0; i < N - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool KiemTraGiam(int a[], int N) {
    for (int i = 0; i < N - 1; i++) {
        if (a[i] < a[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[1000] , n=100 ,x ;
    clock_t t1,t2;
    float t ;
    t1 = clock();
	phatSinhMang(a , n);
    XuatMang(a, n);
    int X;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &X);

if (KiemTraTang(a, n)) {
    int result = TimNhiPhan(a, n, X);
    if (result != -1) {
        printf("Tim thay tai vi tri %d\n", result);
    } else {
        printf("Khong tim thay gia tri\n");
    }
} else if (KiemTraGiam(a, n)) {
    int result = TimNhiPhan2(a, n, X);
    if (result != -1) {
        printf("Tim thay tai vi tri %d\n", result);
    } else {
        printf("Khong tim thay gia tri\n");
    }
} else {
    int result = TimTuyenTinh(a, n, X);
    if (result != -1) {
        printf("Tim thay tai vi tri %d\n", result);
    } else {
        printf("Khong tim thay gia tri\n");
    }
}
t2 = clock();
t = (float)(t2-t1)/CLOCKS_PER_SEC;
printf("Thoi gian lam viec la: %f", t);
}

