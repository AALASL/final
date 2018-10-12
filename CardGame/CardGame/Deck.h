#pragma once

#ifndef DECK_H
#define DECK_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Card.h"

class Deck
{
private:
	//initialize private variables
	std::vector<Card> deck;

public:
	//constructor - add cards to deck then suffles them
	Deck() {
		initDeck();
		deck.shrink_to_fit();
		shuffleDeck();
	}
	Deck(int null) {

	}

	//fill deck with cards
	void initDeck()
	{
		//init Spades
		for (int i = 1; i <= 13; i++) {
			deck.emplace(deck.begin(), Card(i, "Spades"));
		}

		//init Hearts
		for (int i = 1; i <= 13; i++) {
			deck.emplace(deck.begin(), Card(i, "Hearts"));
		}

		//init Diamonds
		for (int i = 1; i <= 13; i++) {
			deck.emplace(deck.begin(), Card(i, "Clubs"));
		}

		//init Clubs
		for (int i = 1; i <= 13; i++) {
			deck.emplace(deck.begin(), Card(i, "Diamonds"));
		}
	}

	//return size of deck
	int getSize() {
		return deck.size();
	}

	//return card array
	std::vector<Card> getDeck() {
		return deck;
	}
	//update entire deck with another one
	void updateDeck(std::vector<Card> cardDeck) {
		for (int i = 0; i < getSize(); i++) {
			this->deck[i] = cardDeck[i];
		}
	}
	//update specific card in the deck
	void addCard(int pos, Card card) {
		deck.insert(deck.begin() + pos, card);
	}
	//return specific card in the deck
	Card getCard(int pos) {
		return deck[pos];
	}
	
	vector<string> getAllCards() {
		vector <string> yourCards;
		for (int i = 0; i < deck.size(); i++) {
			yourCards.push_back(getCard(i).getFace);
		}
		return yourCards;
	}

	Card takeCard(int pos) {
		Card temp = deck[pos];
		deck.erase(deck.begin() + pos);
		return temp;
	}
	//shuffles the deck in random order
	void shuffleDeck() {
		std::random_shuffle(deck.begin(), deck.end());
	}
};

#endif