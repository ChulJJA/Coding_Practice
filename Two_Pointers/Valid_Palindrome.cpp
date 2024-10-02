/*
A phrase is a palindrome if, after converting all uppercase letters into
lowercase letters and removing all non-alphanumeric characters, it reads the
same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;
class MySolution {
   public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;

        while (head < tail) {
            while (head < tail && !isalnum(s[head])) {
                ++head;
            }
            while (head < tail && !isalnum(s[tail])) {
                --tail;
            }

            if (tolower(s[head]) != tolower(s[tail])) {
                return false;
            }
            ++head;
            --tail;
        }
        return true;
    }
};

class BetterSolution {
   public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            else {
                start++;
                end--;
            }
        }
        return true;
    }
}

int main() {
    string str1 = "A man, a plan, a canal: Panama";
    string str2 = "race a car";
    string str3 = " ";

    MySolution my_sol;
    cout << (my_sol.isPalindrome(str1) ? "True" : "False") << endl;
    cout << (my_sol.isPalindrome(str2) ? "True" : "False") << endl;
    cout << (my_sol.isPalindrome(str3) ? "True" : "False") << endl;

    return EXIT_SUCCESS;
}