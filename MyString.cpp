  // Copyright 2024 Lee V.

#include <iostream>
#include <algorithm>
#include <set>

#include "MyString.h"

MyString::MyString(const char* str) {
    if (str == nullptr) {
        m_string = nullptr;
        m_size = 0;
        return;
    }

    m_size = strlen(str) + 1;
    m_string = new char[m_size];

    for (int i = 0; i < m_size; ++i) {
        m_string[i] = str[i];
    }
}

MyString::MyString(const std::string& str) : m_size(str.length() + 1) {
    m_string = new char[m_size];

    for (int i = 0; i < m_size; ++i) {
        m_string[i] = str[i];
    }
}

MyString::MyString(const MyString& copy) : m_size(copy.m_size) {
    delete[] m_string;

    m_string = new char[m_size];

    for (int i = 0; i < m_size; ++i) {
        m_string[i] = copy[i];
    }
}

MyString::MyString(MyString&& moved) :
    m_size(moved.m_size), m_string(moved.m_string) {
    moved.m_string = nullptr;
}

MyString::~MyString() {
    delete[] m_string;
}

MyString& MyString::operator=(const MyString& source) {
    if (this == &source)  // checking for self-assimilation
        return *this;

    delete[] m_string;

    m_size = source.m_size;

    if (source.m_string == nullptr) {
        m_string = nullptr;
        return *this;
    }

    m_string = new char[m_size];
    for (int i = 0; i < m_size; ++i)
        m_string[i] = source[i];

    return *this;
}

MyString& MyString::operator=(MyString&& source) {
    if (this == &source)  // checking for self-assimilation
        return *this;

    delete[] m_string;

    m_size = source.m_size;
    m_string = source.m_string;
    source.m_string = nullptr;

    return *this;
}

size_t MyString::length() const {
    if (m_string == nullptr)
        return 0;

    return m_size - 1;
}

char* MyString::get() const {
    return m_string;
}

MyString operator+(const MyString& str1, const MyString& str2) {
    size_t size = 0;
    if (str1.m_string == nullptr && str2.m_string == nullptr)
        return str1;  // or str2

    if (str1.m_string == nullptr || str2.m_string == nullptr)
        size = std::max(str1.m_size, str2.m_size);
    else
        size = str1.m_size + str2.m_size - 1;

    char* temp = new char[size];
    size_t last_index = 0;

    for (int i = 0; i < str1.length(); ++i) {
        temp[i] = str1[i];
        last_index = i + 1;
    }

    for (int i = 0; i < str2.m_size; ++i)
        temp[last_index + i] = str2[i];

    return MyString(temp);
}

MyString operator-(const MyString& str1, const MyString& str2) {
    std::set<char> symbols;
    for (int i = 0; i < str2.length(); ++i) {
        symbols.insert(str2[i]);
    }

    size_t counter = 0;
    for (int i = 0; i < str1.length(); ++i) {
        if (symbols.count(str1[i]) == 0)
            ++counter;
    }

    if (counter == 0)
        return MyString();

    char* temp = new char[counter + 1];
    int index = 0;
    for (int i = 0; i < str1.m_size; ++i) {
        if (symbols.count(str1[i]) == 0)
            temp[index++] = str1[i];
    }

    return MyString(temp);
}

MyString operator*(const MyString& str, const int multiplier) {
    char* temp = new char[multiplier * str.length() + 1];
    int counter = multiplier;
    int index = 0;

    while (counter != 0) {
        for (int i = 0; i < str.length(); ++i) {
            temp[index++] = str[i];
        }

        --counter;
    }

    if (index == 0) {
        delete[] temp;

        return MyString();
    }

    temp[index] = '\0';

    return MyString(temp);
}

MyString operator*(const int multiplier, const MyString& str) {
    return str * multiplier;
}

bool operator==(const MyString& str1, const MyString& str2) {
    if (str1.m_size != str2.m_size)
        return false;

    if (str1.m_string == nullptr && str2.m_string == nullptr)
        return true;

    for (int i = 0; i < str1.m_size - 1; ++i) {
        if (str1[i] != str2[i])
            return false;
    }

    return true;
}

bool operator!=(const MyString& str1, const MyString& str2) {
    return !(str1 == str2);
}

bool operator>(const MyString& str1, const MyString& str2) {
    if (str1.m_string == nullptr)
        return false;

    if (str2.m_string == nullptr)
        return true;

    size_t length = std::min(str1.length(), str2.length());
    for (int i = 0; i < length; ++i) {
        if (str1[i] < str2[i])
            return false;

        if (str1[i] > str2[i])
            return true;
    }

    return false;
}

bool operator<(const MyString& str1, const MyString& str2) {
    return !(str1 >= str2);
}

bool operator>=(const MyString& str1, const MyString& str2) {
    return (str1 > str2) || (str1 == str2);
}

bool operator<=(const MyString& str1, const MyString& str2) {
    return !(str1 > str2);
}

MyString MyString::operator!() const {
    char* temp = new char[m_size];

    for (int i = 0; i < m_size; ++i) {
        if (static_cast<int>(m_string[i]) >= 'a' &&
            static_cast<int>(m_string[i]) <= 'z')

            temp[i] = static_cast<char>(m_string[i] - 32);
        else if (static_cast<int>(m_string[i]) >= 'A' &&
            static_cast<int>(m_string[i]) <= 'Z')

            temp[i] = static_cast<char>(m_string[i] + 32);
        else
            temp[i] = m_string[i];
    }

    return MyString(temp);
}

char MyString::operator[](const size_t index) const {
    try {
        if (index < 0 || index > this->length())
            throw static_cast<int>(index);

        return m_string[index];
    }
    catch (const int& throwing_index) {
        std::cerr << throwing_index << " - Incorrect index" << std::endl;
    }
}

bool MyString::operator()(const MyString& str) const {
    if (str.m_size > m_size || m_string == nullptr || str.m_string == nullptr)
        return false;

    for (int i = 0; i < this->length(); ++i) {
        if (m_string[i] == str[0]) {
            int temp_index = 1;
            bool flag = true;

            for (int j = i + 1; j < this->length() &&
                temp_index < str.length(); ++j) {
                if (m_string[j] != str[temp_index++]) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                return true;
        }
    }

    return false;
}

std::istream& operator>>(std::istream& in, MyString& str) {
    char buffer[kBufferSize];
    in.getline(buffer, kBufferSize);
    str = MyString(buffer);

    return in;
}

std::ostream& operator<<(std::ostream& out, const MyString& str) {
    if (str.m_string == nullptr) {
        out << "[STRING DOES NOT HAVE ANY SYMBOLS]";
        return out;
    }

    for (int i = 0; i < str.m_size; ++i)
        out << str[i];

    return out;
}
