//
// Created by administrator on 4/18/25.
//
#include "Hand.h"

Hand :: Hand() {

}
void Hand::clearHand() {
    m_hand.clear();
}
void Hand::operator+=(Card temp) {
    m_hand.push_back(temp);
}
Card Hand::displayCard(int i) {
    return m_hand[i];
}
int Hand::getPoints() {
    int points = 0;
    for (auto i : m_hand) {
        points += i.getValue();
        if(points > 21) {
            if(i.getRank()== "Ace") {
                points-=10;
            }
        }
    }
    return points;
}

int Hand::cardCount() {
    return m_hand.size();
}



