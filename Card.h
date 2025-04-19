//
// Created by administrator on 4/18/25.
//

#ifndef CARD_H
#define CARD_H
#include <string>


class Card {
    private:
    std::string m_suit;
    std::string m_rank;
    int m_value;
    public:
    Card();
    Card(std::string suit, std::string rank, int value);
    std::string getRank();
    int getValue();
    std::string getCard();
};
#endif //CARD_H
