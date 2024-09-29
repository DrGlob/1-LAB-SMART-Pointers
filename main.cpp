// /home/students/g/gataullin.ar/GlebLove12
#include <iostream>
#include "SmrtPtr.h"
#include "ShrdPtr.h"
#include <string.h>

void testSmrtPtr() {
    int x = 50;
    SmrtPtr<int> pointer;
    pointer = &x;
    // *pointer = 100;
    int* pp = pointer.get();
    std::cout << *pp;
    if (*pointer == pointer.get_data()){
        std::cout << pointer.get_data() << std::endl;
    }
}
// ssh gataullin.ar@samos.dozen.mephi.ru -p 22  заход на сервер
// 5ogdjtarp1 пароль

void testShrdPtr() {
    int x = 50;
    ShrdPtr<int> ptr;
    ptr = &x;

}

void f(std:: shared_ptr<int> p) {
    std::cout << p.get();
}
int main() {
    std::shared_ptr<int> p(new int(5));
    std::shared_ptr<int> pp = p;
    f(p);
    f(std::move(pp));
    pp = std:: move(p);
}

// int main() {
    
//     //  std::string s = "abc";
//     // std::string s1 = s;
//     // s = s1;
//     // Двойная утечка памяти из-за потери указателя

//     // testSmrtPtr();
//     testShrdPtr();
//     return 0;
// }