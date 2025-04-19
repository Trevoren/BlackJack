cmake_minimum_required(VERSION 3.29)
project(BlackJack)

set(CMAKE_CXX_STANDARD 20)

add_executable(BlackJack main.cpp
        Card.h
        Card.cpp
        Deck.h
        Deck.cpp
        Hand.h
        Hand.cpp
        Game.h
        Game.cpp)
