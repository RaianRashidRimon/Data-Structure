#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
int main()
{
    cout << "~~~~~ String Operations ~~~~~"<< endl;
    int choice;
flag:
    cout << "Enter your choice of operation:" << endl;
    cout << "Press 1 for printing substring:" << endl;
    cout << "Press 2 patter matching:" << endl;
    cout << "Press 3 length of a string:" << endl;
    cout << "Press 4 concatenation:" << endl;
    cout << "Press any key for exit" << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        string str;
        cout << "Enter your string: "<< endl;
        getline(cin, str);
        int n,m;
        cout << "Enter the first index of the substring: ";
        cin >> n;
        cout << "Enter the length of the substring: ";
        cin >> m;
        string sub = str.substr(n,m);
        cout << "Substring is: " << sub;
        goto flag;
    }
    case 2:
    {
        string str;
        cout << "Enter your string: "<< endl;
        getline(cin, str);
        cout << "Enter your substring: "<< endl;
        string substrr;
        getline(cin, substrr);
        int index, pos=0;
        while((index = str.find(substrr,pos))!= string::npos)
        {
            cout << "Match found at: " << index << endl;
            pos = index+1;
        }
        goto flag;
    }
    case 3:
    {
        string str;
        cout << "Enter your string: "<< endl;
        getline(cin,str);
        int n;
        n = str.length();
        cout << "The length of the string is: "<< n;
        goto flag;
    }
    case 4:
    {
        string str1;
        cout << "Enter your string: "<< endl;
        getline(cin,str1);
        string str2;
        cout << "Enter another string: "<< endl;
        getline(cin,str2);
        str1.append(str2);
        cout << "The concatenated string is: " << str1 << endl;
        goto flag;
    }
    default:
    {
        cout << "Exiting program."<< endl;
        break;
    }
    }
    return 0;
}
