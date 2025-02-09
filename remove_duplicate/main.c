#include <stdio.h>

int printArray(int* nums)
{
    int i = 0;
    while (nums[i] != '\0')
    {
        printf("[%d] = %d", i, nums[i]);
        i++;
    }
}

int offset(int* nums, int numSize, int index)
{
    for (int i = numSize - 1; i > index; i--)
    {
        nums[i - 1] = nums[i];
    }
}

int removeDuplicates(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            offset(nums, numsSize, i);
            numsSize--;
        }
        printf("%d\n", nums[i]);
    }
    return 1;
}



int main(void)
{
    int nums[3] = { 1, 1, 2 };
    removeDuplicates(nums, 3);
    printArray(nums);
}