using namespace std;

#include<iostream>
#include<stdio.h>
#include<string.h>

int main()
{
    char str[101];
    char arr[3][10] = { {'q','w','e','r','t','y','u','i','o','p'} ,  {'a','s','d','f','g','h','j','k','l',';'} , {'z','x','c','v','b','n','m',',','.','/'} };
    char ch;
    int i,j,k;
    cin>>ch;
    cin.ignore();
    cin.getline(str,101,'\n');
    if(ch == 'R' || ch == 'r')
    {
        for(i=0;i<strlen(str);i++)
        {
            for(j = 0; j<3; j++)
            {
                for(k=0; k<10; k++)
                {
                    if(str[i] == arr[j][k])
                    {
                        str[i] = arr[j][k-1];
                        break;
                    }
                }
            }
        }
    }
    else if (ch == 'L' || ch =='l')
    {
        for(i=0;i<strlen(str);i++)
        {
            for(j = 0; j<3; j++)
            {
                for(k=0; k<10; k++)
                {
                    if(str[i] == arr[j][k])
                    {
                        str[i] = arr[j][k+1];
                        break;
                    }
                }
            }
        }
    }
    cout<<str;
}
