template<typename T>
class UniqPtr {
private:
    T* ptr;
public:
    explicit UniqPtr(T* ptr) : ptr(ptr) {}
    UniqPtr(const UniqPtr &) = delete;
    UniqPtr& operator = (const UniqPtr&) = delete;
    UniqPtr(UniqPtr && other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    } // 

    auto& operator= (UniqPtr& other) noexcept {
        if (ptr == other.ptr) { // не знвю, так ли это работает?
            other.ptr = nullptr;
            return *this;
        }
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
    ~UniqPtr() {
        delete ptr;
    }
    void reset() { // обнуление
        delete ptr;
        ptr = nullptr;
    }
    T get() const {
        return *ptr;
    }
};