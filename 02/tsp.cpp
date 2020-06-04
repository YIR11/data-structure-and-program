#include <iostream>
#define MAXSIZE 1000000 //��̫���ڽӱ�����ֱ������ʱϵͳ�Ῠ ����̬�������� �ɽ� 
using namespace std;
//const int MAXSIZE = 100;
//ͼ�ṹ-�ڽӱ� 

//�߱���
struct EdgeNode{
	int data;
	EdgeNode* next;
};
//����
struct VectexNode{
	int data;
	EdgeNode* firstnode;
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
				V[i].data = i+1;   //�������� 
				V[i].firstnode = NULL; //��ʼ�ޱ� 
			}
			vec_num = n;
			edge_num = m;
		}
		void addedge(int start, int end){
			EdgeNode *e = new EdgeNode;
			e->data = end-1;
			e->next = NULL; 
			if (V[start-1].firstnode){
				EdgeNode *p = V[start-1].firstnode;
				while(p->next){
					p = p->next;
				}
				p->next = e;
			}
			else{
				V[start-1].firstnode = e;
			}
		}
		void printA(){
			EdgeNode* a = V[0].firstnode;
			while (a){
				cout<<a->data<<endl;
				a = a->next;
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
	tsp.printA();
	return 0;
}
