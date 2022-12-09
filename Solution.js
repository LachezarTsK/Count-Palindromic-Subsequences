
/**
 * @param {string} input
 * @return {number}
 */
var countPalindromes = function (input) {
    const PALINDROME_LENGTH = 5;
    const MODULO = Math.pow(10, 9) + 7;
    const ASCII_0 = 48;

    let totalPalindromesWithLengthFive = 0;

    for (let first = 0; first <= 9; ++first) {
        for (let second = 0; second <= 9; ++second) {

            const palindrome = [first, second, 0, second, first];
            const memo = [0, 0, 0, 0, 0, 1];

            for (let i = 0; i < input.length; ++i) {
                for (let n = 0; n < PALINDROME_LENGTH; ++n) {

                    let digit = input.codePointAt(i) - ASCII_0;
                    if (digit === palindrome[n] || n === 2) {
                        memo[n] = (memo[n] + memo[n + 1]) % MODULO;
                    }
                }
            }
            totalPalindromesWithLengthFive = (totalPalindromesWithLengthFive + memo[0]) % MODULO;
        }
    }
    return totalPalindromesWithLengthFive;
};
