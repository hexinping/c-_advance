//
//  example125.hpp
//  Algorithm
//
//  Created by hexinping on 2019/4/6.
//  Copyright © 2019年 hexinping. All rights reserved.
//

#ifndef example125_h
#define example125_h

#include <stdio.h>
#include <iostream>
using namespace std;

/*
 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 
 说明：本题中，我们将空字符串定义为有效的回文串。
 
 示例 1:
 
 输入: "A man, a plan, a canal: Panama"
 输出: true
 示例 2:
 
 输入: "race a car"
 输出: false

*/

/*
 C++，双指针分别指向头和尾，如果是非法字符移动指针，然后判断字符是否相等（大小写需要特殊处理）。
 
 isdigit(c);来判断是否为数字，如果是数字那么会返回非0
 isalpha(c);来判断是否为字母，如果是字母那么返回非0
 */
bool isPalindrome(string s)
{
    if(s == "") return true;
    const char * p1 = s.c_str();
    const char * p2 = nullptr;
    bool result = true;
    
    //先把数字字符和字母字符挑选出来
    char *res = new char[1024];
    int count = 0;
    while (*p1!='\0')
    {
        if(isdigit(*p1) || isalpha(*p1))
        {
            res[count] = *p1;
            count++;
        }
        p1++;
    }
    
    cout<<"str====="<<res<<endl;
    p1 = res;
    p2 = p1+count-1;
    
    while(p1<p2)
    {
        if(*p1==*p2 || (*p1<*p2 && *p1==(*p2-32)) ||(*p1>*p2 && *p1==(*p2+32)))
        {
            p1++;
            p2--;
        }
        else
        {
            result = false;
            break;
        }
        
    }
    return result;
}

#endif /* example125_hpp */
