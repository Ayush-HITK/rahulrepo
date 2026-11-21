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
--------
#include<stdio.h>
void heapify(int a[],int n,int i){
    int l=2*i+1,r=2*i+2,largest=i,t;
    if(l<n&&a[l]>a[largest])largest=l;
    if(r<n&&a[r]>a[largest])largest=r;
    if(largest!=i){
        t=a[i];a[i]=a[largest];a[largest]=t;
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n){
    int i,t;
    for(i=n/2-1;i>=0;i--)heapify(a,n,i);
    for(i=n-1;i>0;i--){
        t=a[0];a[0]=a[i];a[i]=t;
        heapify(a,i,0);
    }
}
int main(){
    int a[100],n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    heapSort(a,n);
    printf("Sorted array: ");
    for(i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}
-----------
#include<stdio.h>
#define SIZE 10
int h[SIZE];
void insert(int x){
    int i=x%SIZE,j;
    for(j=0;j<SIZE;j++){
        if(h[(i+j)%SIZE]==-1){
            h[(i+j)%SIZE]=x;
            return;
        }
    }
    printf("Hash Table Full\n");
}
void display(){
    int i;
    for(i=0;i<SIZE;i++)
        printf("%d : %d\n",i,h[i]);
}
int main(){
    int i,n,x;
    for(i=0;i<SIZE;i++)h[i]=-1;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insert(x);
    }
    display();
    return 0;
}
---------
#include<stdio.h>
int h[100],n=0;
void insert(int x){
    int i=n++;
    while(i>0&&h[(i-1)/2]<x){
        h[i]=h[(i-1)/2];
        i=(i-1)/2;
    }
    h[i]=x;
}
void delete(){
    int i=0,x;
    if(n==0){printf("Empty\n");return;}
    printf("Deleted: %d\n",h[0]);
    x=h[--n];
    while(2*i+1<n){
        int c=2*i+1;
        if(c+1<n&&h[c+1]>h[c])c++;
        if(h[c]<=x)break;
        h[i]=h[c];
        i=c;
    }
    h[i]=x;
}
void display(){
    int i;
    for(i=0;i<n;i++)printf("%d ",h[i]);
}
int main(){
    int ch,x;
    while(1){
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                scanf("%d",&x);
                insert(x);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice");
        }
    }
}
-----------
#include<stdio.h>
void quick(int a[],int low,int high){
    int i=low,j=high,p=a[low],t;
    if(low>=high)return;
    while(i<j){
        while(a[i]<=p&&i<high)i++;
        while(a[j]>p)j--;
        if(i<j){
            t=a[i];a[i]=a[j];a[j]=t;
        }
    }
    a[low]=a[j];
    a[j]=p;
    quick(a,low,j-1);
    quick(a,j+1,high);
}
int main(){
    int a[100],n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    quick(a,0,n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}
---------
#include<stdio.h>
void merge(int a[],int l,int m,int r){
    int b[100],i=l,j=m+1,k=l;
    while(i<=m&&j<=r){
        if(a[i]<a[j])b[k++]=a[i++];
        else b[k++]=a[j++];
    }
    while(i<=m)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    for(i=l;i<=r;i++)a[i]=b[i];
}
void sort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main(){
    int a[100],n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,0,n-1);
    printf("Sorted array: ");
    for(i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}
---------
#include<stdio.h>
int getMax(int a[],int n){
    int m=a[0],i;
    for(i=1;i<n;i++)
        if(a[i]>m)m=a[i];
    return m;
}
void countSort(int a[],int n,int exp){
    int b[100],c[10]={0},i;
    for(i=0;i<n;i++)c[(a[i]/exp)%10]++;
    for(i=1;i<10;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)
        b[--c[(a[i]/exp)%10]]=a[i];
    for(i=0;i<n;i++)a[i]=b[i];
}
void radixSort(int a[],int n){
    int m=getMax(a,n),exp;
    for(exp=1;m/exp>0;){
        countSort(a,n,exp);
        if(exp>m/10)break;
        exp*=10;
    }
}
int main(){
    int a[100],n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    radixSort(a,n);
    printf("Sorted array: ");
    for(i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}
------
#include<stdio.h>
#include<string.h>
#define N 50
#define L 100

void radixSort(char a[][L],int n){
    char b[N][L];
    int i,j,k,max=0,c[257],pos;
    for(i=0;i<n;i++)
        if(strlen(a[i])>max)max=strlen(a[i]);

    for(pos=max-1;pos>=0;pos--){
        for(i=0;i<257;i++)c[i]=0;
        for(i=0;i<n;i++){
            k=pos<strlen(a[i])?(unsigned char)a[i][pos]+1:0;
            c[k]++;
        }
        for(i=1;i<257;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--){
            k=pos<strlen(a[i])?(unsigned char)a[i][pos]+1:0;
            strcpy(b[--c[k]],a[i]);
        }
        for(i=0;i<n;i++)strcpy(a[i],b[i]);
    }
}
int main(){
    char a[N][L];
    int n,i;
    printf("Enter number of words: ");
    scanf("%d",&n);
    printf("Enter words: ");
    for(i=0;i<n;i++)scanf("%99s",a[i]);
    radixSort(a,n);
    printf("Sorted words:\n");
    for(i=0;i<n;i++)printf("%s\n",a[i]);
    return 0;
}