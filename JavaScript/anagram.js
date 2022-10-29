
// example 

/**
 * Sort - HeapSort Space O(1) | QuickSort Space O(log(N))
 * Time O(N * logN) | Space O(N)
 * https://leetcode.com/problems/valid-anagram/
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
var isAnagram = (s, t) => {
    const isEqual = s.length === t.length;
    if (!isEqual) return false;

    return reOrder(s) === reOrder(t);
}

const reOrder = str => str
    .split('')
    .sort((a, b) => a.localeCompare(b))
    .join("");


console.log(isAnagram("mango", "goman"))  //returns true
console.log(isAnagram("rat", "tas"))    //returns false
console.log(isAnagram("parrot", "aorrpt")) //returns true
console.log(isAnagram("water", "terwe")) //returns false






