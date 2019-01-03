#include<cstdio>
#include<cstdlib>
#include<set>
#include<stack>
#include<functional>
 
using namespace std;
 
stack<int> s;
multiset<int> upper;//大于中位数的数，从小到大排列
multiset<int,greater<int> > lower;//小于中位数的数，从大到小排列
int mid=0;
 
void Adjust(int* mid)//调整中位数
{
    if(upper.size()>lower.size())
    {
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
    }
    else if(lower.size()>upper.size()+1)
    {
        upper.insert(*lower.begin());
        lower.erase(lower.begin());
    }
    (*mid)=*lower.begin();
}
 
int main(int argc,char *argv[])
{
    int i,n;
    char str[20];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        switch(str[1])
        {
            case 'o':
                if(s.empty())   
                    printf("Invalid\n");
                else
                {
                    int key=s.top();
                    s.pop();
                    printf("%d\n",key);
                    if(key>*lower.begin())
                    {
                        upper.erase(upper.find(key));
                    }
                    else
                    {
                        lower.erase(lower.find(key));
                    }
                    if(s.empty())
                        mid=0;
                    else
                        Adjust(&mid);
                }
                break;
            case 'e':
                if(s.empty())
                    printf("Invalid\n");
                else
                    printf("%d\n",mid);
                break;
            case 'u':
                int key;
                scanf("%d",&key);
                s.push(key);
                if(key>mid)
                    upper.insert(key);
                else
                    lower.insert(key);
                Adjust(&mid);
                break;
        }
    }
 
    return 0;
}