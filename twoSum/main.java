class Solution {
    public int[] twoSum(int[] nums, int target) {
    int[] toReturn = new int[2];
    boolean found = false;
    int i = 0;
    int len = nums.length;

    while (i < len && !found)
    {
        int j = i + 1;

        while (j < len && !found)
        {
            if (nums[i] + nums[j] == target)
            {
                toReturn[0] = i;
                toReturn[1] = j;
                found = true;
            }
            j++;
        }
        i++;
    }
    return toReturn;
    }
}
