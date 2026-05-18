#include <iostream>

template <typename T, typename S>
class Pair 
{
    private:
        T value_1;
        U value_2;

    public:
        pair(T v_1, U v_2) : value_1(v_1), value_2(v_2) {};
        T get_value_1() {return this->value_1;};
        U get_value_2() {return this->value_2;};
        void set_value_1(T v_1) {this->value_1 = v_1;};
        void set_value_2(U v_2) {this->value_2 = v_2;};
};

int main()
{


    return 0;
}