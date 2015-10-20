#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int priority(char c)
{
    int ans;
    switch(c)
    {
    case '+':ans=1;break;
    case '-':ans=2;break;
    case '*':ans=3;break;
    case '/':ans=4;break;
    case '^':ans=5;break;
    }

    return ans;
}

bool high_priority(char a,char b)
{
    int x=priority(a);
    int y=priority(b);

    if(x>=y)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s,ans;
        cin>>s;

        stack<char> p ;
        p.push('(');

        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                ans=ans+s[i];
            }
            else if(s[i]=='(')
            {
                p.push(s[i]);
            }
            else if(s[i]==')')
            {
                while(p.top()!='(')
                {
                    ans=ans+p.top();
                    p.pop();
                }
                p.pop();   // pop '('
            }
            else
            {
                int l=s.length();
                char c=s[l-1];


                while(high_priority(c,p.top()) && p.top()!='(')
                {
                    ans=ans+p.top();
                    p.pop();
                }

                p.push(s[i]);
            }

        }

        while(p.top()!='(')
        {
            ans=ans+p.top();
            p.pop();
        }

        cout<<ans<<endl;
    }

    return 0;
}
