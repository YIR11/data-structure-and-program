#include <iostream>
#define MAXSIZE 1000000 //数太大，邻接表数组直接生成时系统会卡 ，动态分配数组 可解 
using namespace std;
int maxl = 1;
//const int MAXSIZE = 100;
//图结构-邻接表 

//边表顶点               //指针---动态性 
struct EdgeNode{
	int data;
	EdgeNode* next;  //下一与该顶点相连点 
};
//顶点
struct VectexNode{
	int data;
	int in;  //入度 
	int length;  //长度-路径顶点数 
	EdgeNode* firstnode; //第一个与该顶点相连的顶点 
}; 
class Graph{
	private:
		//VectexNode V[MAXSIZE];  //邻接表 
		VectexNode* V = new VectexNode[MAXSIZE]; 
		int vec_num;
		int edge_num;
	public:
		Graph(int n, int m){
			for(int i = 0;i<n;i++){
				V[i].data = i;   //顶点数据 
				V[i].firstnode = NULL; //初始无边 
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
					p = p->next;  //在最后一个相连点之后插入 
				}
				p->next = e;
			}
			else{
				V[start-1].firstnode = e;
			}
			V[end-1].in ++;
		}
		void toposort(){
			int* stack = new int[MAXSIZE];  //数组+size维护栈结构 
			int size=0;                      //注意栈顶位置和size的关系对应 
			for (int i = 0;i<vec_num;i++){  //入度为零点入栈 
				if(V[i].in == 0){
					size++;
					stack[size-1] = i;
					
					//cout<<"."<<endl;
				}
			}
			while(size!=0){
				//cout<<","<<endl;
				int index = stack[size-1];  //取栈顶点 
				size--;
				int l = V[index].length + 1;
				for(EdgeNode* p = V[index].firstnode;p!=NULL;p=p->next){  //遍历所有邻点 
				    int  temp =  p->data;
					V[temp].in--;        
					//cout<<V[temp].length<<" "<<l<<endl;                            //邻点入度-1，相当于删除该点 	
					if (l > V[temp].length){         //动态规划 
						V[temp].length = l;
					}
					if(l>maxl){
						maxl = l;
					}
					if(V[temp].in==0){  //邻点入度为零入栈 
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
