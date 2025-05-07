#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
    ifstream file("data.txt");
    if(!file)
    {
        cerr<<"Error:File could not be opened!"<<endl;
    return 1;
    }
    vector<string> lines;
    string line;
    int linecount=0,wordcount=0,charcount=0;

    while(getline(file,line))
    {
        lines.push_back(line);
        linecount++;
        charcount+=line.length();
        istringstream ss(line);
        string word;
        while(ss>>word)
        {
            wordcount++;
        }
        charcount++;
    }
    file.close();
    cout<<"Lines:"<<linecount<<endl;
    cout<<"Words:"<<wordcount<<endl;
    cout<<"Characters:"<<charcount<<endl;
    return 0;

}