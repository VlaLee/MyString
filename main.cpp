  // Copyright 2024 Lee V.

#include <iostream>
#include <string>

#include "MyString.h"

const MyString single_separator("=====");
const MyString separator = 10 * single_separator;

void print_separator() {
    std::cout << '\n' << separator << "\n\n";
}

int main() {
    // инициализируем строку по умолчанию - она указывает на nullptr
    MyString s0;
    std::cout << "[default constructor], string s0: " << s0 << '\n';
    print_separator();

    // инициализируем строку типом char*
    MyString s1("Cat");
    std::cout << "[char* data type constructor], string s1: " << s1 << '\n';
    print_separator();

    // инициализируем строку типом std::string
    std::string temp_str = "Dog";
    MyString s2(temp_str);
    std::cout << "[std::string data type constructor], string s2: "
        << s2 << '\n';
    print_separator();

    // инициализируем строку путем копирования
    MyString s1_copy(s1);
    std::cout << "[copy initialization], string s1_copy: " << s1_copy << '\n';
    print_separator();

    // инициализируем строку путем перемещения
    MyString s1_move(std::move(s1));
    std::cout << "[moving initialization], string s1_move: " << s1_move << '\n';

    // теперь s1 указывает на nullptr
    std::cout << "string s1 after moving initialization: " << s1 << '\n';
    print_separator();

    s1 = s2;  // копирующее присваивание
    std::cout << "[copying assignment], string s1: " << s1 << '\n';
    print_separator();

    MyString s3("Monkey");
    s1 = std::move(s3);

    std::cout << "[moving assignment], string s1: " << s1 << '\n';

    // теперь s3 указывает на nullptr
    std::cout << "string s3 after moving assignment: " << s3 << '\n';
    print_separator();

    MyString s4("Hello,");
    MyString s5(" world!");

    // выводим длину строки (в длину не входит символ "нуль-терминатор")
    std::cout << "s4 string length: " << s4.length() << '\n';

    // длина "пустой" строки
    std::cout << "s0 string length: " << s0.length() << '\n';
    print_separator();

    // указатель на данные строки
    std::cout << "pointer to the data of string s5: " << s5.get() << '\n';
    print_separator();

    // конкатенация строк
    std::cout << "s4 + s5 result: " << s4 + s5 << '\n';
    print_separator();

    MyString s6("ACCEPTEDCCDD");
    MyString s7("DC");
    std::cout << "s6 - s7 result: " << s6 - s7 << '\n';  // вычитание строк
    std::cout << "s7 - s6 result: " << s7 - s6 << '\n';  // из меньшей - большую
    std::cout << "s6 - s0 result: " << s6 - s0 << '\n';  // из строки - "пустую"
    std::cout << "s0 - s6 result: " << s0 - s6 << '\n';  // из "пустой" - строку
    print_separator();

    // умножение строки на число
    std::cout << "s7 * 4 result: " << s7 * 4 << '\n';

    // в другом порядке
    std::cout << "4 * s7 result: " << 4 * s7 << '\n';

    // умножение на "пустую" строку
    std::cout << "4 * s0 result: " << 4 * s0 << '\n';

    // умножение на 0
    std::cout << "0 * s7 result: " << 0 * s7 << '\n';
    print_separator();

    MyString s8("aaa");
    MyString s9("aaA");
    MyString s10("aaa");

    if (s8 == s9)  // сравнение одинаковых по длине
        std::cout << "strings s8 and s9 are equal\n";
    else
        std::cout << "strings s8 and s9 are not equal\n";

    if (s8 == s10)  // сравнение одинаковых по длине
        std::cout << "strings s8 and s10 are equal\n";
    else
        std::cout << "strings s8 and s10 are not equal\n";

    print_separator();

    if (s8 != s9)  // сравнение одинаковых по длине строк
        std::cout << "strings s8 and s9 are not equal\n";
    else
        std::cout << "strings s8 and s9 are equal\n";

    if (s8 != s10)  // сравнение одинаковых по длине строк
        std::cout << "strings s8 and s10 are not equal\n";
    else
        std::cout << "strings s8 and s10 are equal\n";

    if (s8 != s0)  // сравнение с "пустой" строкой
        std::cout << "strings s8 and s0 are not equal\n";
    else
        std::cout << "strings s8 and s0 are equal\n";

    print_separator();

    if (s8 > s9)  // сравнение одинаковых по длине строк
        std::cout << "string s8 is more than s9\n";
    else
        std::cout << "string s8 is not more than s9\n";

    if (s8 > s0)  // сравнение с "пустой" строкой
        std::cout << "string s8 is more than s0\n";
    else
        std::cout << "string s8 is not more than s0\n";

    MyString s11("aghaghagh");
    if (s11 > s8)  // сравнение разных по длине строк
        std::cout << "string s11 is more than s8\n";
    else
        std::cout << "string s11 is not more than s8\n";

    print_separator();

    if (s8 < s9)  // сравнение одинаковых по длине строк
        std::cout << "string s8 is less than s9\n";
    else
        std::cout << "string s8 is not less than s9\n";

    if (s0 < s8)  // сравнение с "пустой" строкой
        std::cout << "string s0 is less than s8\n";
    else
        std::cout << "string s0 is not less than s8\n";

    if (s8 < s11)  // сравнение разных по длине строк
        std::cout << "string s8 is less than s11\n";
    else
        std::cout << "string s8 is not less than s11\n";

    print_separator();

    if (s8 >= s9)  // сравнение одинаковых по длине строк
        std::cout << "string s8 is not less than s9\n";
    else
        std::cout << "string s8 is less than s9\n";

    MyString s12;
    if (s0 >= s12)  // сравнение двух "пустых" строк
        std::cout << "string s0 is not less than s12\n";
    else
        std::cout << "string s0 is not less than s12\n";

    if (s8 >= s11)  // сравнение разных по длине строк
        std::cout << "string s8 is not less than s11\n";
    else
        std::cout << "string s8 is less than s11\n";

    print_separator();

    if (s8 <= s9)  // сравнение одинаковых по длине строк
        std::cout << "string s8 is not more than s9\n";
    else
        std::cout << "string s8 is more than s9\n";

    if (s12 <= s0)  // сравнение двух "пустых" строк
        std::cout << "string s12 is not more than s0\n";
    else
        std::cout << "string s12 is more than s0\n";

    if (s8 <= s11)  // сравнение разных по длине строк
        std::cout << "string s8 is not more than s11\n";
    else
        std::cout << "string s8 is more than s11\n";

    print_separator();

    MyString s13("75*^@:AAbbCDCdcdjGk0002@@");

    // конвертация строки по регистру
    std::cout << "Converted by register s13: " << !s13 << '\n';
    print_separator();

    // обращение к корректным и некорректным индексам
    std::cout << "Symbol at index 6: " << s13[6] << '\n';
    std::cout << "Symbol at index -100: " << s13[-100] << '\n';
    std::cout << "Symbol at index 100: " << s13[100] << '\n';
    print_separator();

    MyString s14("I want to break free");
    MyString s15("want");
    MyString s16("want ");
    MyString s17("want  ");
    if (s14(s15))  // поиск строки "want" в строке s14
        std::cout << "String s15 - " << s15 << " - includes in string s14\n";
    else
        std::cout << "String s15 - " << s15 <<
            " - does not include in string s14\n";

    if (s14(s16))  // поиск строки "want " в строке s14
        std::cout << "String s16 - " << s16 << " - includes in string s14\n";
    else
        std::cout << "String s16 - " << s16 <<
            " - does not include in string s14\n";

    if (s14(s17))  // поиск строки "want  " в строке s14
        std::cout << "String s17 - " << s17 << " - includes in string s14\n";
    else
        std::cout << "String s17 - " << s17 <<
            " - does not include in string s14\n";

    print_separator();

    MyString s18;
    std::cout << "Enter your string:\n";
    std::cin >> s18;  // пользовательский ввод
    std::cout << "Your entered string: " << s18 << '\n';

    return 0;
}
