#include<iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
vector<string> split(const string &text, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(text);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
 void fanzhuan(){
    int a,b=0;
    cin >> a;
    while(a != 0){
        b = b*10 + a%10;
        a = a/10;
    }
    cout << b << endl;
}
int main() {
    string str;
    string fenge;
    cin>>str;
    for (int i = 0; i < str.length(); i++) {
        string ch;
        ch = str[i];
        if (ch == "."||"/"||"%"){
            fenge=ch;
        }
    }
    vector<string> tokens = split(str, fenge);
    for (const string &token : tokens) {
        cout << token << endl;
    }
    system("pause");
    return 0;
}
