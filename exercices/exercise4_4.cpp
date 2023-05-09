#include <iostream>

class Singleton {
    public:
        static Singleton* getInstance();
        void setValue(int val) {value_ = val;}
        int getValue()  {return(value_);}

    protected:
        int value_;

    private:
        static Singleton* inst_;
        Singleton() : value_(0) {}
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
};

Singleton* Singleton::inst_ = NULL;

Singleton* Singleton::getInstance() {
    if (inst_ == NULL) {
        inst_ = new Singleton();
    }
    return(inst_);
}

int main() {

   Singleton* p1 = Singleton::getInstance();

   p1->setValue(10);
    
   Singleton* p2 = Singleton::getInstance();

   std::cout << "Value = " << p2->getValue() << '\n';
}