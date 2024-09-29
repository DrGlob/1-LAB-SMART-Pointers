template<typename T>
class SharedPtr{
private:
    T* ptr;
    int* count;
public:
    explicit SharedPtr(T* ptr) : ptr(ptr), count(new int(1)) {};
   
    SharedPtr(const SharedPtr& other) noexcept : ptr(other.ptr), count(other.count) {
         ++*count;
    }

    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), count(other.count) {
        other.ptr = nullptr;
        other.count = nullptr;
    } // move конструктор

    // move signent рператор
    // написать функцию make_shared позволяет, минуя стадию new (конструирование C pointer) 
    // эту функцию мы вызываем от аргументов конструктора
    // цель - перестать писать new
    ~SharedPtr() {
        if (!count) return;
        --*count;
        if (*count == 0) {
            delete ptr;
            delete count;
        }
    }

};