#include <iostream>
using namespace std;

class Fib{
	public:
		Fib(int n);
		int get();
		int next();
		int prev();
	private:
		int g,f;
}; 
Fib::Fib(int n){
	f = 1;
	g = 0;
	while(n>0){
		g = g + f;
		f = g - f;
		n--;
	}
}
int Fib::get(){
	return g;
}
int Fib::next(){
	return g+f;
}
int Fib::prev(){
	return f;
}

int main(){
	int n = 6;
	Fib F(n);
	cout<<F.get()<<endl;
	cout<<F.next()<<endl;
	cout<<F.prev()<<endl;
	return 0;
}
