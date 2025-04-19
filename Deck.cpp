//
// Created by administrator on 4/18/25.
//
#include<vector>
#include<iostream>
#include<algorithm>
#include<random>

#include "Deck.h"
#include "Card.h"

Deck::Deck() {
    std::vector<std::string> suits{"Hearts", "Diamonds", "Spades", "Clubs"};
    std::vector<std::string> ranks{"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    std::vector<int> values{2,3,4,5,6,7,8,9,10,10,10,10,11};
    for(int i = 0; i < suits.size(); i++) {
        for(int j =0; j < ranks.size(); j++) {
            m_cardDeck.push_back(Card(suits[i],ranks[j],values[j]));
        }
    }
    shuffleDeck();
}

void Deck::shuffleDeck() {
    std::random_device rd;
    std::mt19937 gen(rd());
    //gen.seed(0);
    std::shuffle(m_cardDeck.begin(), m_cardDeck.end(), gen);
}
Card Deck::dealCard() {
    Card temp;
    temp=m_cardDeck.back();
    m_cardDeck.pop_back();
    return temp;
}
int Deck::getCount() {
    return m_cardDeck.size();
}

