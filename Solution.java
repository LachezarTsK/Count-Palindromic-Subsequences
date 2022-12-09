
public class Solution {

    private static final int PALINDROME_LENGTH = 5;
    private static final int MODULO = (int) Math.pow(10, 9) + 7;

    public int countPalindromes(String input) {
        long totalPalindromesWithLengthFive = 0;

        for (int first = 0; first <= 9; ++first) {
            for (int second = 0; second <= 9; ++second) {

                int[] palindrome = {first, second, 0, second, first};
                long[] memo = {0, 0, 0, 0, 0, 1};

                for (int i = 0; i < input.length(); ++i) {
                    for (int n = 0; n < PALINDROME_LENGTH; ++n) {

                        int digit = input.charAt(i) - '0';
                        if (digit == palindrome[n] || n == 2) {
                            memo[n] = (memo[n] + memo[n + 1]) % MODULO;
                        }
                    }
                }
                totalPalindromesWithLengthFive = (totalPalindromesWithLengthFive + memo[0]) % MODULO;
            }
        }
        return (int) totalPalindromesWithLengthFive;
    }
}
