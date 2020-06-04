#include<cstdio>
#define MAXSIZE 4000000
struct node{
	int data;
	 node *lc,*rc;	
};
int pre[MAXSIZE],post[MAXSIZE],i,j,k,m,n,e;//定义前序和后序数组 
node *ProperRebuild(int pre_lo,int pre_hi,int post_lo,int post_hi){//传入前序和后序递归范围 
	node *root=new node;//创建新节点 
	root->data=pre[pre_lo];//以新节点为根，数据域为前序最左端的数据 
	root->lc=root->rc=NULL;//其左右子树初始化为空 
	int pos,num_left;//定义前序左子树根在后序中的位置，左子树节点数 	
	if(post_lo==post_hi)return root;//若后序范围长度为0，返回当前根节点 
	for(i=post_lo;i<=post_hi;i++)//遍历给定范围的后序 
	if(post[i]==pre[pre_lo+1]){//若前序最左端+1即当前左子树根节点等于后序节点	
		pos=i;
		break;//记录左子树根节点在后序中的位置并退出循环 
	}
	num_left=pos-post_lo+1;//计算左子树节点数 
root->lc=ProperRebuild(pre_lo+1,pre_lo+num_left,post_lo,pos);//递归地在左子树中寻找当前节点的左孩子 
root->rc=ProperRebuild(pre_lo+num_left+1,pre_hi,pos+1,post_hi-1);//递归地在右子树中寻找当前节点的右孩子 
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
