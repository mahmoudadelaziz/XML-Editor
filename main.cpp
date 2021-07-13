#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>

using namespace std;

vector<string> data;
vector<string> new_data;



int bracket_type(string s){// 0 >> open,  1 >> closed,   2 >> comment,   3 >> text
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        if(s[i] == '<'){
            if((s[i + 1] >= 'A' && s[i + 1] <= 'Z') || (s[i + 1] >= 'a' && s[i + 1] <= 'z')) return 0;
            else if(s[i + 1] == '/') return 1;
            else if(s[i + 1] == '!' || s[i + 1] == '?') return 2;
            else return 3;
        }
    }
}

string bracket_name(string s){
    string name = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        if(s[i] == '<'){
            for(int j = i + 1; j < s.size(); j++){
                if(s[i + 1] == '/') continue;
                if(s[j] == '>' || s[j] == ' ') break;
                else name += s[j];
            }
        }
    }
    return name;
}

void divide_line (string line){
    int start = 0;
    int finish = line.size() - 1;
    string open = "<", close = ">";
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ' ') continue;//ignore early spaces
        else if((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')){//normal line
            size_t found = find(open);
            if (found != string::npos){
                string temp = substr(start, found - 1);
                new_data.push_back(temp);
                i = found;
                start = i;
            }
        }
        else if(line[i] == '<'){// a tag
            size_t found = find(close);
            if (found != string::npos){
                string temp = substr(start, found);
                new_data.push_back(temp);
                i = found + 1;
                start = i;
            }
        }
    }
}

int main()
{
    ifstream file("example.xml");
    if(!file.is_open()){
        cout << "Open failure!";
        return 1;
    }
    string line;

    while(getline(file, line)){
        data.push_back(line);
    }

    for(int i = 1; i < data.size(); i++)
        cout << i << " " << data[i] << endl;

    int num_lines = data.size() - 1;
    ////////////////////////////////////////////////

    string temp;


    ////////////////////////////////////////////////
    stack<string> names_stack;

    for(int i = 0; i < num_lines; i++){
        if(bracket_type(data[i]) == 0)
            names_stack.push(bracket_name(data[i]));
        //closing tag
        if(bracket_type(data[i]) == 3) continue;
    }


    return 0;
}
