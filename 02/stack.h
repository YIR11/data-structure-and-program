#ifndef _Stack_H
#define _Stack_H
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

		void push(const T& e){    //²åÈëÄ©ÔªËØ 
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
#endif
