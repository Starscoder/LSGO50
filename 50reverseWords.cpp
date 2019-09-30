/**
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
**/

class Solution {
public:
    void reverseS(int front,int tail,string& s){
            while(front < tail){
                s[front] ^= s[tail];
                s[tail] ^= s[front];
                s[front++] ^= s[tail--];
            }
        }
    string reverseWords(string s) {
        int front = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                reverseS(front,i-1,s);
                front = i+1;
            }
        }
        reverseS(front,s.length()-1,s);
        return s;
    }
};
