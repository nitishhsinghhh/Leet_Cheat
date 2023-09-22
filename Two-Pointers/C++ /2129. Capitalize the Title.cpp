class Solution {
public:
    string capitalizeTitle(string s) {
        for (int i = 0, j = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                if (i - j > 2)
                    s[j] = toupperCase(s[j]);
                j = i + 1;
            }
            else
                s[i] = tolowerCase(s[i]);
        }
        return s;
    }

    char tolowerCase(char c) {
        if (c >= 'A' && c <= 'Z') 
            return c - 'A' + 'a';
        return c;
    }

    char toupperCase(char c) {
        if (c >= 'a' && c <= 'z') 
            return c - 'a' + 'A';
        return c;
    }
};
