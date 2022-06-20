#pragma once
#include <random>


class RandomRange
{
public:
    RandomRange(int begin, int end);
    RandomRange(const RandomRange&) = delete;
    ~RandomRange();

    int GetNext();
    void Resize(int begin, int end);
    bool Remove(int value);

private:
    std::default_random_engine _e;
    int* _array = nullptr;
    int _arrayLength = 0;
    int _currentIndex = 0;
};
