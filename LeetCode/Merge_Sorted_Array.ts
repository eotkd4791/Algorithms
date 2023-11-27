function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    let lastIndex = m + n - 1;
    while(n > 0) {
        nums1[lastIndex--] = nums2[--n];
    }
    nums1.sort((a, b) => a - b);
};
