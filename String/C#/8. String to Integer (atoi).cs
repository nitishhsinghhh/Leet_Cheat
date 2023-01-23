/*
8. String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

Example 1:
Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.

Example 2:
Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.

Example 3:
Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
 
Constraints:
0 <= s.length <= 200
s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.
*/

using System;

namespace atoiFunc {
    class Program {
        public int MyAtoi(string str) {
            if (str == null || str == string.Empty) return 0;
            int res = 0, sign = 1;
            bool findSign = false, findDigit = false;
            foreach (var c in str)
                if (!findSign && !findDigit && (c == '+' || c == '-')) {
                    findSign = true;
                    sign = c == '+' ? 1 : -1;
                }
                else if (c >= '0' && c <= '9') {
                    findDigit = true;
                    if (res == 0 && c == '0') continue;
                    else if (res > Int32.MaxValue / 10 || (res == Int32.MaxValue / 10 && c - '0' > Int32.MaxValue % 10))
                        return sign == 1 ? Int32.MaxValue : Int32.MinValue;
                    else
                        res = res * 10 + (c - '0');
                }
                else if (c != ' ' || ((findDigit || findSign) && c == ' ') || (findDigit && c == '.')) break;
            return res * sign;
        }
        static void Main(string[] args) {
            string s0 = "42";
            string s1= "   -42";
            string s2 = "4193 with words";
            Program oProgram = new Program();
            int res0 = oProgram.MyAtoi(s0);
            int res1 = oProgram.MyAtoi(s1);
            int res2 = oProgram.MyAtoi(s2);
            Console.WriteLine(res0);
            Console.WriteLine(res1);
            Console.WriteLine(res2);
            Console.ReadLine();
        }
    }
}