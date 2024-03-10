#include <stdio.h>

void findTwoMinIndexes(int arr[], int size, int *index1, int *index2) {
    *index1 = *index2 = -1; // 初始化为无效的下标 -1

    for (int i = 0; i < size; ++i) {
        if (*index1 == -1 || arr[i] < arr[*index1]) {
            *index2 = *index1;
            *index1 = i;
        } else if (*index2 == -1 || arr[i] < arr[*index2]) {
            *index2 = i;
        }
    }
}

int main() {
    int arr[256]; // 假设数组的大小为256
    // 填充数组（这里简单地用递减序列填充）
    for (int i = 0; i < 256; ++i) {
        arr[i] = 300 - i; // 0到255的递减序列
    }
    arr[10]=1;
    arr[15]=0;
    int index1, index2;
    findTwoMinIndexes(arr, 256, &index1, &index2);

    printf("最小的两个数的下标为 %d 和 %d\n", index1, index2);

    return 0;
}
