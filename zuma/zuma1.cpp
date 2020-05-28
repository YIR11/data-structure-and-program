#include <iostream>
using namespace std;

int length(char* s){
	int size = 0;
	while(*s!='\0'){
		s++;
		size++;
	}
	return size;
}

class zuma{
	private:
		int size;
		char *str;
	public:
		zuma(char *s){
			str = s;
			size = length(str);    //不算‘/0’ 
		}
		void show(){
			if (size!=0){
				//cout<<str<<endl;
			    //cout<<size<<endl;
			    for (int i =0;i<size;i++){
			    	cout<<str[i];
				}
				cout<<endl;
			}
			else{
				cout<<'-'<<endl;
			}

		}
		void insert(int index, char const &s){
			for (int i = size+1;i>index;i--){  //考虑str末尾的‘/0’ 
				str[i] = str[i-1];
			}
			str[index] = s;
			size++;
		}
		void remove(int lo,int hi){
			while(hi<=size){
				str[lo++]=str[hi++];
			}
			//cout<<"r";
			size = lo-1;
		}
		int check(int index,char const &s){
			int left = ((index-2)>0)? (index-2):0;
			int right = ((index+2)>size)? size:(index+2);
			for(int i = left;i<=index&&(i+2)<=right;i++){
				int k = 1;
				while(str[i]==str[i+k]){
					k++;
				} 
				if(k>=3){
					remove(i,i+k);
					return i;
					break;
				}
			}
			return -1;   //不能用0，index可能是0 
		}
		
		void iter_check(int index,char const &s){
			int change = index;
			while(change!=-1){
				change = check(change,s);
			}
		}
};

int main(){
	char str[100000];
	cin>>str;
    zuma z(str);
    //z.show();
    int num;
    cin>>num;
    for (int i = 0;i<num;i++){
    	int index;
	    char s;
	    cin>>index>>s;
	    z.insert(index,s);
	    //z.show();
	    
	    z.iter_check(index,s);
	    z.show();
	}

	return 0;
}
