#include "Student.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "КЛАСС Man\n";
    cout << "Работа конструктора с параметрами\n";
    Man ma("Иванов", "17.07.1999");
    cout << ma << '\n';//Перегрузка потокового вывода
    cout << "Работа конструктора копирования\n";
    Man mb(ma);
    cout << mb << '\n';
    Man mc;
    cout << "Работа перегруженного оператора присваивания\n";
    mc = ma;
    cout << mc << '\n';
    cout << "Результат изменения значения полей по отдельности\n";
    mc.SetFullName("Петров");
    mc.SetBirthDate("12.07.2000");
    cout << "Чтение значения полей по отдельности\n";
    cout << "ФИО: " << mc.GetFullName() << "\nГод рождения: " << mc.GetBirthDate() << '\n';
    cout << mc << '\n';
    cout << "КЛАСС Student\n";
    cout << "Работа конструктора с параметрами\n";
    Student sa("Иванов", "17.07.1999", "ПИм-211", "КузГТУ");
    cout << sa << '\n';//Перегрузка потокового вывода
    cout << "Работа конструктора копирования\n";
    Student sb(sa);
    cout << sb << '\n';
    Student sc;
    cout << "Работа перегруженного оператора присваивания\n";
    sc = sa;
    cout << sc << '\n';
    cout << "Результат изменения значения полей по отдельности\n";
    sc.SetFullName("Петров");
    sc.SetBirthDate("12.07.2000");
    sc.SetGroup("МГ-211");
    sc.SetUniversity("КемГУ");
    cout << "Чтение значения полей по отдельности\n";
    cout << "ФИО: " << sc.GetFullName() << "\nГод рождения: " << sc.GetBirthDate()
        << "\nГруппа: " << sc.GetGroup() << "\nВУЗ: " << sc.GetUniversity() << '\n';

    cout << sc << '\n';
    cout << "КЛАСС LinkedList\n";
    LinkedList<Man> t;
    //Добавление записей
    t.Add(new Man("Иванов", "01.01.1996"));
    t.Add(new Student("Сидоров", "02.02.1997", "ПИб-197", "КузГТУ"));
    t.Add(new Man("Петров", "03.03.1998"));
    cout << "Содержимое таблицы:\n";
    cout << "Количество записей: " << t.GetSize() << '\n';
    cout << t;//Перегрузка потокового вывода
    cout << "Удаление записи таблицы:\n";
    cout << t.Remove(2) << "\n";
	cout << "Новая таблица:\n";
    cout << t;
    cout << *t[1];//Перегрузка операции индексирования
}


