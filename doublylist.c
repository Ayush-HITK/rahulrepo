#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* create(int x){
    struct node *p=malloc(sizeof(struct node));
    p->data=x;
    p->left=p->right=NULL;
    return p;
}
struct node* insert(struct node *r,int x){
    if(r==NULL)return create(x);
    if(x<r->data)r->left=insert(r->left,x);
    else if(x>r->data)r->right=insert(r->right,x);
    return r;
}
void inorder(struct node *r){
    if(r){inorder(r->left);printf("%d ",r->data);inorder(r->right);}
}
void preorder(struct node *r){
    if(r){printf("%d ",r->data);preorder(r->left);preorder(r->right);}
}
void postorder(struct node *r){
    if(r){postorder(r->left);postorder(r->right);printf("%d ",r->data);}
}
struct node* search(struct node *r,int x){
    if(r==NULL||r->data==x)return r;
    if(x<r->data)return search(r->left,x);
    return search(r->right,x);
}
struct node* delete(struct node *r,int x){
    if(r==NULL)return NULL;
    if(x<r->data)r->left=delete(r->left,x);
    else if(x>r->data)r->right=delete(r->right,x);
    else{
        if(r->left==NULL){
            struct node *t=r->right;
            free(r);
            return t;
        }
        if(r->right==NULL){
            struct node *t=r->left;
            free(r);
            return t;
        }
        struct node *t=r->right;
        while(t->left)t=t->left;
        r->data=t->data;
        r->right=delete(r->right,t->data);
    }
    return r;
}
int main(){
    struct node *root=NULL;
    int ch,x,n,i;
    while(1){
        printf("\n1.Create\n2.Insert\n3.Inorder\n4.Preorder\n5.Postorder\n6.Delete\n7.Search\n8.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                root=NULL;
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    scanf("%d",&x);
                    root=insert(root,x);
                }
                break;
            case 2:
                scanf("%d",&x);
                root=insert(root,x);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                scanf("%d",&x);
                root=delete(root,x);
                break;
            case 7:
                scanf("%d",&x);
                if(search(root,x))printf("Found");
                else printf("Not Found");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }
}
------------
#include<stdio.h>
int main(){
    int a[20][20],q[20],v[20]={0};
    int n,s,f=0,r=-1,i,j;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d",&s);
    q[++r]=s;
    v[s]=1;
    printf("BFS: ");
    while(f<=r){
        s=q[f++];
        printf("%d ",s);
        for(i=1;i<=n;i++){
            if(a[s][i]&&!v[i]){
                q[++r]=i;
                v[i]=1;
            }
        }
    }
    return 0;
}
----------
#include<stdio.h>
int a[20][20],v[20]={0},n;
void dfs(int s){
    int i;
    printf("%d ",s);
    v[s]=1;
    for(i=1;i<=n;i++)
        if(a[s][i]&&!v[i])
            dfs(i);
}
int main(){
    int i,j,s;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter starting vertex: ");
    scanf("%d",&s);
    printf("DFS: ");
    dfs(s);
    return 0;
}