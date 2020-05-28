#include <iostream>
using namespace std;
long long MAX = 10000000000;
long long num_inv = 0;     //全局变量，方便每次递归调用 
struct  xy{
	long long x;
	long long y;
};
//对x排序
void merge(xy a[],long long m,long long q,long long n)  //[m,q]和[q+1,n)是已经有序的两部分 L，R 
{
	long long n1 = q - m + 1;
	long long n2 = n - q;
	xy *L = new xy[n1+1];
	xy *R = new xy[n2 + 1];
	long long i, j, k;
	for ( i = 0; i < n1; i++)
	{
		L[i] = a[m+i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = a[q + 1+ j];
	}
	L[n1].x = MAX;    //省去了某一列空，将另一列整体放入的操作 
	R[n2].x = MAX;
	for (i = 0, j = 0,k = m; k <= n; k++)
	{
		//i = 0, j = 0;               //特别注意i=0,j=0;放在for循环里面和外面完全不一样结果
		if (L[i].x < R[j].x)
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
void sort_x(xy A[],long long m,long long n){
	if (m<n){
		long long q = (m+n)/2;
		sort_x(A,m,q);
		sort_x(A,q+1,n);
		merge(A,m,q,n);
	}
} 
void get_y(xy A[],long long num,long long* B){
	for (long long i=0;i<num;i++){
		B[i] = A[i].y;
	}
}





void inver(long long a[],long long m,long long q,long long n)  //[m,q]和[q+1,n)是已经有序的两部分 L，R 
{
	//long long num_inv = 0;
	
	long long n1 = q - m + 1;
	long long n2 = n - q;
	long long *L = new long long[n1+1];
	long long *R = new long long[n2 + 1];
	long long i, j, k;
	for ( i = 0; i < n1; i++)
	{
		L[i] = a[m+i];
	}
	for (j = 0; j < n2; j++)
	{
		R[j] = a[q + 1+ j];
	}
	L[n1] = MAX;    //省去了某一列空，将另一列整体放入的操作 
	R[n2] = MAX;
	for (i = 0, j = 0,k = m; k <= n; k++)
	{
		//i = 0, j = 0;               //特别注意i=0,j=0;放在for循环里面和外面完全不一样结果
		if (L[i] <R[j])
		{
			a[k] = L[i];
			i++;
			if (j!=n2){
			num_inv = num_inv + (n2-j);     //右侧j及其后元素都可以与i构成顺序对，依次累加即可 
			//cout<<num_inv<<endl;
		}
		}
		else 
		{
			a[k] = R[j];
			j++;
		}
	}
	delete[]L;
	delete[]R;
	//return num_inv;
}


void inversion(long long A[],long long m, long long n){//,long long &num_inv){
	
	if (m<n){
		long long q = (m+n)/2;
		inversion(A,m,q);//,num_inv);
		inversion(A,q+1,n);//,n,num_inv);
		//num_inv += inver(A,m,q,n);
		inver(A,m,q,n);
	}
	//return num;
}

int main(){
	long long num;
	cin>>num;
	xy A[num];
	for (long long i=0;i<num;i++){
		cin>>A[i].x>>A[i].y;
	}                              //各个坐标存入结构体数组 
    sort_x(A,0,num-1);
    long long B[num];
    get_y(A,num,B); 

	//long long num_inv=0;   
	inversion(B,0,num-1);//,num_inv);
	cout<<num_inv<<endl;
	return 0;
}
