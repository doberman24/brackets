#include <iostream>
#include <string>
using namespace std;

//Работаем с отфильтрованной строкой, в которой содержаться только скобки
bool test(string str)
{
    int len_str = str.length(); //измеряем длину входной строки
    string last_symb = "";      //создаем строку для хранения открывающихся скобок (т.н. стек)

    for (int i = 0; i < len_str; ++i)
    {
        //Проверяем открывание скобок
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            last_symb += str[i]; //помещаем открытые скобки в т.н. стек
        }

        if (str[i] == ')')                                  //если скобка закрывается,
        {
            if (last_symb.length() <= 0)                    //проверяем не первый ли это символ в строке,
                return false;
            if (last_symb[last_symb.length() - 1] == '(')   //после проверяем предыдущий символ,
            {                                               //если он откывает эту закрывающуюся скобку,
                last_symb.erase(last_symb.length() - 1);    //то удаляем из стека эту скобку (удаляем элемент)
            }                                               //и переходим к следующему символу (скобке)
            else
                return false;
        }

        if (str[i] == ']')                                  //если скобка закрывается,
        {
            if (last_symb.length() <= 0)                    //проверяем не первый ли это символ в строке,
                return false;
            if (last_symb[last_symb.length() - 1] == '[')   //после проверяем предыдущий символ,
            {                                               //если он откывает эту закрывающуюся скобку,
                last_symb.erase(last_symb.length() - 1);    //то удаляем из стека эту скобку (удаляем элемент)
            }                                               //и переходим к следующему символу (скобке)
            else
                return false;
        }

        if (str[i] == '}')                                  //если скобка закрывается,
        {
            if (last_symb.length() <= 0)                    //проверяем не первый ли это символ в строке,
                return false;
            if (last_symb[last_symb.length() - 1] == '{')   //после проверяем предыдущий символ,
            {                                               //если он откывает эту закрывающуюся скобку,
                last_symb.erase(last_symb.length() - 1);    //то удаляем из стека эту скобку (удаляем элемент)
            }                                               //и переходим к следующему символу (скобке)
            else
                return false;
        }
    }
    return true;
}

int main()
{
    cout << "Enter your string: ";
    string str;
    getline(cin, str);                  //вводим строку
    int len_str = str.length();         //измеряем длину входной строки
    string brackets = "";               //создаем строку для хранения отфильтрованных скобок
    for (int i = 0; i < len_str; ++i)
    {
        if (str[i] == '{' || str[i] == '}' || str[i] == '[' || str[i] == ']'
                || str[i] == '(' || str[i] == ')')
        {
            brackets += str[i];         //заносим в строку только скобки из входной строки
        }
    }

    if (test(brackets))
        cout << brackets << " - true";
    else
        cout << brackets << " - false";
    return 0;
}
