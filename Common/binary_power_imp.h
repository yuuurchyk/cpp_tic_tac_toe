#ifndef BINARY_POWER_H
#define BINARY_POWER_H

namespace TicTacToe{
    template<class T>
    T binary_power(T number, int power){
        if(power == 0)
            return 1;
        if(power % 2 == 0)
            return binary_power(number * number, power / 2);
        else
            return number * binary_power(number, power - 1);
    }
}

#endif