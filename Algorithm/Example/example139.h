
/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/

#include <iostream>
#include <vector>
using namespace std;

/*
	1 从原str里去除字典里的相同字符串
*/


//找到某个子串在主串中的起始位置
int findSubStr(const char * MainStr, const char *Substr)
{
	const char *p;
	const char *q;
	const char *u = MainStr;
	if (MainStr == NULL || Substr == NULL)
	{
		return -1;
	}
	while (*MainStr)
	{
		p = MainStr;
		q = Substr;

		//找到子串的位置 当*p！=*q时 循环跳出
		while (*q && *p && *p++ == *q++);
		if (!*q) //q->'\0'
		{
			return MainStr - u + 1;
		}

		MainStr++;
	}

	return -1;
}

/*
string mainStr = "applepenapple";
vector<string> wordDict = {"apple", "pen" };
*/
string removeEqualStr(string str, string word)
{
	string result = "";
	int wordLen = word.length();
	int index = findSubStr(str.c_str(), word.c_str());
	if (index != -1)
	{

		result = str.substr(0, index-1);
		result = result + str.substr(index + wordLen - 1, str.length() - wordLen - index+1);
		
		//////递归寻找多个相同的子串
		int index = findSubStr(result.c_str(), word.c_str());
		while (index != -1)
		{
			result = removeEqualStr(result, word);
			index = findSubStr(result.c_str(), word.c_str());
		}
		
	}
	return result;
}


 bool wordBreak(string s, vector<string>& wordDict) 
 {
	 bool result = true;
	 int count = wordDict.size();
	 for (int i = 0; i < count;i++)
	 {
		 string word = wordDict[i];
		 if (word != s)
		 {
			 s = removeEqualStr(s, word);
			 if (s.length() == 0)
			 {
				 //没有找到对应的子串
				 result = false;
				 break;
			 }
		 }
		
	 }
	 return result;
 }