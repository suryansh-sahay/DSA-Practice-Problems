var nextGreaterElements = function(nums) {
    const n = nums.length;
    const res = Array(n).fill(-1);
    const stack = [];

    for (let i = 0; i < 2 * n; i++) {
        const num = nums[i % n];
        while (stack.length && nums[stack[stack.length - 1]] < num) {
            res[stack.pop()] = num;
        }
        if (i < n) stack.push(i);
    }

    return res;
};