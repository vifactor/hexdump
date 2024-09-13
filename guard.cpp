#include <iostream>

#include <coroutine>
#include <type_traits>

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

struct nothing {};
struct GuardEngine {
    struct promise_type {
        std::suspend_never initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void unhandled_exception() {}
        std::suspend_always yield_value(nothing) { return {}; }
        GuardEngine get_return_object() {
            return {std::coroutine_handle<promise_type>::from_promise(*this)};
        }
    };
    
    void resume() {
        handle();
    }

    std::coroutine_handle<promise_type> handle;
};

template<typename Coro>
struct CoroGuard {
    CoroGuard(Coro&& _coro): coro(std::forward<Coro>(_coro)()) {
    };
    
    ~CoroGuard() {
        coro.resume();
    }
    std::invoke_result_t<Coro> coro;
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

    std::cout << "-----------" << std::endl;
    {
        CoroGuard guard([]() -> GuardEngine {
            std::cout << "On enter" << std::endl;
            co_yield {};
            std::cout << "On exit" << std::endl;
            }
        );
        std::cout << "Some code" << std::endl;
    }

    return 0;
}