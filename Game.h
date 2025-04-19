//
// Created by administrator on 4/18/25.
//

#ifndef GAME_H
#define GAME_H
#include <string>
#include "Hand.h"
#include "Deck.h"


class Game {
private:
    Hand m_dealerHand;
    Hand m_playerHand;
    Deck m_deck;
public:
    Game();
    Hand getPlayerHand(Deck &d, Hand &h);
    Hand getDealerHand(Deck &d, Hand &h);
    void displayCards(Hand h, std::string name);
    void displayRound();
    void playGame();
};
#endif //GAME_H
