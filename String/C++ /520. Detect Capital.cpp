class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.empty()) 
            return false;
        if(word.size() == 1) 
            return true;
        
        int i = 1;
        if(word[0] >= 'A' && word[0] <= 'Z') {
            i = 2;
            if(word[1] >= 'A' && word[1] <= 'Z')
                while(i < word.size() && word[i]>='A' && word[i] <= 'Z')
                    i++;
            else if(word[1] >= 'a' && word[1] <= 'z')
                while(i < word.size() && word[i]>='a' && word[i] <= 'z')
                    i++;
        }
        
        if(word[0]>='a' && word[0] <= 'z')
            while(i < word.size() && word[i]>='a' && word[i] <= 'z')
                i++;

        return i == word.size();
    }
};
