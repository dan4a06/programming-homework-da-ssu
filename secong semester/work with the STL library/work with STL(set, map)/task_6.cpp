#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

/*
 Дан текст, состоящий из предложений, разделҷнных знаками препинания из
набора «.?!». Предложения в свою очередь состоят из слов, отделенных друг от
друга пробелами. Найти слова (без учҷта регистра) и их количество, которые
встречаются только в повествовательных предложениях.
*/

string str_lower(string s){
    for(int i = 0; i < s.length() ; ++i)
        s[i] = tolower(s[i]);
    return 0;
}

set <string> set_word(string s) {
    set <string> set_s;
    if (s[s.length() - 1] != ' ')
        s += " ";
    while (s != " "){
        set_s.insert(str_lower(s.substr(0, s.find(' '))));
    }
    return set_s;
}

int main() {
    //setlocale(LC_ALL, "RU");
    


    return 0;
}