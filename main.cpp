#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

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

    cout << data.size() - 1;

    ////////////////////////////////////////////////


    return 0;
}
