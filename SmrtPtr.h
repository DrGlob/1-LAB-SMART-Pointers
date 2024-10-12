template<typename T>
class SmrtPtr {
private:
    T * val;
    mutable int* count;
public:
    SmrtPtr() : val(nullptr), count(new int(0)) {}
    SmrtPtr(T& val) : val(new T(val)), count(new int(1)) {}
    
    SmrtPtr& operator=(const SmrtPtr& other) {
        if (this != other) {
            --(*count);
            if (*count == 0) {
                delete val;
                delete count;
            }
            *val = *(other.val);
            *count = *(other.count) + 1;
        }
        return *this;
    }
    SmrtPtr& operator = (T& right) {
        if (val == nullptr) {
            val = new T(right);
        } else {
            *val = right;
        }
        ++(*count);
        return *this;
    }
    SmrtPtr& operator = (T* right) {
        if (val == NULL) {
            val = new T(*right);
        } else {
            *val = *right;
        }
        ++(*count);
        return *this;
    }
    T& operator * () {
        return *val;
    }
    T* operator -> () { return val; }
    ~SmrtPtr() {
        --(*count);
        if (*count == 0) {
            delete val;
            delete count;
            std::cout << "huy" << '\n';
        }
    }
    T* get() {
        return val;
    }

    T get_data(){
        return *val;
    }

    void set_data(T v){
        if (val == nullptr){
            val = new T(v);
        }
        *val = v;
    }
};
