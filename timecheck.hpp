#ifndef TIMECHECK_HPP
#define TIMECHECK_HPP
#include <SFML/System.hpp>
#include <ctime>

class Timecheck
{
    private:
        sf::Time m_t;
        sf::Time m_current;
        sf::Clock m_clock;

    public:
        Timecheck();
        void startClock();
        bool conditionTimer(sf::Time time);
};

#endif //TIMECHECK_HPP
