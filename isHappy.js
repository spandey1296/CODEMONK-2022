/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1(where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/




/**
 * Slow Fast
 * Time O(log(N)) | Space O(1)
 * @param {number} n
 * @return {boolean}
 */
var isHappy = (n) => {
    let [slow, fast] = [n, getNext(n)];
    const hasCycle = () => ((fast === 1) || (slow === fast));
    while (!hasCycle()) {
        slow = getNext(slow);
        fast = getNext(getNext(fast));
    }
    return (fast === 1)

};

var getNext = (n, sum = 0) => {
    while (0 < n) {
        const remainder = (n % 10);
        n = Math.floor(n / 10);
        sum += (remainder * remainder)
    }
    return sum
}
console.log(isHappy(32)) // returns true
console.log(isHappy(50)) // retuns false
console.log(isHappy(99)) // retuns false
console.log(isHappy(44)) // returns true
