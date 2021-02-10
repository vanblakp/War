#include "Deck.h"
#include "SidePile.h"
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

Deck* randomDecks() {
	vector<int> allCards;
	for (int k = 0; k < 13; k++) {
		allCards.push_back(k);
		allCards.push_back(k);
		allCards.push_back(k);
		allCards.push_back(k);
	}
	random_shuffle(allCards.begin(), allCards.end());

	Deck deck1, deck2;
	Deck* decks = new Deck[2];
	for (int k = 0; k < 26; k++) {
		decks[0].AddCards(allCards[k]);
	}
	for (int k = 26; k < 52; k++) {
		decks[1].AddCards(allCards[k]);
	}

	return decks;
}

int askMove(Deck player) {
	cout << "You draw a " << player.Peek() << ". What would you like to do?" << endl;
	cout << "[1] Play this card" << endl;
	cout << "[2] Play this card with a card from the side pile" << endl;
	cout << "[3] Push this card to the side and play the next card in the deck" << endl;
	string userInput;
	getline(cin, userInput);
}

int computerDecision(Deck computer) {
	return 1;
}

vector<int> playCards(Deck* player, int decision) {
     vector<int> cardsToPlay;
     if (decision == 1) {
         cardsToPlay.push_back(player->PlayCard());
     } else if (decision == 2) {
         player->PlayWithSide();
     } else {
         player->MoveCardToSide();
         cardsToPlay.push_back(player->PlayCard());
     }
     return cardsToPlay;
}

void playWar() {
	Deck* twoDecks = randomDecks();
	Deck player = twoDecks[0];
	Deck computer = twoDecks[1];
	delete[] twoDecks;

	while (computer.CountCards() > 0 && player.CountCards() > 0) {
		int playerdecision = askMove(player);
		int computersDecision = computerDecision(computer);


	}
}

int main()
{
	playWar();

