#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
bool number(string s)
// возвращает true, если s - число
{
for (int i = 0; i < s.length(); i++)
if (!isdigit(s[i]))
return false;
return true;
}
int main()
{
string slovo;
map<string, int> word;
map<string, int> numb;
string first_word = "";
ifstream in("text.txt");
//будем составлять numb - это структура типа map,
//где каждому числу будет сопоставлено число вхождений в текст
// аналогично word - для слов
//запишем в first_word - первое слово из текста
while (in.peek() != EOF) {
in >> slovo;
if (number(slovo))
numb[slovo] ++;
else {
if (first_word == "") first_word = slovo;
word[slovo]++;
}
}
if (first_word == "")
{
cout << "no words";
system("pause");
return 0;
}
for (map <string, int> ::iterator i = numb.begin(); i != numb.end(); i++)
//перебираем все числа
{
if (i->second == word[first_word])
//если число встречается столько же раз сколько и первое слово
cout << i->first << " ";
}
system("pause");
return 0;
}