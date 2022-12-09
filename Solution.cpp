
#include <array>
#include <string>
using namespace std;

class Solution {
    
    inline static const int PALINDROME_LENGTH = 5;
    inline static const int MODULO = pow(10, 9) + 7;

public:
    int countPalindromes(string input) const {
        long totalPalindromesWithLengthFive = 0;

        for (int first = 0; first <= 9; ++first) {
            for (int second = 0; second <= 9; ++second) {

                array<int, PALINDROME_LENGTH> palindrome{ first, second, 0, second, first};
                array<long, PALINDROME_LENGTH + 1> memo{ 0, 0, 0, 0, 0, 1};

                for (int i = 0; i < input.length(); ++i) {
                    for (int n = 0; n < PALINDROME_LENGTH; ++n) {

                        int digit = input[i] - '0';
                        if (digit == palindrome[n] || n == 2) {
                            memo[n] = (memo[n] + memo[n + 1]) % MODULO;
                        }
                    }
                }
                totalPalindromesWithLengthFive = (totalPalindromesWithLengthFive + memo[0]) % MODULO;
            }
        }
        return totalPalindromesWithLengthFive;
    }
};
