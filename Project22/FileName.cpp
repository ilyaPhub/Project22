#include <iostream>
using namespace std;

class MyString {
private:
    char* str;
    size_t size;

public:
    MyString(const char* arr, size_t arr_size) {
        size = arr_size;
        str = new char[size + 1];
        for (size_t i = 0; i < size; ++i) {
            str[i] = arr[i];
        }
        str[size] = '\0';
    }

    MyString(MyString&& other) noexcept {
        str = other.str;
        size = other.size;
        other.str = nullptr;
        other.size = 0;
    }

    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            size = other.size;
            other.str = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~MyString() {
        delete[] str;
    }

    void print() const {
        cout << str << endl;
    }
};

int main() {
    char arr[] = { 'H', 'e', 'l', 'l', 'o' };
    MyString obj(arr, sizeof(arr) / sizeof(arr[0]));
    obj.print();

    MyString moved = std::move(obj);
    moved.print();
    obj.print();  

    return 0;
}
