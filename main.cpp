#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>

using namespace std;

int bracket_type(string s){// 0 >> open,  1 >> closed,   2 >> comment
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        if(s[i] == '<'){
            if((s[i + 1] >= 'A' && s[i + 1] <= 'Z') || (s[i + 1] >= 'a' && s[i + 1] <= 'z')) return 0;
            else if(s[i + 1] == '/') return 1;
            else if(s[i + 1] == '!' || s[i + 1] == '?') return 3;
        }
    }
}

string bracket_name(string s){
    string name = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        if(s[i] == '<'){
            for(int j = i + 1; j < s.size(); j++){
                if(s[I + 1] == '/') continue;
                if(s[j] == '>') break;
                else name += s[j];
            }
        }
    }
    return name;
}

int main()
{
    ifstream file("example.xml");
    if(!file.is_open()){
        cout << "Open failure!";
        return 1;
    }
    string line;
    vector<string> data;
    while(getline(file, line)){
        data.push_back(line);
    }

    for(int i = 1; i < data.size(); i++)
        cout << i << " " << data[i] << endl;

    int num_lines = data.size() - 1;

    ////////////////////////////////////////////////
    stack<string> names_stack;

    for(int i = 0; i < num_lines; i++){
        if(bracket_type(data[i]) == 0)
            names_stack.push(bracket_name(data[i]));
    }


    return 0;
}
