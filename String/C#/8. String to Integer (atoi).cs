/*
 https://leetcode.com/problems/string-to-integer-atoi/
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
