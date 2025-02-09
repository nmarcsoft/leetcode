#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            // remove in line
            *nums = *(nums + 1);
        }
        else {
            k++;
        }
    }

    return k;
}

void print_tab(int *nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("nums[%d] = %d\n", i, nums[i]);
    }
}

int main(void)
{
    int *nums = malloc(sizeof(int) * 5);
    nums[0] = 5;
    nums[1] = 2;
    nums[2] = 2;
    nums[3] = 1;
    nums[4] = 4;

    print_tab(nums, 5);
    printf("remove element returned = %d\n", removeElement(nums, 5, 2));
    print_tab(nums, 3);
}
