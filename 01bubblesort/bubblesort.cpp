//bubblesort

#include <iostream>
using namespace std;

void bubblesort (int A[], int n){
	int sorted = 0;
	while (sorted != 1){
		sorted = 1;
		for (int i = 0;i<n-1;i++){
			if (A[i]>A[i+1]){
				swap(A[i],A[i+1]);
				sorted = 0;
			}
	}  
	
	for (int j = 0;j<n;j++){
		cout<<A[j]<<" ";
	}
	cout<<endl; 
	
	//n--;//ÿ������һ����Ԫ�ؾ�λ 
	}
	// int* bubblesort()---- return A;
} 

int main(){
	int A[] = {2,5,1,8,4,0,2};
	//int B = bubblesort(A,7);
	bubblesort(A,7); //�������βΣ�������ָ�룬ʵ�θ��Ÿı� 
	for (int i = 0;i<7;i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
