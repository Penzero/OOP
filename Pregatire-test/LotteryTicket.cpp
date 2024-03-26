#include "LotteryTicket.h"

int LotteryTicket::numbers_match(const LotteryTicket& other) {
    bool ok = 0;
    for(int i = 0; i < 6; i++){
        if(extractedNumbers[i] == 0) 
            ok = 1;
        if(ok == 1 && extractedNumbers[i] != 0)
            throw std::invalid_argument("Invalid number");
    }
    if(this->drawDate.differenceInDays(other.drawDate) > 7)
        throw std::invalid_argument("Invalid date");
    
    int count = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (this->extractedNumbers[i] == other.extractedNumbers[j]) {
                count++;
            }
        }
    }
    return count;
}