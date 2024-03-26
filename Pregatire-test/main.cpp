#include <iostream>
#include <stdexcept>
#include "Date.h"
#include "LotteryTicket.h"

int main() {
    try {
        // Create a LotteryTicket object on the stack
        LotteryTicket lotteryTicket;

        // Create a Date object on the heap
        LotteryTicket* lotteryTicketHeap = new LotteryTicket();

        LotteryTicket tickets[100];
        tickets[0] = lotteryTicket;
        tickets[1] = *lotteryTicketHeap;
        for (int i = 2; i < 100; i++) {
            tickets[i] = LotteryTicket();
        }

        LotteryTicket extractedNumbers;
        extractedNumbers.setExtractedNumbers(new int[6]{7, 11, 28, 33, 44, 49});
        extractedNumbers.setDrawDate(Date(2024, 3, 26));
        
        int num4 = 0, num5 = 0, num6 = 0;

        for (int i = 0; i < 100; i++) {
            if(tickets[i].numbers_match(extractedNumbers) == 4) {
                num4++;
            } else if(tickets[i].numbers_match(extractedNumbers) == 5) {
                num5++;
            } else if(tickets[i].numbers_match(extractedNumbers) == 6) {
                num6++;
            }
        }
        std::cout << "Numarul de bilete cu 4 numere castigatoare: " << num4 << std::endl;
        std::cout << "Numarul de bilete cu 5 numere castigatoare: " << num5 << std::endl;
        std::cout << "Numarul de bilete cu 6 numere castigatoare: " << num6 << std::endl;
        // Don't forget to delete the heap object after use
        delete lotteryTicketHeap;
    } catch (std::invalid_argument& e) {
        std::cerr << "Invalid date: " << e.what() << std::endl;
    }
}