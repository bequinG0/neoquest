#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void output(vector <string> a)
{
    for(int i=0; i<a.size(); i++) cout << a[i] << "! !";
    cout << "\n";
}

int main()
{
    vector <string> str;
    ifstream file;
    file.open("task");
    for(int i=0; i<96720; i++)
    {
        string temp;
        file >> temp;
        temp.erase(temp.find("b"), 1);
        str.push_back(temp);
    }file.close();
    output(str);
    for(int i=0; i<str.size(); i++)
    {
        while(str[i].size() < 8)
        {
            string temp = "0" + str[i];
            str[i] = temp;
        }
    }
    output(str); cout << str.size() << endl;
    ofstream fon;
    fon.open("original_task");
    for(int i=0; i<96720; i+=6)
    {
        for(int j=i; j<i+6; j++)
        {
            cout << j << " ";
            if(j < str.size()) fon << str[j] << " ";
            else break;
        }
        fon << "\n";
    }
    fon.close();
}