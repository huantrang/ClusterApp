#ifndef CLUSTERSTRUCT_H
#define CLUSTERSTRUCT_H
#include <cstdint>
#include <string>
struct SpeedData
{
    explicit SpeedData(double m_Speed, uint64_t m_LimitedSpeed, std::string m_Unit)
        : m_Speed(m_Speed), m_LimitedSpeed(m_LimitedSpeed), m_Unit(m_Unit) {}
    double m_Speed;
    uint64_t m_LimitedSpeed;
    std::string m_Unit;
};


#endif // CLUSTERSTRUCT_H
