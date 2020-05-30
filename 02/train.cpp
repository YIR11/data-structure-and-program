#include <iostream>
#define default_capacity  1600000
using namespace std;
template <typename T> class Stack{
	private:
		int size; int capacity;
		T* elem;
	public:
		Stack(int c = default_capacity, int s = 0, T v = 0 ){
			elem = new T[capacity = c];
			for(size=0;size<s;size++){
				elem[size]=v;
			}
		}
		bool full(){
			if(size>capacity){
				return true;
			}
			return false;
		}

		void push(const T& e){    //插入末元素 
		     if(!full()){
		     	elem[size] = e;
		     	size ++;
			 }
		}
		T pop(){
          T old = elem[size-1];
          size--;
          return old;
		}
		T top(){
			if (size==0){
				return 1600000;
			}
			else{
				return elem[size-1];
			}
		}
		~Stack(){
			delete [] elem;
		}
};
int main(){
	int c1,c2;
	cin>>c1>>c2;
	Stack<int> S1(c1);  //原始次序1，2，3.。。。c1 
	Stack<int> S2(c2);
	int aft[c1];     //B端次序，从aft[0]到aft[c1] 
	for(int i = 0;i<c1;i++){
		S1.push(c1-i);
		cin>>aft[i];
	}

	int l = 0;
	int* str = new int[2*c1];
	
	for(int i = 0;i<c1;i++){
	    if (aft[i]>=S1.top()){
	    	int j = S1.top();
			for(;j<=aft[i];j++){
				S2.push(S1.pop());	
				str[l] = 1;
				l++;
			}
			if(!S2.full()){
			   S2.pop();
			   str[l]=2;
			   l++;
		     }
			else{
			    l =0;
			    str [l]=0;
			    break;
		     }
		}
		else{
			if(aft[i]==S2.top()){
				S2.pop();
				str[l]=2;
				l++;
			}
			else{
			    l =0;
			    str [l]=0;
				break;
			}
		}	
	}
	
	if (l==0){
		cout<<"No"<<endl;
	}
	else{
		for(int i=0;i<l;i++){
			if(str[i]==1){
				printf("%s\n","push");
				//cout<<"push"<<endl;
			}
			else {
				printf("%s\n","pop");
				//cout<<"pop"<<endl;
			}
		}
    }  
	return 0;
}
