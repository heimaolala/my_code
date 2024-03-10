#include <stdio.h>
int main()
{
    int n=0;
    char arr[100][2] = {0};
    scanf_s("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf_s("%c", &arr[i][0]);
        while(1)
        {
            scanf_s("%c", &arr[i][1]);
            if (arr[i][0] >= 'A' && arr[i][0] <= 'Z' && (arr[i][1] == arr[i][0] + 32 || arr[i][1] == arr[i][0] + 1))
            {
                arr[i][0] = arr[i][1];
            }
            else if (arr[i][0] >= 'a' && arr[i][0] <= 'z' && (arr[i][1] == arr[i][0] - 32 || arr[i][1] == arr[i][0] - 1))
            {
                arr[i][0] = arr[i][1];
            }
            else if (arr[i][1] == '\n')
            {
                printf("Y\n");
                break;
            }
            else
            {
                printf("N\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            }
        }
    }
    return 0;
}