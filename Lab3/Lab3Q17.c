#include <stdio.h>

int countMatches(int n, int data[], int searchValue);

int main()
{
  //  int nums[] = {1, 2, 3, 4, 1, 1, 5};
   // printf("%d\n", countMatches(7, nums, 1));

    int nums[] = {10, 20, 30};
    printf("%d\n", countMatches(3, nums, 1));

}

int countMatches(int n, int data[], int searchValue)
{
    int i = 0;
    int counts = 0;

    for (i = 0; i <= (n - 1); i++) {
        if (data[i] == searchValue) {
            counts += 1;
        }
    }
    return counts;
}
