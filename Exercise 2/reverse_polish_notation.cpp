#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;

bool number(char c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool operand(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    return false;
}

unsigned weight(char c)
{
    if (!operand(c))
    {
        return -1;
    }
    switch(c)
    {
    case '+':
    case '-':
        return 3;
    case '*':
    case '/':
        return 2;
    case '^':
        return 1;
    }
}

//bool bracket(char c)
//{
//    if(c == '(' || c == ')')
//    {
//        return true;
//    }
//    return false;
//}

void translate (const char* s, char* res)
{
    string result = "";
    stack<char> st;
    for(int i = 0; s[i]; i++)
    {
        if(number(s[i]))
        {
            cout<<s[i];
            result += s[i];
        }
        else if(operand(s[i]))
        {
            unsigned w = weight(s[i]);
            while(!st.empty() && weight(st.top()) <= w)
            {
                cout<<st.top();
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(st.top() != '(')
            {
                cout<<st.top();
                result += st.top();
                st.pop();
            }
            st.pop();
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        result += st.top();
        st.pop();
    }
//    strcpy(res, result);
}

int compute(const char* s)
{
    stack<int> st;
    for(int i = 0; s[i]; i++){
        if(number(s[i])){
            st.push((int)s[i] - (int)'0');
        } else if(operand(s[i])){
            int value;
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            switch(s[i]){
                case '+': value = first + second;
                    break;
                case '-': value = first - second;
                    break;
                case '*': value = first * second;
                    break;
                case '/': value = first / second;
                    break;
                case '^': value = pow(first, second);
            }
            st.push(value);
        }
    }
    cout<<st.size()<<endl;
    return st.top();
}




int main()
{
    char* str;
//    translate("(1+2)*3-4", str);
    cout<<compute("12+3*4-");
}
