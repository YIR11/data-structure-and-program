//范围查询

#include <iostream>
#define max 10000000
using namespace std; 
void merge(int a[],int m,int q,int n)  //[m,q]和[q+1,n)是已经有序的两部分 L，R 
{
	int n1 = q - m + 1;
	int n2 = n - q;
	int *L = new int[n1+1];
	int *R = new int[n2 + 1];
	int i, j, k;
	for ( i = 0; i < n1; i++)
	{
		L[i] = a[m+i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = a[q + 1+ j];
	}
	L[n1] = max;    //省去了某一列空，将另一列整体放入的操作 
	R[n2] = max;
	for (i = 0, j = 0,k = m; k <= n; k++)
	{
		//i = 0, j = 0;               //特别注意i=0,j=0;放在for循环里面和外面完全不一样结果
		if (L[i] <=R[j])
		{
			a[k] = L[i];
			i++;
		}
		else 
		{
			a[k] = R[j];
			j++;
		}
	}
	delete[]L;
	delete[]R;
}
void mergesort (int A[], int m,int n){  //m,n是数组的下标左右值 
	if (m<n){
		int q = (n+m)/2;
		mergesort(A,m,q);
		mergesort(A,q+1,n);
		merge(A,m,q,n);
	}
} 

int binsearch_l(int* A,int e,int lo,int hi){
	while(lo<hi){
		int mi = (lo + hi)/2;
		//int mi = (lo + hi)>>1;
		if (e<A[mi]){
			hi = mi;
		}
		else {
			if (e==A[mi]){
				return mi-1;
			}
			else{
				lo = mi + 1;
			}
		}
	}
	return --lo;
}

int binsearch_r(int* A,int e,int lo,int hi){
	while(lo<hi){
		int mi = (lo + hi)/2;
		//int mi = (lo + hi)>>1;
		if (e<A[mi]){
			hi = mi;
		}
		else {
			lo = mi + 1;
		}
	}
	return --lo;
}

int inquire(int* V,int size,int left,int right){
	int l = binsearch_l(V,left,0,size);
	int r = binsearch_r(V,right,0,size);
    return (r-l);
}

int main(){
	int v_size, inquire_num;
    scanf("%d %d",&v_size,&inquire_num);
    int V[v_size]; 
    for (int i = 0;i<v_size;i++){
    	scanf("%d",&V[i]); 
	}	
	mergesort (V, 0,v_size-1);	
    for (int i = 0;i<inquire_num;i++){
    	int left,right;
    	scanf("%d %d",&left,&right);        
    	printf("%d\n",inquire(V,v_size,left,right));
    }
    return 0;
}

