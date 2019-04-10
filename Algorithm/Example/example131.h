
/*


给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

class Solution {
public:
int singleNumber(vector<int>& nums) {

}
};

*/

/*
	C++，dfs，回溯剪枝。

	这种从前往后都是同一个规律的题，就要想到递归了。

	对于字符串S的当前子串[left, right]，要找到其中所有的回文串组合，要完成如下工作：

		1 定义变量i从left到right进行分割，得到子串S[left, i]；
		2 如果子串S[left, i]是回文串，则问题发生变化；
		3 新问题：对于字符串S的当前子串[i + 1, right]，找到其中所有的回文串组合
		…
		如果left >= right，则说明当前路径下的回文串组合生成结束

*/

#include <iostream>
using namespace std;

#include <vector>
#include <map>

vector<vector<string>> partition(string s) 
{
        vector<vector<string>> ans;
        if (s.empty()) return ans;
        vector<string> temp;
        dfs(ans, s, temp, 0);
        return ans;
 }
    
 void dfs(vector<vector<string>> &ans, string &s, vector<string> &temp, int left) 
 {
    if (left >= s.length())
        ans.push_back(temp);
    else {
        for (int right = left; right < s.length(); right++) {
            string ts = s.substr(left, right - left + 1);
            if (is_pali(s, left, right)) {
                temp.push_back(ts);
                dfs(ans, s, temp, right + 1);
                temp.pop_back();
            }
        }
    }
 }

//判断是否是回文串
bool is_pali(string &s, int left, int right) {
    if (left == right || left > right) 
        return true;
    if (s[left] == s[right])
        return is_pali(s, left + 1, right - 1);
    else return false;
}
