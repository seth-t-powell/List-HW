#pragma once

#include <utility>
#include <vector>

#include "LinkedList.h"

enum class Suit { SPADES, DIAMONDS, CLUBS, HEARTS };

using Rank = int;

constexpr Rank ACE   = 1;
constexpr Rank JACK  = 11;
constexpr Rank QUEEN = 12;
constexpr Rank KING  = 13;

struct Card {
    Suit suite;
    Rank rank;
};

std::vector<Card> buildDeck(const char* filepath);

LinkedList<Card> shuffle(const std::vector<Card>& deck);
