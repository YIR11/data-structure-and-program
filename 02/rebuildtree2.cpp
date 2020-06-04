#include<cstdio>
#define MAXSIZE 4000000
struct node{
	int data;
	 node *lc,*rc;	
};
int pre[MAXSIZE],post[MAXSIZE],i,j,k,m,n,e;//����ǰ��ͺ������� 
node *ProperRebuild(int pre_lo,int pre_hi,int post_lo,int post_hi){//����ǰ��ͺ���ݹ鷶Χ 
	node *root=new node;//�����½ڵ� 
	root->data=pre[pre_lo];//���½ڵ�Ϊ����������Ϊǰ������˵����� 
	root->lc=root->rc=NULL;//������������ʼ��Ϊ�� 
	int pos,num_left;//����ǰ�����������ں����е�λ�ã��������ڵ��� 	
	if(post_lo==post_hi)return root;//������Χ����Ϊ0�����ص�ǰ���ڵ� 
	for(i=post_lo;i<=post_hi;i++)//����������Χ�ĺ��� 
	if(post[i]==pre[pre_lo+1]){//��ǰ�������+1����ǰ���������ڵ���ں���ڵ�	
		pos=i;
		break;//��¼���������ڵ��ں����е�λ�ò��˳�ѭ�� 
	}
	num_left=pos-post_lo+1;//�����������ڵ��� 
root->lc=ProperRebuild(pre_lo+1,pre_lo+num_left,post_lo,pos);//�ݹ������������Ѱ�ҵ�ǰ�ڵ������ 
root->rc=ProperRebuild(pre_lo+num_left+1,pre_hi,pos+1,post_hi-1);//�ݹ������������Ѱ�ҵ�ǰ�ڵ���Һ��� 
	return root;
}
void InTraverse(node *root){
	if(!root)return;
	InTraverse(root->lc);
	printf("%d ",root->data);
	InTraverse(root->rc);
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&pre[i]);
	for(i=0;i<n;i++)scanf("%d",&post[i]);
	node *r=ProperRebuild(0,n-1,0,n-1);
	InTraverse(r);
	return 0;
}
