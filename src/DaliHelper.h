#pragma once
#include "Arduino.h"

class DaliHelper
{
    public:
        static uint8_t percentToArc(uint8_t percent)
        {
            if (percent == 0)
                return 0;
            if (percent == 100)
                return 254;
            
            return ((253 / 3.0) * (log10(percent) + 1)) + 1;
        }

        static float arcToPercent(uint8_t arc)
        {
            if (arc == 0)
                return 0;
            if (arc == 255)
                return 100;
            
            return pow(10, ((arc-1) / (253/3.0)) - 1);
        }

        static uint32_t fadeTimeFromNumber(uint8_t number) {
            switch (number)
            {
            case 0:
                return 50;
                break;
            case 1:
                return 700;
                break;
            case 2:
                return 1000;
                break;
            case 3:
                return 1400;
                break;
            case 4:
                return 2000;
                break;
            case 5:
                return 2800;
                break;
            case 6:
                return 4000;
                break;
            case 7:
                return 5700;
                break;
            case 8:
                return 8000;
                break;
            case 9:
                return 11300;
                break;
            case 10:
                return 16000;
                break;
            case 11:
                return 22600;
                break;
            case 12:
                return 32000;
                break;
            case 13:
                return 45300;
                break;
            case 14:
                return 64000;
                break;
            case 15:
                return 90500;
                break;
            default:
                Serial.printf("Got unknown fade time number %u\n", number);
                return 100;
                break;
            }
        }

        static float fadeRateFromNumber(uint8_t number) {
            switch (number)
            {
            case 0:
                return 358;
                break;
            case 1:
                return 253;
                break;
            case 2:
                return 179;
                break;
            case 3:
                return 127;
                break;
            case 4:
                return 89.4;
                break;
            case 5:
                return 63.3;
                break;
            case 6:
                return 44.7;
                break;
            case 7:
                return 31.6;
                break;
            case 8:
                return 22.4;
                break;
            case 9:
                return 15.8;
                break;
            case 10:
                return 11.2;
                break;
            case 11:
                return 7.9;
                break;
            case 12:
                return 5.6;
                break;
            case 13:
                return 4.0;
                break;
            case 14:
                return 2.8;
                break;
            case 15:
                return 1.4;
                break;
            default:
                Serial.printf("Got unknown fade rate number %u\n", number);
                return 10;
                break;
            }
        }
};