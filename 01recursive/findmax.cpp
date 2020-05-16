//find max of array
#include <iostream>
using namespace std;

int findmax(int A[],int n){
	if (n==1){
		return A[0];
	}
	else{
		return (findmax(A,n-1)>A[n-1])?findmax(A,n-1):A[n-1];
	}
} 
int main(){
	int A[] = {2,4,5,7,8,10,14};
	cout<<findmax(A,7)<<endl;
	return 0; 
}
