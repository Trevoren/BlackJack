//
// Created by administrator on 4/18/25.
//
#include "Card.h"

Card::Card() {
    m_suit="";
    m_rank="";
    m_value=0;
}
Card::Card(std::string suit, std::string rank, int value) {
    m_suit=suit;
    m_rank=rank;
    m_value=value;
}
std::string Card::getRank() {
    return m_rank;
}
int Card::getValue() {
    return m_value;
}
std::string Card::getCard() {
    return m_rank + " of " + m_suit;
}

