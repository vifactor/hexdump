#include <iostream>


template<typename T, typename U>
struct TwoLambdasGuard {
    TwoLambdasGuard(T&& onEnter, U&& onExit): 
        _onExit(std::forward<U>(onExit))
    {onEnter();}

    ~TwoLambdasGuard() {
        _onExit();
    }
private:
    U _onExit;
};


int main() {
    {
        TwoLambdasGuard guard([]{
            std::cout << "On Enter" << std::endl;
        }, []{
            std::cout << "On Exit" << std::endl;
        });

        std::cout << "Some code" << std::endl;
    }

    return 0;
}