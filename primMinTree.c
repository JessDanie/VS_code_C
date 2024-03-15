#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
struct B {
    int p, s;
    struct B* next;
};

struct A{
    struct B* BH;
    bool visit;
};

void AaddB(struct A* A,  int n, int m, int s){
    struct B* B= A[n].BH;
    A[n].BH = (struct B*)malloc(sizeof(struct B));
    A[n].BH->next = B;
    A[n].BH->p = m;
    A[n].BH->s = s;
}
struct A* creatT(int n){
    struct A* ATO= (struct A*)malloc(n * sizeof(struct A));
    for(int i=0;i<n;i++)
        ATO[i].BH = NULL;
    int i, j, s;
    printf("几条路\n");
    int o;
    scanf("%d", &o);
    for(int z = 0;z < o;z++){
        scanf("%d%d%d", &i, &j, &s);
        AaddB(ATO, i, j, s);
    }
    return ATO;
}

int  findmin(int n, int** H){
    int min_i, min=1000;
    for(int i=0;i<n;i++){
        if(H[i][0]<min&&H[i][2]){
            min=H[i][0];
            min_i = i;
        }
    }
    return min_i;
}

void path(int**H, int start, int end){
    int sum =0;
    for(int i = end;i!=start;i=H[i][1]){
        sum+=H[i][0];
        printf("%d<-[%d]<-", i, H[i][0]);
    }
    printf("%d=%d", start, H[end][0]);
}

void Dijkstra(struct A* A, int Alen, int start){
    int **H = (int **)malloc(sizeof(int*)*Alen);
    for(int i=0;i<Alen;i++){
        H[i] = (int*)malloc(sizeof(int)*3);
        H[i][2] = 1;
        H[i][0]=1000;
        H[i][1] = start;
    }
    for(struct B* b = A[start].BH;b;b=b->next){
        H[b->p][0] = b->s;
    }
        
    for(int i=1;i<Alen;i++){
        int k = findmin(Alen, H);
        H[k][2]=0;
        for(struct B* b = A[k].BH;b;b=b->next){
            if(b->s+H[k][0]<H[b->p][0]){
                H[b->p][0]=b->s+H[k][0];
                H[b->p][1]=k;
            }
        }
    }
    int e;
    printf("终点\n");
    scanf("%d", &e);
    path(H, start, e);
}



int main(){
    int n;
    scanf("%d", &n);
    struct A* A = creatT(n);
    printf("起点\n");
    int start;
    scanf("%d", &start);
    Dijkstra(A, n, start);
}