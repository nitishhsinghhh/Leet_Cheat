int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize=2;
    int *returna=(int*)malloc(2*(sizeof(int)));
    for(int i=0;i<numsSize;i++) {
        for(int j=i+1;j<numsSize;j++) {
            int def[2] = {i,j};
            if(nums[i]+nums[j]==target)
                memcpy(returna, def, sizeof(def));
        }
    }
    return returna;
}
