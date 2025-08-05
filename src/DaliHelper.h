#pragma once
#include "Arduino.h"

class DaliHelper
{
    public:
        static uint8_t percentToArc(uint8_t percent)
        {
            if (percent == 0)
                return 0;
            if (percent == 255)
                return 255;
            
            return ((253 / 3.0) * (log10(percent) + 1)) + 1;
        }

        static uint8_t arcToPercent(uint8_t arc)
        {
            if (arc == 0)
                return 0;
            if (arc == 255)
                return 255;
            
            return pow(10, ((arc-1) / (253/3.0)) - 1);
        }

};