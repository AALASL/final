#pragma once

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card
{
	private:
		//initialize private variables
		int cardNumber;
		std::string faceCard;
		std::string cardSuit;
	
	public:
		//constructor
		Card() {};
		Card(int number, std::string suit) {
			this->cardNumber = number;
			this->cardSuit = suit;
			
			if (number == 11) {
				this->faceCard = "Jack";
			}
			else if (number == 12) {
				this->faceCard = "Queen";
			}
			else if (number == 13) {
				this->faceCard = "King";
			}
			else if (number == 1) {
				this->faceCard = "Ace";
			}
			else {
				this->faceCard = std::to_string(number);
			}
		}
		Card(std::string face, std::string suit) {
			this->cardSuit = suit;
			this->faceCard = face;

			if (face == "Jack") {
				this->cardNumber = 11;
			}
			else if (face == "Queen") {
				this->cardNumber = 12;
			}
			else if (face == "King") {
				this->cardNumber = 13;
			}
			else if (face == "Ace") {
				this->cardNumber = 1;
			}
		}

		//return the number of the Card object
		int getNumber() {
			return cardNumber;
		}
		//set the number of the Card object
		void setNumber(int number) {
			this->cardNumber = number;
		}

		//return the suit of the Card object
		std::string getSuit() {
			return cardSuit;
		}
		//set the suit of the Card object
		void setSuit(std::string suit) {
			this->cardSuit = suit;
		}

		//return face of the Card object
		std::string getFace() {
			return faceCard;
		}
		//set face with name
		void setFace(std::string face) {
			this->faceCard = face;
		}
		//set face with number
		void setFace(int face) {
			this->faceCard = std::to_string(face);
		}
};

#endif