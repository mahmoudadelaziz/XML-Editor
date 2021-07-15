//<<<<<<< MahmoudDawood-patch-1
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
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

using namespace std;

vector<string> data;
vector<string> new_data;

template <class T>
class newVector{
private:
    int sz;
    int cap;
    T *p;
    void modify_cap(bool exp){
        // true -> *2
        // else -> /2
        if(exp)
            cap *= 2;
        else{
            if(cap > 1)
                cap /= 2;
        }
 
        T *tp = new T[cap];
        for(int i = 0; i < sz; i++)
            tp[i] = p[i];
        delete []p;
        p = tp;
        tp = NULL;
    }
public:
    newVector(){
        sz = 0;
        cap = 1;
        p = new T[cap];
    }
    newVector(int _sz){
        int nxt = 1;
        while(nxt <= _sz)
            nxt *= 2;
        sz = _sz;
        cap = nxt;
        p = new T[cap];
    }
    newVector(const newVector<T>&v):newVector(v.sz){
        for(int i=0;i<sz;i++)
            p[i]=v[i];
    }
    ~newVector(){
        delete [] p;
    }
    void set_val(int idx, T val){
        if(idx < 0 || idx >= sz){
            cout << "idx outside limits\n";
            int x = 5;
            x /= 0;
        }
        p[idx] = val;
    }
    T get_val(int idx){
        if(idx < 0 || idx >= sz){
            cout << "idx outside limits\n";
            int x = 5;
            x /= 0;
        }
        return p[idx];
    }
    int get_size(){
        return sz;
    }
    void push_back(T val){
        if(sz + 1 == cap){
            modify_cap(1);
        }
        p[sz++] = val;
    }
    void pop_back(){
        if(sz == 0){
            cout << "you can't delete form an empty newVector\n";
            int x = 5;
            x /= 0;
        }
        sz--;
        if(sz * 2 < cap)
            modify_cap(0);
    }
    T& operator[](int idx) {
        return p[idx];
    }
    const T& operator[](int idx)const {
        return p[idx];
    }
    newVector<T>& operator=(const newVector<T>& v){
        if(sz!=v.sz){
            delete [] p;
            int nxt = 1;
            while(nxt <= v.sz)
                nxt *= 2;
            sz = v.sz;
            cap = nxt;
            p = new T[cap];
        }
        for(int i=0;i<sz;i++)
            p[i]=v[i];
        return *this;
    }
   newVector<T> operator+(newVector<T> v){
        if(sz!=v.sz){
            cout << "you can't add two newVectors of different size\n";
            int x = 5;
            x /= 0;
        }
       newVector<T> ret(sz);
        for(int i=0;i<sz;i++)
            ret[i]=p[i]+v[i];
        return ret;
    }
};



template<typename T>
class newLinkedList {
    Node<T> *h, *t;
    int sz;
public:
    newLinkedList() : h(0), t(0), sz(0) {}
 
    newLinkedList(const newLinkedList<T> &l) : newLinkedList() {
        for (auto p = l.first(); p; p = p->nxt)
            insertEnd(p->val);
    }
 
    ~newLinkedList() {
        while (sz)deleteFirst();
    }
 
    newLinkedList<T>  &operator=(const newLinkedList<T>  &l) {
        while (sz)deleteFirst();
        for (auto p = l.first(); p; p = p->nxt)
            insertEnd(p->val);
        return *this;
    }
 
    newLinkedList<T>  &operator+=(const newLinkedList<T>  &l) {
        for (auto p = l.first(); p; p = p->nxt)
            insertEnd(p->val);
        return *this;
    }
 
    newLinkedList<T> operator+(const newLinkedList<T>  &l) const {
        newLinkedList<T> ret(*this);
        for (auto p = l.first(); p; p = p->nxt)
            ret.insertEnd(p->val);
        return ret;
    }
    newLinkedList<T> operator()(int s,int len) const {
        newLinkedList<T> ret;
 
        auto x=h;
        while (s--)x=x->nxt;
        while (len--){
            ret.insertEnd(x->val);
            x=x->nxt;
        }
        return ret;
    }
    void insertBegin(const T &v) {
        sz++;
        auto n = new Node<T>(v, h);
        h = n;
        if (!t)t = n;
    }
 
    void insertEnd(const T &v) {
        sz++;
        auto n = new Node<T>(v, 0);
        if (t)
            t->nxt = n;
        else
            h = n;
        t = n;
    }
 
    void insertAftet(Node<T> *p, const T &v) {
        sz++;
        auto n = new Node<T>(v, p->nxt);
        p->nxt = n;
        if (t == p)t = n;
    }
 
    void deleteFirst() {
        sz--;
        auto temp = h;
        h = h->nxt;
        delete temp;
        if (!h)t = 0;
    }
 
    void deleteAftet(Node<T> *p) {
        sz--;
        auto temp = p->nxt;
        p->nxt = temp->nxt;
        delete temp;
        if (!p->nxt)t = p;
    }
 
    Node<T> *first() const {
        return h;
    }
 
    Node<T> *last() const {
        return t;
    }
    T& operator[](int i){
        auto x=h;
        while (i--)x=x->nxt;
        return x->val;
    }
    const T& operator[](int i)const{
        auto x=h;
        while (i--)x=x->nxt;
        return x->val;
    }
    int size() {
        return sz;
    }
 
    bool empty() {
        return h == 0;
    }
};
 
template<class T>
class newStack{
    newLinkedList<T> l;
public:
    int size() {
        return l.size();
    }
 
    bool empty() {
        return l.empty();
    }
    void push(const T &v){
        l.insertBegin(v);
    }
    T& top()const {
       return l.first()->val;
    }
    void pop() {
        l.deleteFirst();
    }
};



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
/*=======
*/




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
//>>>>>>> main*/
