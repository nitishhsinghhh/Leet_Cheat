class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {
            { 'I' , 1 }, { 'V' , 5 }, { 'X' , 10 },
            { 'L' , 50 }, { 'C' , 100 }, { 'D' , 500 },
            { 'M' , 1000 }
        };

        int sum = 0;  // Initialize the sum to zero

        // Replace the special Roman numeral substrings with their simplified forms
        s = regex_replace(regex_replace(regex_replace(regex_replace(regex_replace(regex_replace
            (s, regex("CM"), "DCCCC"), regex("CD"), "CCCC"), regex("XC"), "LXXXX"), regex("XL"), "XXXX"),
            regex("IX"), "VIIII"), regex("IV"), "IIII");

        // Iterate through each character in the modified string and add its corresponding value to the sum
        for (auto c : s)
            sum += map[c];

        return sum;  // Return the final sum
    }
};
