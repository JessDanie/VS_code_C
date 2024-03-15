#include<stdio.h>

int main(){
    FILE * f = fopen("a", "w");
    char t[100];
    gets(t);
    fputs(t, f);
    fclose(f);
    f = fopen("a", "r");
    int l, d, q, p[100] = {0}, c[100] = {0}, r[100] = {0}, i = 0, j, max = 0;
    fscanf(f, "%d;", &l);
    while(~fscanf(f, "%d,%d;", &d, &q)){
        p[d] = q;
    }
    fclose(f);
    for(i = 1;i <= l;i++){
        q = p[i];
        r[i] = i;
        for(j = 1;j < i;j++){
            if(q < p[j] + c[i - j]){
                q = p[j] + c[i - j];
                r[i] = j;
            }
        }
        c[i] = q;
    }
    while(l > 0){
        //max += p[r[l]];
        printf("%d ", r[l]);
        l -= r[l]; 
    }
    printf("%d", max);
}
//10;1,1;2,5;3,8;4,9;5,10;6,17;7,17;8,20;9,24;10,24;"};
//10;1,1;2,5;3,8;4,9;5,10;6,17;7,17;8,20;9,24;10,30;"};