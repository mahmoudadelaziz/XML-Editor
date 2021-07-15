#ifndef TREE_H
#define TREE_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;
#define TREE_H
#include <string>
#include <vector>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

#endif // TREE_H
class node {
    string name;
   string content;
    vector <node*> nodes;
    node* parent;
    vector<vector<string>> paramiters;
    string par;
    bool error;



public:
    void setpars(string s) {
        par .append(' '+s);
        vector<string> temp; int j = 0, c = 0, c1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '=') {
                temp.push_back(s.substr(j, i - j));

                for (int i1 = i + 1; i1 < s.size(); i1++) {
                    if (s[i1] == '\"')c++;
                    if (c == 2) { temp.push_back( s.substr(i + 1, i1 - i)); i = i1 + 1; j = i;  c = 0; paramiters.push_back(temp);  break; }
                }
            }
        }
    }
    node(string s, node* p = NULL) {
        name = s;  parent = p; error=0;
    }
    string tname(){
        return name; }
void set_error(bool b){error =b;}
bool get_error(){return error;}
    vector <node*> tnodes() { return nodes; }
    void addcontent(string s) {
        content.append(' '+s);
    }
    node* addnode(string s) { node* temp = new node(s, this); nodes.push_back(temp); return temp; }
    node* NP() { return parent; }


    void print_xml(int n, string *all,bool errbool) {

         node* current = this;
         if(n!=0)
         all->append("\n");
        for (int i = 0; i < n; i++) {
           all->append ("    ");all->append ("  ");
        }

        all->append( '<' + name +' ');
        if(par!=""){
            if(par.size()>50){
             int it=0,it2=50;
                again:
                if(it<par.size()){
                for (int i = 0; i < n-1; i++) {all->append ("    ");all->append ("  ");}
                for(int i=it2;i<it2+10;i++){if(par[i]==' '||i==par.size()-1) {it2=i;  break;}}

                all->append(par.substr(it,it2-it));
                it=it2+1;
                if(it2+50<par.size()-1){it2+=50;}
                else{it2=par.size()-1;}
                goto again;}
            }
            else{all->append(par);}
        }
        all->append(">");


        n++;
        if (content!="") {
            if (content.size() > 50 || nodes.size() != 0) {
               // cout<<endl<<"size if large"<<endl;
                int it=0,it2=50;
                again1:
                if(it<content.size()){
                all->append( "\n");
                for (int i = 0; i < n; i++) {all->append ("    ");all->append ("  ");}
                for(int i=it2;i<it2+10;i++){if(content[i]==' '||i==content.size()-1) {it2=i; /*cout<<endl<<"it2 "<<it2<<endl;*/ break;}}
                all->append(content.substr(it,it2-it));
                it=it2+1;
                if(it2+50<content.size()-1){it2+=50;}
                else{it2=content.size();}
                goto again1;}

            }
            else{
            all->append( content);}

        }


        for (int i = 0; i < nodes.size(); i++) {
            node* temp = nodes[i];
            temp->print_xml(n,all,errbool);
        }

        n--;

            if (content.size() > 50 || nodes.size() != 0) {
                all->append( "\n");

                for (int i = 0; i < n; i++) {all->append ("    ");all->append ("  ");}
            }

        all->append( "</" + name + '>');
        if(current->get_error()&&errbool)all->append("   <<---ERROR");
        ofstream output("XML.xml");
        output<<*all;
        output.close();
    }
   // ofstream output("text.txt");

};


