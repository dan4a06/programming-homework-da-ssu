#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

string str_tolower(string s)
    //функция преобразует строку s в нижний регистр
    {
    for (int i = 0; i < s.length(); i++)
    s[i] = tolower(s[i]);
    return s;
}

set <string> set_word(string s)
    //функция возвращает множество из слов нижнего регистра предложения s
    //Если s="Max and Alex went to play football", то
    //множество слов set_s = { alex, and, football, max, play, to, went}
    {
    set <string> set_s;
    if (s[s.length() - 1] != ' ')
    s += " ";
    while (s != "") {
    set_s.insert(str_tolower(s.substr(0, s.find(' '))));
    s.erase(0, s.find(' ') + 1);
    }
    return set_s;
}

int main(){
    string s, pr;
    cout << "Input text\n";
    getline(cin, s);
    set <string> prres, res, pov, voskl, vopr, s0;
    //будем составлять множества pov, voskl, vopr из слов
    //повествовательного, восклицательного
    //и вопросительного предложений соответственно
    while (s != "") {
    int pos = s.find_first_of(".!?");
    pr = s.substr(0, pos);
    s0 = set_word(pr);
    if (s[pos] == '.') pov.insert(s0.begin(), s0.end());
    if (s[pos] == '!') voskl.insert(s0.begin(), s0.end());
    if (s[pos] == '?') vopr.insert(s0.begin(), s0.end());
    s.erase(0, pos + 1);
    }
    //находим пересечение множеств pov и vopr
    set_difference(pov.begin(), pov.end(), vopr.begin(), vopr.end(), inserter(prres, prres.begin()));
    set_difference(prres.begin(), prres.end(), voskl.begin(), voskl.end(), inserter(res, res.begin()));
    for (set <string> ::iterator i = res.begin(); i != res.end(); i++)
    cout << *i << " ";

    return 0;
}