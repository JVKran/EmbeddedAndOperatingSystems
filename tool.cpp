#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stoi;


int main(int argc, char*argv[0]){
    string s = "start";
    int rotation = 0;
    if(argc != 2){
        std::cerr << "Geef paramters mee" << endl;
        return -1;
    }
    for(;;){
        cin >> s;
        rotation = stoi(string(argv[2]));
        cout << rotation;
        if(cin.eof()) {return 0;}
        for(unsigned int i = 0; i < s.length(); i++){
            cout << char(int(s[i]));
        }
    }
}