//2^n
#include <iostream>
using namespace std;

int power2(int n){
	if (n==0){
		return 1;
	}
	else{
		return 2*power2(n-1);
	}
} 
int main(){
	cout<<power2(3)<<endl;
	return 0;
}
