#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<string>
#include<cstdlib>
#include<iostream>
#include<QFileDialog>
#include <iostream>
#include <fstream>
#include"Tree.h"
#include <vector>
#include <cstdlib>
//#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include<stack>

using namespace std;

vector<string> data1;
vector<string> new_data;
stack<string> names_stack;
node* start1;
string *all;
bool j_x;


string removeSpaces(string str)
{
    if (str[str.size() - 1] == ' ') str = str.substr(0, str.size() - 1);
    return str;
}
void read(node *start){
string in;
 stack <string> nodes;
 vector<string> snodes;
 node* current;
ifstream input("text.txt");

if (!input.is_open()) {  cout<< "dile is not open"<<endl;return;//QMessageBox::warning("WARNING","File not open");
}
    string line;
   if(getline(input,line)){
    in=line;
    in = in.substr(1, in.size()-2);
    start = new node(in);
    current=start;
    nodes.push(in);
    snodes.push_back(in);
   // cout<<"in "<<in<<endl;
   }
 string in1;
    while (getline(input, in1)) {
//cout<<start->tname()<<endl;
       // cout << in1.size() << endl;
        in = removeSpaces(in1);
       // cout << "nospaces" << in << 1 << endl;
        //for (int i = 0; i < in.size(); i++)cout << in[i] << endl;
       // if (in == "end"||)break;

       // cout << nodes.top() << endl;
       // cout << current->tname() << endl;
       // if (current->NP() != NULL)
         //   cout << current->NP()->tname() << endl;
        if (in[0] == '<') {
            if (in[in.size() - 1] == '>') {
                in = in.substr(1, in.size() - 2);

            }
            else {
                in = in.substr(1, in.size() - 1);

            }
           // cout << in.substr(1, in.size() - 1).size() << " " << nodes.top().size() << "  open  " << endl;
            if (in[0] == '/' ) {
                if(in.substr(1, in.size() - 1) == nodes.top()){

             //   cout << "end" << endl;
                nodes.pop();
                snodes.pop_back();
                if(current->NP()==NULL)goto ende;
                if (current->NP() != NULL)
                    current = current->NP();
                }
                else{current->set_error(1);
                    int sim=1;
                    for(int i=1;i<snodes.size();i++){
                        if(in.substr(1, in.size() - 1)==snodes[snodes.size()-i]){sim=i; break;}
                    }
                    for(int i=0;i<sim;i++){
                        nodes.pop();
                        snodes.pop_back();
                        if(current->NP()==NULL)goto ende;
                        if (current->NP() != NULL)
                            current = current->NP();
                    }
                }

            }

            else {
                nodes.push(in);
                snodes.push_back(in);
                current = current->addnode(in);
            }

        }
        else if (in[in.size() - 1] == '>') { if (in.size() > 1) { in = in.substr(0, in.size() - 1); /*cout << "parsssss" << endl << endl;*/ current->setpars(in); } }
        else {
            current->addcontent(in);
        }

    }
    ende:
   // cout<<"read finished "<<start->tname()<<endl;
    start1=start;
input.close();
}
void get_element() {
    string original = new_data.back();
    int sz = (new_data.back()).size();
    int flag = 0;
    int tag_finish = 0;
    bool first = true;
    for (int i = 0; i < sz; i++) {
        tag_finish++;
        if (original[i] == ' ') {
            flag++;
            continue;
        }
        if (flag && new_data.back()[i] != '>') {
            int quotes = 0;
            string temp = "";
            while (quotes < 2) {         //new_data.back()[i] != '>' && new_data.back()[i] != ' '
                temp += original[i];
                if (original[i] == '"') quotes++;
                i++;
            }
            if (first) {
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

int bracket_type(string s) {// 0 >> open,  1 >> closed,   2 >> text,   3 >> comment(won't appear)
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] != '<') return 2;
        if (s[i] == '<') {
            //if((s[i + 1] >= 'A' && s[i + 1] <= 'Z') || (s[i + 1] >= 'a' && s[i + 1] <= 'z')) return 0;
            if (s[i + 1] == '/') return 1;
            else return 0;
            //else if(s[i + 1] == '!' || s[i + 1] == '?') return 3;
            //else return 3;
        }
    }
}

string bracket_name(string s) {
    string name = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '<') {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i + 1] == '/') continue;
                if (s[j] == '>' || s[j] == ' ') break;
                else name += s[j];
            }
        }
    }
    return name;
}

void divide_line(string line) {
    //int start = 0;
    int finish = line.size() - 1;
    //int cnt = 0;
    string open = "<", close = ">";
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') continue;                     //ignore early spaces
        else if (line[i] != '<') {                              //pure text
            size_t found = line.find("<", i);
            if (found != string::npos) {
                string temp = line.substr(i, found - i);
                //cout << temp << endl;
                new_data.push_back(temp);
                i = found - 1;
                //start = i;
            }
        }
        else if (line[i] == '<') {// a tag
            if ((line[i + 1] == '?') || (line[i + 1] == '!')) {//ignore comments
                size_t found = line.find(">", i);
                if (found != string::npos) {
                    //cnt++;
                    i = found;
                    //start = i;
                    continue;
                }
            }
            size_t found = line.find(">", i);                  //take open tags
            if (found != string::npos) {
                //cnt++;
                string temp = line.substr(i, found + 1 - i);
                //cout << temp << endl;
                new_data.push_back(temp);
                if (bracket_type(new_data.back()) == 0) get_element();   //extract elements
                i = found;
                //start = i;
            }
        }
        else {
            string temp = line.substr(i, finish);
            cout << temp << endl;
            new_data.push_back(temp);
            return;
        }
    }
}

int read1(QFile file1)
{
    //("elements.xml"); //put file location heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeere <<<<<<<<<<
    if(!file1.open(QFile::ReadWrite | QFile::Text))
    {
         // QMessageBox ::information(ui.MainWindow(),"Error","File couldn't be loaded");
         return 1;
    }
    else
    {
        QTextStream stream(&file1);
        while (!stream.atEnd())
           {
              string line = stream.readLine().toLocal8Bit().constData();
              data1.push_back(line);
           }

    }

    //for (int i = 0; i < data1.size(); i++)
     //   cout << data1[i] << endl;

    /////////////////////////////////////// original file is saved to data vector
   // cout << "/////////////" << endl;

    for (int i = 0; i < data1.size(); i++)
        divide_line(data1[i]);

    ////////////////////////////////////////// every data in one line in new_data vector ya 5aaaaaaaaaaaaaaled <<<<<<<<<<

    for (int i = 0; i < new_data.size(); i++) {
        //cout << new_data[i] << endl;
        if (bracket_type(new_data[i]) == 0) { // open tag names are being pushed to names_stack staaaaaaaack <<<<<<<<<<<<<<
            string temp = bracket_name(new_data[i]);
            names_stack.push(temp);
        }

    }

cout<<"read done"<<endl;
data1.clear();
    return 0;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QDir d;
QString File_name;
void MainWindow::on_Load_B_clicked()
{
    ofstream ofs;
    ofs.open("text.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    QString l = QFileDialog::getOpenFileName(this,"Choose the file");
 QFile file1(l);
 d = QFileInfo(l).absoluteDir();
 File_name=QFileInfo(l).baseName();
 read1(l);
 string stext;
 for(int i=0;i<new_data.size();i++){
     stext.append(new_data[i]);
     stext.append("\n");
 }

 new_data.clear();
// cout<<endl<<endl<<"new"<<endl<<stext<<endl;
  ofstream output("text.txt");
  output<<stext;
  output.close();
 // cout<<endl<<endl<<"new"<<endl<<stext<<endl;
 QString QStext;



if(!file1.open(QFile::ReadWrite | QFile::Text))
{
      QMessageBox ::information(this,"Error","File couldn't be loaded");
     //return 1;
}
else
{
    QTextStream stream(&file1);
    QString text =stream.readAll();
    ui->Original->setText(text);
    file1.close();
}


read(start1);
all= new string;
//start1->print2(0,all,0);
}





void MainWindow::on_Detect_B_clicked()
{
    if(start1!=NULL){
        string* all = new string;
           start1->print_xml(0,all,1);
           QString qtext=QString::fromLocal8Bit(*all);


           ui->Edited->setText(qtext);
        }
        else{QMessageBox::warning(this,"ERROR","Please load a file");}
j_x=0;
}


void MainWindow::on_Convert_B_clicked()
{
    if(start1!=NULL){
        string* all = new string;
           start1->print_json(0,all);
           QString qtext=QString::fromLocal8Bit(*all);
ui->Edited->setText(qtext);
        }
        else{QMessageBox::warning(this,"ERROR","Please load a file");}
    j_x=1;
}


void MainWindow::on_Format_B_clicked()
{if(start1!=NULL){
    string* all = new string;
       start1->print_xml(0,all,0);
       QString qtext=QString::fromLocal8Bit(*all);

       ui->Edited->setText(qtext);
    }
    else{QMessageBox::warning(this,"ERROR","Please load a file");}
j_x=0;
}


void MainWindow::on_Save_B_clicked()
{if(start1==NULL){QMessageBox::warning(this,"ERROR","Please load a file");}
    else{QString absolute=d.absolutePath();
    if(j_x){
    QFile saved(absolute+"/"+File_name+".json");
    if (!saved.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File not open");
    }
    QTextStream out(&saved);
    QString s = ui->Edited->toPlainText();
    out<<s;
    string dir="";
    dir.push_back(absolute.toLocal8Bit().constData()[0]);
    dir.push_back(absolute.toLocal8Bit().constData()[1]);
    vector<string> cmds;
    cmds.push_back(dir);
    string temp="cd ";
    temp .append(absolute.toLocal8Bit().constData());
    cmds.push_back(temp);
    cmds.push_back("start.");
    saved.flush();
    saved.close();
    QMessageBox::warning(this,"File saved","Your saved file is the same directory");
   /* for(int i=0;i<cmds.size();i++){
    const char *locout=cmds[i].c_str();
  //  dir+=locout;
    system(locout);}*/
    }
    if(!j_x){
    QFile saved(absolute+"/"+File_name+".xml");
    if (!saved.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File not open");
    }
    QTextStream out(&saved);
    QString s = ui->Edited->toPlainText();
    out<<s;
    string dir="";
    dir.push_back(absolute.toLocal8Bit().constData()[0]);
    dir.push_back(absolute.toLocal8Bit().constData()[1]);
    vector<string> cmds;
    cmds.push_back(dir);
    string temp="cd ";
    temp .append(absolute.toLocal8Bit().constData());
    cmds.push_back(temp);
    cmds.push_back("start.");
    saved.flush();
    saved.close();
    QMessageBox::warning(this,"File saved","Your saved file is the same directory");}

}
}

