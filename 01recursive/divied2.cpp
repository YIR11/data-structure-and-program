//等分数组？
#include <iostream>
using namespace std;

int sum(int A[],int n){
	int s =0;
	for (int i = 0;i<n;i++){
		s+=A[i];
	}
	return s;
} 

bool can_be_divied(int A[],int n,int half_sum){
	if (n==0){
		return A[0]==half_sum;
	}
	else{
		return can_be_divied(A,n-1,half_sum)||(sum(A,n-1)+A[n-1]==half_sum)||A[n-1]==half_sum;
	}
}
int main(){
	int A[] = {1,2,3,4,5,18};
	int half_sum = 0.5*sum(A,6);
	cout<<can_be_divied(A,6,half_sum)<<endl;
	return 0;
}
