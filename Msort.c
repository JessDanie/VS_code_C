#include<stdio.h>
#include<malloc.h>

inline void Merge(int *A, int *TmpA, int Lpos, int Rpos, int RightEnd){
    int i, LeftEnd = Rpos - 1, N = RightEnd - Lpos + 1, TmpPos = Lpos;
    while(Lpos <= LeftEnd && Rpos <= RightEnd){
        if(A[Lpos] <= A[Rpos]){
            TmpA[TmpPos++] = A[Lpos++];
        } else {
            TmpA[TmpPos++] = A[Rpos++];
        }
    }
    while(Lpos <= LeftEnd)
        TmpA[TmpPos++] = A[Lpos++];
    while(Rpos <= RightEnd)
        TmpA[TmpPos++] = A[Rpos++];
    for(i = 0;i < N;i++, RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
}
inline void Msort(int *A, int *TmpA, int Left, int Right){
    int Center;
    if(Left < Right){
        Center = (Left + Right) / 2;
        Msort(A, TmpA, Left, Center);
        Msort(A, TmpA, Center + 1, Right);
        Merge(A, TmpA, Left, Center + 1, Right);
    }
}

void Mergesort(int *A, int N){
    int *TmpA = (int*)malloc(N * 4);
    Msort(A, TmpA, 0, N - 1);
    free(TmpA);
}

int main(){
    int A[1000], N = 0, i;
    do{
        scanf("%d", A + N);
        N++;
    } while(',' == getchar());
    Mergesort(A, N);
    for(i = 0;i < N - 1;i++)
        printf("%d,", A[i]);
    printf("%d", A[i]);
    return 0;
}