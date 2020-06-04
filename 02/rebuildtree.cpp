//树的重构
#include <iostream>
#define MAXSIZE 4000000
using namespace std;
int pl[MAXSIZE], ll[MAXSIZE];

//结点类 
struct BinNode{
	int data;      //数据域 
	//BinNode* parent;//父节点，该处不需要 
	BinNode* lc;  //左右子节点 
	BinNode* rc;
	BinNode(int e,  BinNode* l = NULL,BinNode* r = NULL ):data(e),lc(l),rc(r){}//构造函数，左右子节点默认为空 
}; 

int position(int A[],int start,int end,int e){
	for(int i=start;i<end;i++){
		if (A[i]==e){
			return i;
			break;
		}
	}
}


BinNode* buildtree( int pstart, int pend,  int lstart, int lend){
	
	BinNode *root = new BinNode(pl[pstart]);       //确定根节点 
	
    if(pstart >= pend-1|| lstart>=lend-1){         //若序列中只有一点，即返回根节点 ；递归的终止条件 
    	return root;
	}
    else{	
	    int div_pos1 = position(pl,pstart,pend,ll[lend-2]);  //确定序列中左右子树的分界 
	    int div_pos2 = position(ll,lstart,lend,pl[pstart+1]);
	    //int l_length = div_pos1 - pstart-1;
	    root->lc = buildtree(pstart+1,div_pos1,  lstart,div_pos2+1);  //以左子树的根节点作root的左子结点 ，递归深入 
	    root->rc = buildtree(div_pos1,pend,  div_pos2+1,lend-1);
	    return root;       //递归结束，返回root 
	}
	
}
///想着递归语句，指代的是整个函数代码段，进入了函数栈中，后进先出调用，想象执行过程 
void travin(BinNode* s){  //中序遍历 
	if(!s){
		return;
	}
	travin(s->lc);
	//cout<<s->data<<" ";
	printf("%d ",s->data);
	travin(s->rc);
}

int main(){
	int length;
	cin>>length;
	
	for (int i = 0;i<length;i++){
		//cin>>pl[i];;
		scanf("%d",&pl[i]);
	}
	for (int i = 0;i<length;i++){
		scanf("%d",&ll[i]);
	}
	 
	BinNode *root = buildtree(0,length,  0,length);
	travin(root);
	return 0;
}
