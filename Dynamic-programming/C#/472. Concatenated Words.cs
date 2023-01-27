// https://leetcode.com/problems/concatenated-words/

using System;
using System.Collections.Generic;
namespace ConcatenatedWordsApp {
    public class Solution {
        public IList<string> FindAllConcatenatedWordsInADict(string[] words) {
            List<string> res = new List<string>();
            if (words == null || words.Length == 0) return res;
            HashSet<string> wordSet = new HashSet<string>();
            Array.Sort(words, (a, b) => a.Length - b.Length);
            foreach (var word in words) {
                if (IsConcatenated(word, wordSet)) res.Add(word);
                wordSet.Add(word);
            }
            return res;
        }
        public bool IsConcatenated(string word, HashSet<string> wordSet) {
            if (wordSet.Count == 0) return false;
            bool[] dp = new bool[word.Length + 1];
            dp[0] = true;
            for (int i = 1; i <= word.Length; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && wordSet.Contains(word.Substring(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[word.Length];
        }
        static void Main(string[] args) {
            string[] words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat" };
            Solution oSolution = new Solution();
            IList<string> AllWords = oSolution.FindAllConcatenatedWordsInADict(words);
            foreach (var item in AllWords) {
                Console.WriteLine(item);
            }
            Console.ReadKey();
        }
    }
}
/*
    It is obvious that a word can only be formed by words shorter than it. So we can first sort the input by length of each word, 
    and only try to form one word by using words in front of it.


*/
