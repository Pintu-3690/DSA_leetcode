/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function (nums) {
  const counts = new Map();
  const threshold = Math.floor(nums.length / 3);
  const result = [];

  for (const num of nums) {
    counts.set(num, (counts.get(num) || 0) + 1);
  }

  for (const [num, count] of counts.entries()) {
    if (count > threshold) {
      result.push(num);
    }
  }

  return result;
};