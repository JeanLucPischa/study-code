// exc2:
// output: "Endwert: 0"; error: "terminate callled without an active exception"

#include <iostream>
#include <thread>
#include <semaphore>

constexpr int NUM_ITERATIONS_1M = 1000000;
constexpr int NUM_ITERATIONS_500K = 500000;
int counter = 0;

std::binary_semaphore region(1);

void increment_loop_1M()
{
    for (int i = 0; i < NUM_ITERATIONS_1M; ++i)
    {
        region.acquire();
        ++counter;
        region.release();
    }
}

void increment_loop_500K()
{
    for (int i = 0; i < NUM_ITERATIONS_500K; ++i)
    {
        region.acquire();
        ++counter;
        region.release();
    }
}

int main()
{
    std::thread t1{increment_loop_1M};
    std::thread t2{increment_loop_1M};
    std::thread t3{increment_loop_500K};

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Endwert: " << counter << '\n';
}
