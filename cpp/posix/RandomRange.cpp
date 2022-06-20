
#include "RandomRange.h"
#include <chrono>


RandomRange::RandomRange(int begin, int end) 
    : _e((int)std::chrono::steady_clock::now().time_since_epoch().count())
{
    Resize(begin, end);
}

RandomRange::~RandomRange()
{
    if (_array)
    {
        delete[] _array;
    }
}

int RandomRange::GetNext()
{
    if (!_array)
        return 0;

    if (_currentIndex >= _arrayLength)
    {
        std::shuffle(_array, _array + _arrayLength - 1, _e);
        _currentIndex = 0;
    }

    return _array[_currentIndex++];
}

void RandomRange::Resize(int begin, int end)
{
    if (_array)
        delete[] _array;
    _arrayLength = end - begin + 1;
    _array = new int[_arrayLength];
    _currentIndex = 0;

    for (int i = 0; i < _arrayLength; ++i)
        _array[i] = begin + i;
    std::shuffle(_array, _array + _arrayLength - 1, _e);
}

bool RandomRange::Remove(int value)
{
    if (!_array)
        return false;

    for (int i = _currentIndex; i < _arrayLength; ++i)
    {
        if (_array[i] == value)
        {
            int temp = _array[_currentIndex];
            _array[_currentIndex] = _array[i];
            _array[i] = temp;
            ++_currentIndex;
            return true;
        }
    }
    return false;
}
