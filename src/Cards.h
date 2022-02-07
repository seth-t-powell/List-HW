#pragma once

#include <utility>
#include <vector>

#include "LinkedList.h"

enum class Suit { SPADES, DIAMONDS, CLUBS, HEARTS };

#define ACE   1
#define JACK  11
#define QUEEN 12
#define KING  13

using Card = std::pair<Suit, int>;

std::vector<Card> buildDeck(const char* filepath);

LinkedList<Card> shuffle(const std::vector<Card>& deck);
