#include<stdio.h>
#include<malloc.h>

inline void Merge(int *A, int *TmpA, int Lpos, int Rpos, int RightEnd, int *S){
    int i, LeftEnd = Rpos - 1, N = RightEnd - Lpos + 1, TmpPos = Lpos;
    while(Lpos <= LeftEnd && Rpos <= RightEnd){
        if(A[Lpos] <= A[Rpos]){
            TmpA[TmpPos++] = A[Lpos++];
        } else {
            *S += LeftEnd - Lpos + 1;
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
inline void Msort(int *A, int *TmpA, int Left, int Right, int *S){
    int Center;
    if(Left < Right){
        Center = (Left + Right) / 2;
        Msort(A, TmpA, Left, Center, S);
        Msort(A, TmpA, Center + 1, Right, S);
        Merge(A, TmpA, Left, Center + 1, Right, S);
    }
}

void Mergesort(int *A, int N, int *S){
    int *TmpA = (int*)malloc(N * 4);
    Msort(A, TmpA, 0, N - 1, S);
    free(TmpA);
}

int main(){
    int A[1000], N = 0, i, Sum = 0, *S = &Sum;
    do{
        scanf("%d", A + N);
        N++;
    } while(',' == getchar());
    Mergesort(A, N, S);
    /*
    for(i = 0;i < N - 1;i++)
        printf("%d,", A[i]);
    printf("%d", A[i]);
    */
    printf("\n%d", *S);
    return 0;
}