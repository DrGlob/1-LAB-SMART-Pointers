template<typename T>
class ShrdPtr {
private:
    T* val;
    int* count;
    // блок count должен быть общи у всех ссылающихся на этот объект
    //https://learn.microsoft.com/ru-ru/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-170
public:
    ShrdPtr() : val(nullptr), count(new int(0)) {}
    ShrdPtr(T val) : val(new T(val)) {
        ++(*count);
    }
    ShrdPtr(T& val) {
        // if () {

        // }
    }
    ShrdPtr& operator = (ShrdPtr& other) {
        delete val;
        val = other.get();
        count = other.count;
        ++(*count);
    }
    ShrdPtr& operator = (T& other) {
        if (other == *val) {
            ++(*count);
        } else {
            delete val;
            --(*count);
            val = new T(other);
            count = new int(1); // так как изначально count мог использоваться и для других объектов
        }
    }
    ShrdPtr& operator = (T* other) {
        if (other == val) {
            ++(*count);
        } else {
            delete val;
            --(*count);
            val = other;
            count = new int(1);
        }
        return *this;
    }
//     ShrdPtr (T& val) {
//         delete val;
//         --(*count);
// // если переименовываем и указатель указывает на другую область памяти
// //                      надо разобраться
//         (*val) = val;
//         ++(*count);
//     }
    T& operator *() const {
        return *val;
    }
    T* get() {
        return val;
    }

    ~ShrdPtr() {
        --(*count);
        if (*count == 0) {
            delete val;
            delete count;
        }
    }
};