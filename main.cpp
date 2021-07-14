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
stack<string> names_stack;




void get_element(){
    string original = new_data.back();
    int sz = (new_data.back()).size();
    int flag = 0;
    int tag_finish = 0;
    bool first = true;
    for(int i = 0; i < sz; i++){
        tag_finish++;
        if(original[i] == ' '){
            flag++;
            continue;
        }
        if(flag && new_data.back()[i] != '>'){
            int quotes = 0;
            string temp = "";
            while(quotes < 2){         //new_data.back()[i] != '>' && new_data.back()[i] != ' '
                temp += original[i];
                if(original[i] == '"') quotes++;
                i++;
            }
            if(first){
                new_data.back() = original.substr(0, tag_finish - 1 - flag) + ">";
                first = false;
            }
            temp += '>';
            new_data.push_back(temp);
            flag = 0;
            i--;
        }
    }
}

int bracket_type(string s){// 0 >> open,  1 >> closed,   2 >> text,   3 >> comment(won't appear)
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') continue;
        if(s[i] != '<') return 2;
        if(s[i] == '<'){
            //if((s[i + 1] >= 'A' && s[i + 1] <= 'Z') || (s[i + 1] >= 'a' && s[i + 1] <= 'z')) return 0;
            if(s[i + 1] == '/') return 1;
            else return 0;
            //else if(s[i + 1] == '!' || s[i + 1] == '?') return 3;
            //else return 3;
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
    //int start = 0;
    int finish = line.size() - 1;
    //int cnt = 0;
    string open = "<", close = ">";
    for(int i = 0; i < line.size(); i++){
        if(line[i] == ' ') continue;                     //ignore early spaces
        else if(line[i] != '<'){                              //pure text
            size_t found = line.find("<", i);
            if (found != string::npos){
                string temp = line.substr(i, found - i);
                //cout << temp << endl;
                new_data.push_back(temp);
                i = found - 1;
                //start = i;
            }
        }
        else if(line[i] == '<'){// a tag
            if((line[i + 1] == '?') || (line[i + 1] == '!')){//ignore comments
                size_t found = line.find(">", i);
                if (found != string::npos){
                    //cnt++;
                    i = found;
                    //start = i;
                    continue;
                }
            }
            size_t found = line.find(">", i);                  //take open tags
            if (found != string::npos){
                //cnt++;
                string temp = line.substr(i, found + 1 - i);
                //cout << temp << endl;
                new_data.push_back(temp);
                if(bracket_type(new_data.back()) == 0) get_element();   //extract elements
                i = found;
                //start = i;
            }
        }
        else{
            string temp = line.substr(i, finish);
            cout << temp << endl;
            new_data.push_back(temp);
            return;
        }
    }
}

int main()
{
    ifstream file("elements.xml"); //put file location heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeere <<<<<<<<<<
    if(!file.is_open()){
        cout << "Open failure!";
        return 1;
    }
    string line;
    while(getline(file, line)){
        data.push_back(line);
    }
    for(int i = 0; i < data.size(); i++)
        cout << data[i] << endl;

    /////////////////////////////////////// original file is saved to data vector
    cout << "/////////////" << endl;

    for(int i = 0; i < data.size(); i++)
        divide_line(data[i]);

    ////////////////////////////////////////// every data in one line in new_data vector ya 5aaaaaaaaaaaaaaled <<<<<<<<<<

    for(int i = 0; i < new_data.size(); i++){
        cout << new_data[i] << endl;
        if(bracket_type(new_data[i]) == 0){ // open tag names are being pushed to names_stack staaaaaaaack <<<<<<<<<<<<<<
            string temp = bracket_name(new_data[i]);
            names_stack.push(temp);
        }
    }



    return 0;
}
