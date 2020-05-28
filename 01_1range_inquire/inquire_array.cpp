//范围查询

#include <iostream>

using namespace std; 

void bubblesort (int A[], int n){  //n是数组的size 
	int sorted = 0;
	while (sorted != 1){
		sorted = 1;
		for (int i = 0;i<n-1;i++){
			if (A[i]>A[i+1]){
				swap(A[i],A[i+1]);
				sorted = 0;
			}
	}  
	}
	// int* bubblesort()---- return A;
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
	//cout<<l<<r<<endl;
    return (r-l);
}


int main(){
	int v_size, inquire_num;
    //cin>>v_size>>inquire_num;
    scanf("%d %d",&v_size,&inquire_num);
    int V[v_size]; 
    for (int i = 0;i<v_size;i++){
    	//cin>>V[i];
    	scanf("%d",&V[i]); 
	}
	
	bubblesort (V, v_size);
	
	//int A[inquire_num];
	
    for (int i = 0;i<inquire_num;i++){
    	int left,right;
    	//cin>>left>>right;
    	scanf("%d %d",&left,&right);         //&取地址符,%d后面不加\n
    	printf("%d\n",inquire(V,v_size,left,right));
    }
    	/**
    	A[i]=inquire(V,v_size,left,right);
	}
    for (int i = 0;i<inquire_num;i++){
    	//cout<<A[i]<<endl;
    	printf("%d\n",A[i]);
	}    
	**/
    return 0;
}

