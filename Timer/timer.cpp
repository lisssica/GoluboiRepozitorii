#include <iostream>
#include <chrono>
#include <vector>
#include <timer.h>

Timer::Timer()
{
    Start();
}

Timer::~Timer()
{
    Stop();
}

void Timer::Start()
{
    if (!_isActive)
    {
        std::vector<time_point_t> interval = {clock_t::now()};
        _intervals.push_back(interval);
        _currentInterval = _intervals.size() - 1;
        _isActive = true;
    }
}

void Timer::Pause()
{
    if (_isActive)
    {
        _isActive = false;
        _intervals[_currentInterval].push_back(clock_t::now());
    }
}

void Timer::Lap()
{
    if (_isActive)
    {
        _intervals[_currentInterval].push_back(clock_t::now());
    }
}

void Timer::Print()
{
    int totalElapsedTime = 0;
    int currentLap = 0;

    for (auto interval = 0; interval < _intervals.size(); interval++)
    {
        for (auto innerLap = 1; innerLap < _intervals[interval].size(); innerLap++)
        {
            int currentInterval = std::chrono::duration_cast<std::chrono::milliseconds>(_intervals[interval][innerLap] - _intervals[interval][innerLap - 1]).count();
            totalElapsedTime += currentInterval;

            std::cout << "Lap " << currentLap << " time: " << currentInterval << " TotalTime: " << totalElapsedTime << std::endl;
            currentLap++;
        }
    }

    std::cout << std::endl;
    std::cout << "total elapsed time: " << totalElapsedTime << " ms" << std::endl;
}

void Timer::Stop()
{
    if (_isActive)
    {
        _isActive = false;
        _intervals[_currentInterval].push_back(clock_t::now());
        Print();
    }
    else
    {
        Print();
    }
}
