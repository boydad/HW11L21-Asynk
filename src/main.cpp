#include <iostream>
#include <chrono>
#include <thread>

#include "async.h"


int main(int, char *[]) {
    std::size_t bulk = 5;
    auto h = async::connect(bulk);
    auto h2 = async::connect(bulk);
    async::receive(h, "1", 1);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    async::receive(h2, "1\n", 2);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    async::receive(h, "\n2\n3\n4\n5\n6\n{\na\n", 15);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    async::receive(h, "b\nc\nd\n}\n89\n", 11);
    async::disconnect(h);
    async::disconnect(h2);

    return 0;
}
    