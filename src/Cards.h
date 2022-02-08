#pragma once

#include <fstream>

#include "List.h"

enum class Suit { SPADES, DIAMONDS, CLUBS, HEARTS };

using Rank = int;

constexpr Rank ACE   = 1;
constexpr Rank JACK  = 11;
constexpr Rank QUEEN = 12;
constexpr Rank KING  = 13;

struct Card {
    Suit suit;
    Rank rank;
};

List<Card> buildDeck(std::ifstream& file);

List<Card> shuffle(const List<Card>& deck);
