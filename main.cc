#include <iostream>
#include <fstream>
#include "numlist.h"

using namespace std;

int main(){
    ifstream ifs;
    ofstream ofs;
    int num1, num2, num3, position;
    NumList n;
    string file_name;

    cout << "Enter name of file" << endl;
    cin >> file_name;
    ifs.open(file_name.c_str());
    n.load_from_file(ifs);
    ifs.close();

    n.see_all();
    cout << endl;
    n.b_sort();
    n.see_all();
    cout << endl;
     
    cout << "Enter three numbers to add to the array" << endl;
    cin >> num1 >> num2 >> num3;

    n.insert(num1);
    n.insert(num2);
    n.insert(num3);

    string sorted = "sorted";
    position = file_name.find(".");
    file_name.insert(position, sorted);

    ofstream file (file_name);
    n.save_to_file(file);
    
   
    cout << "Array saved in: " << file_name << endl;

    return 0;
}