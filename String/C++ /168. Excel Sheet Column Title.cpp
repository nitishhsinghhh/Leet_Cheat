class Solution {
public:
    string convertToTitle(int columnNumber) {
        // base(10) -> base(26)   
        string column = "";
        int rem;

        while(columnNumber) {
            rem = (--columnNumber)%26;  
            columnNumber /= 26;
            column = char('A' + rem) + column;
        }
        return column;
    }
};
