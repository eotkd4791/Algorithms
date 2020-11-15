const twoSum = (nums, target) => {
    const obj = {};
    let ans = [];
    
    nums.forEach((v, i) => {
        obj.hasOwnProperty(v)
            ? ans.push(obj[v], i)
            : obj[target - v] = i;
    });
    return ans;
};
