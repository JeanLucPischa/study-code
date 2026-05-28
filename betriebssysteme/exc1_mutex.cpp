#include <iostream>
#include <thread>
#include <mutex>

constexpr int NUM_ITERATIONS = 1000000;
int counter = 0;

std::mutex mtx;

void increment_loop()
{
    mtx.lock();

    for (int i = 0; i < NUM_ITERATIONS; ++i)
    {
        ++counter;
    }

    mtx.unlock();
}

int main()
{
    std::thread t1{increment_loop};
    std::thread t2{increment_loop};

    // t1.join();
    // t2.join();

    std::cout << "Endwert: " << counter << '\n';
}

//2.    Ausgabe: "Endwert: 0"; -> "terminate called without an active exception"
