#include <iostream>
#define MAXSIZE 1000000 //��̫���ڽӱ�����ֱ������ʱϵͳ�Ῠ ����̬�������� �ɽ� 
using namespace std;
int maxl = 1;
//const int MAXSIZE = 100;
//ͼ�ṹ-�ڽӱ� 

//�߱���               //ָ��---��̬�� 
struct EdgeNode{
	int data;
	EdgeNode* next;  //��һ��ö��������� 
};
//����
struct VectexNode{
	int data;
	int in;  //��� 
	int length;  //����-·�������� 
	EdgeNode* firstnode; //��һ����ö��������Ķ��� 
}; 
class Graph{
	private:
		//VectexNode V[MAXSIZE];  //�ڽӱ� 
		VectexNode* V = new VectexNode[MAXSIZE]; 
		int vec_num;
		int edge_num;
	public:
		Graph(int n, int m){
			for(int i = 0;i<n;i++){
				V[i].data = i;   //�������� 
				V[i].firstnode = NULL; //��ʼ�ޱ� 
				V[i].in = 0;
				V[i].length = 1;
			}
			vec_num = n;
			edge_num = m;
		}
		void addedge(int start, int end){
			EdgeNode *e = new EdgeNode;
			e->data = end-1;
			e->next = NULL; 
			if (V[start-1].firstnode!=NULL){
				EdgeNode *p = V[start-1].firstnode;
				while(p->next!=NULL){
					p = p->next;  //�����һ��������֮����� 
				}
				p->next = e;
			}
			else{
				V[start-1].firstnode = e;
			}
			V[end-1].in ++;
		}
		void toposort(){
			int* stack = new int[MAXSIZE];  //����+sizeά��ջ�ṹ 
			int size=0;                      //ע��ջ��λ�ú�size�Ĺ�ϵ��Ӧ 
			for (int i = 0;i<vec_num;i++){  //���Ϊ�����ջ 
				if(V[i].in == 0){
					size++;
					stack[size-1] = i;
					
					//cout<<"."<<endl;
				}
			}
			while(size!=0){
				//cout<<","<<endl;
				int index = stack[size-1];  //ȡջ���� 
				size--;
				int l = V[index].length + 1;
				for(EdgeNode* p = V[index].firstnode;p!=NULL;p=p->next){  //���������ڵ� 
				    int  temp =  p->data;
					V[temp].in--;        
					//cout<<V[temp].length<<" "<<l<<endl;                            //�ڵ����-1���൱��ɾ���õ� 	
					if (l > V[temp].length){         //��̬�滮 
						V[temp].length = l;
					}
					if(l>maxl){
						maxl = l;
					}
					if(V[temp].in==0){  //�ڵ����Ϊ����ջ 
					    size++;
						stack[size-1]=temp;
						
						
					}
				}
			} 
		} 
}; 
int main(){
	int n,m;	
	scanf("%d %d",&n,&m);
	Graph tsp(n,m);
	for(int i = 0;i<m;i++){
		int start , end;
		scanf("%d %d",&start,&end);
		tsp.addedge(start,end);
	}
	//tsp.printA();
	//cout<<maxl<<endl;
	tsp.toposort();
	cout<<maxl<<endl;
	return 0;
}
