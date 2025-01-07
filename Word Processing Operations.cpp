#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout << "~~~~~ Word Processing ~~~~~\n";
    int choice;
flag:
    cout << "Enter your choice for word processing." << endl;
    cout << "Press 1 for insertion." << endl;
    cout << "Press 2 for deletion." << endl;
    cout << "Press 3 for replacement." << endl;
    cout << "Press any key for exit" << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        string str1;
        cout << "Enter your first string: \n";
        getline(cin,str1);
        string str2;
        cout << "Enter your second string: \n";
        getline(cin,str2);
        int pos;
        cout << "Enter the position for insertion: ";
        cin >> pos;
        str1.insert(pos, str2);
        cout << "The new string is: "<< str1 << endl;
        goto flag;
    }
    case 2:
    {
        string str1;
        cout << "Enter your first string: "<< endl;
        getline(cin,str1);
        int n,m;
        cout <<"Enter the position of deletion: "<< endl;
        cin >> n;
        cout << "Enter the number of character you want to delete: "<< endl;
        cin >> m;
        str1.erase(n,m);
        cout << "The new string is: "<< str1 << endl;
        goto flag;
    }
    case 3:
    {
        string str1;
        cout << "Enter your first string: "<< endl;
        getline(cin,str1);
        string str2;
        cout << "Enter your second string: "<< endl;
        getline(cin,str2);
        int x,y;
        cout << "Enter the position for replacement: " << endl;
        cin >> x;
        cout << "Enter number of character you want to replace: "<< endl;
        cin >> y;
        str1.replace(x,y,str2);
        goto flag;
    }
    default:
    {
        cout << "Exiting program."<< endl;
    }
    }
    return 0;
}
