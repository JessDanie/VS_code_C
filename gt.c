#include<stdio.h>

int main(){
    int i = 0, n;
    short s, a, b, h, N = 0, S[101] = {0};//初始化S为0
    scanf("%d%hd\n%hd%hd", &n, &s, &a, &b);
    h = a + b;
    for(i = 0;i < n;i++){
        scanf("%hd,%hd", &a, &b);
        S[b]++;
    }
    a = b = 0;//a:n  b<=s
    for(i = 0;i < N;i++){
        if((h = b + S[i] * i) >= s){ 
            a += (s - b) ? (int)((s - b) / i) : 0;
            //b += h * S[i];
            break;
        }
        a += S[i];
        b = h;
    }
    printf("%d", a);
    return 0;
}