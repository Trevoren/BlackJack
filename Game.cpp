//
// Created by administrator on 4/18/25.
//
#include "Game.h"
#include <iostream>

Game::Game() {

}
Hand Game::getPlayerHand(Deck &d, Hand &h) {
    h+= d.dealCard();
    h+= d.dealCard();
    return h;
}
Hand Game::getDealerHand(Deck &d, Hand &h) {
    h+= d.dealCard();
    h+= d.dealCard();
    return h;
}
void Game::displayCards(Hand h, std::string name) {
    if(name=="Dealer") {
        std::cout << "Dealer's Cards:"<<std::endl;
    }
    else {
        std:: cout<< name <<"'s Cards:"<<std::endl;
    }
    for(int i=0; i < h.cardCount(); i++) {
        std::cout<< h.displayCard(i).getCard()<<std::endl;
    }
    std::cout << std::endl;
}
void Game::displayRound() {
    std:: cout<< "Dealer's Show Card: "<<std::endl;
    std:: cout<< m_dealerHand.displayCard(0).getCard()<<std::endl<<std::endl;
    displayCards(m_playerHand, "Player");
}
void Game::playGame() {
    std:: cout<<"###########################"<<std::endl;
std::cout<<"#  The Game of Blackjack  #"<<std::endl;
std::cout<<"###########################"<<std::endl<<std::endl;
    char again = 'y';
    while(again == 'y'|| again == 'Y') {
        m_deck = Deck();
        m_playerHand.clearHand();
        m_dealerHand.clearHand();
        m_playerHand = getPlayerHand(m_deck, m_playerHand);
        m_dealerHand = getDealerHand(m_deck, m_dealerHand);

        displayRound();

        char temp;
        do {
            std::cout<<"hit or stand? (h/s): ";
            std::cin>>temp;
            if(temp=='h' || temp=='H') {
                m_playerHand+=m_deck.dealCard();
                std::cout<<"Your Cards:"<<std::endl;
                for(int i = 0; i< m_playerHand.cardCount(); i++) {
                    std::cout<< m_playerHand.displayCard(i).getCard()<<std::endl;
                }
                std::cout<<std::endl;
            }

        } while(m_playerHand.getPoints() <21 &&(temp=='h' || temp=='H'));
        if(m_playerHand.getPoints() <= 21) {
            while(m_dealerHand.getPoints() < 17) {
                m_dealerHand+=m_deck.dealCard();
            }
        }
        std::cout<<"Dealer's Cards: "<<std::endl;
        for(int i=0; i<m_dealerHand.cardCount(); i++) {
            std:: cout<< m_dealerHand.displayCard(i).getCard()<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<< "Your Points: "<< m_playerHand.getPoints() << std::endl;
        std::cout<< "Dealer's Points: "<< m_dealerHand.getPoints() << std::endl;
        if(m_playerHand.getPoints() > 21) {
            std::cout<<"Sorry. You busted. You lose."<<std::endl;
        }else if(m_playerHand.getPoints() < m_dealerHand.getPoints() && m_dealerHand.getPoints()==21) {
            std::cout<<"Dealer has Blackjack. You lose."<<std::endl;
        }else if(m_playerHand.getPoints() == 21 && m_dealerHand.getPoints() != 21) {
            std::cout<<"Blackjack! You win!"<<std::endl;
        }else if(m_playerHand.getPoints() == 21 && m_playerHand.getPoints()==m_dealerHand.getPoints()) {
            std::cout<<"Dang, dealer has blackjack too. You push."<<std::endl;
        }else if(m_dealerHand.getPoints() > 21) {
            std::cout<<"Yay! The dealer busted. You win!"<<std::endl;
        }else if(m_playerHand.getPoints() == m_dealerHand.getPoints()) {
            std::cout<<"It's a tie! You push."<<std::endl;
        }else if(m_playerHand.getPoints() > m_dealerHand.getPoints()) {
            std::cout<<"Hooray! You win!"<<std::endl;
        }else if(m_playerHand.getPoints() < m_dealerHand.getPoints()) {
            std::cout<<"Sorry. You lose."<<std::endl;
        }else {
            std::cout<<"I'm not sure what happened."<<std::endl;
        }
        std::cout<<std::endl<<"play another round? (y/n): ";
        std::cin>>again;
        std::cout<<std::endl;
    }
    std::cout<<"Thanks for playing!"<<std::endl;
}


