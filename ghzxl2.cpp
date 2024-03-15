#include <stdio.h>
#include <algorithm>
using namespace std;

inline int seek(int *s, int a, int b, int key){
    int min = a, mid, max = b - 1;
    while (min <= max){
        mid = (min + max) / 2;
        if (s[mid] <= key && key < s[mid + 1]){
            return mid;
        } else if (key < s[mid]){
            max = mid - 1;
        } else if (key >= s[mid + 1]){
            min = mid + 1;
        } 
    }
    return b - 1;
}
//2 2 3 3 4 5 6
int main(){
    int n, i, nums[200000] = {0}, result = 0, key;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", nums + i);
    if (n < 2){
        putchar('0');
        return 0;
    }
    sort(nums, nums + n);
    for(i = 0;i < n;i++){
        key = seek(nums, i, n, 2 * nums[i]);
        if(key - i > result)
            result = key - i;
    }
    printf("%d", result + 1);
    return 0;
}