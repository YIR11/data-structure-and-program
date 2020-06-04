//�����ع�
#include <iostream>
#define MAXSIZE 4000000
using namespace std;
int pl[MAXSIZE], ll[MAXSIZE];

//����� 
struct BinNode{
	int data;      //������ 
	//BinNode* parent;//���ڵ㣬�ô�����Ҫ 
	BinNode* lc;  //�����ӽڵ� 
	BinNode* rc;
	BinNode(int e,  BinNode* l = NULL,BinNode* r = NULL ):data(e),lc(l),rc(r){}//���캯���������ӽڵ�Ĭ��Ϊ�� 
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
	
	BinNode *root = new BinNode(pl[pstart]);       //ȷ�����ڵ� 
	
    if(pstart >= pend-1|| lstart>=lend-1){         //��������ֻ��һ�㣬�����ظ��ڵ� ���ݹ����ֹ���� 
    	return root;
	}
    else{	
	    int div_pos1 = position(pl,pstart,pend,ll[lend-2]);  //ȷ�����������������ķֽ� 
	    int div_pos2 = position(ll,lstart,lend,pl[pstart+1]);
	    //int l_length = div_pos1 - pstart-1;
	    root->lc = buildtree(pstart+1,div_pos1,  lstart,div_pos2+1);  //���������ĸ��ڵ���root�����ӽ�� ���ݹ����� 
	    root->rc = buildtree(div_pos1,pend,  div_pos2+1,lend-1);
	    return root;       //�ݹ����������root 
	}
	
}
///���ŵݹ���䣬ָ������������������Σ������˺���ջ�У�����ȳ����ã�����ִ�й��� 
void travin(BinNode* s){  //������� 
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
