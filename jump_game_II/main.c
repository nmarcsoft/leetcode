#include <stdio.h>

int jump(int* nums, int numsSize) {

    if (numsSize == 1)
        return 0;

    if (numsSize == 2)
        return 1;

    int toReturn = 0;
    int i = 0;
    int j = nums[i];
    int maxId = 0;

    while (i < numsSize)
    {
        // make a jump
        for (int k = i; k <= j; k++)
        {
            if (nums[k] > nums[i])
            {
                i = k;
            }
        }
        toReturn++;
        j = nums[i] + j;
        if (j >= numsSize - 1)
            return ++toReturn;

    }
    return toReturn;
}

int main(void)
{
    int nums[5] = {2, 3, 1, 1, 4};
    printf("%d(2)\n", jump(nums, 5));

    int nums2[5] = {2, 3, 0, 1, 4};
    printf("%d(2)\n", jump(nums2, 5));

    int nums3[5] = {2, 1, 1, 1, 1};
    printf("%d(3)\n", jump(nums3, 5));

    return 0;
}
