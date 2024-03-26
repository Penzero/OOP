#include <iostream>
#include <cstdlib>
#include "Date.h"

class LotteryTicket {
    private:
        static int extractedNumbers[6];
        Date drawDate;
    
    public:
        LotteryTicket(): drawDate(2024, 3, 26) {
            for (int i = 0; i < 6; i++) {
                extractedNumbers[i] = 1 + rand() % 49;
            }
        }

        void setExtractedNumbers(int extractedNumbers[6]) {
            bool ok = 0;
            for(int i = 0; i < 6; i++) {
                if(extractedNumbers[i] == 0) 
                    ok = 1;
                if(ok == 1 && extractedNumbers[i] != 0)
                    throw std::invalid_argument("Invalid number");
            }
            for (int i = 0; i < 6; i++) {
                if (extractedNumbers[i] < 1 || extractedNumbers[i] > 49) {
                    throw std::invalid_argument("Invalid number");
                }
                LotteryTicket::extractedNumbers[i] = extractedNumbers[i];
            }
        }

        void setZeroExtractedNumbers() {
            for (int i = 0; i < 6; i++) {
                this->extractedNumbers[i] = 0;
            }
        }

        void setDrawDate(const Date& drawDate) {
            this->drawDate = drawDate;
        }
        
        int numbers_match(const LotteryTicket& other);
};