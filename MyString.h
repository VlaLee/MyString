  // Copyright 2024 Lee V.

#ifndef INCLUDE_MYSTRING_H
#define INCLUDE_MYSTRING_H

#include <string>

constexpr size_t kBufferSize = 1e6;

class MyString {
 private:
    char* m_string;
    size_t m_size;

 public:
    explicit MyString(const char* str = nullptr);
    explicit MyString(const std::string& str);
    MyString(const MyString& str);
    MyString(MyString&& str);

    ~MyString();

    MyString& operator= (const MyString& source);
    MyString& operator= (MyString&& source);

    size_t length() const;
    char* get() const;

    friend MyString operator+(const MyString& str1, const MyString& str2);
    friend MyString operator-(const MyString& str1, const MyString& str2);
    friend MyString operator*(const MyString& str, const int multiplier);
    friend MyString operator*(const int multiplier, const MyString& str);

    friend bool operator==(const MyString& str1, const MyString& str2);
    friend bool operator!=(const MyString& str1, const MyString& str2);
    friend bool operator>(const MyString& str1, const MyString& str2);
    friend bool operator<(const MyString& str1, const MyString& str2);
    friend bool operator>=(const MyString& str1, const MyString& str2);
    friend bool operator<=(const MyString& str1, const MyString& str2);

    MyString operator!() const;
    char operator[](const size_t index) const;
    bool operator()(const MyString& str) const;

    friend std::istream& operator>>(std::istream& in, MyString& str);
    friend std::ostream& operator<<(std::ostream& out, const MyString& str);
};

#endif  // INCLUDE_MYSTRING_H
