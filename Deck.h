#pragma once
#include "Node.h"
#include "SidePile.h"
using namespace std;

class Deck {
private:
	Node* top;
	SidePile pile;
public:
	Deck();
	int PlayCard();
	void AddCards(int c1);
	int CountCards();
	void MoveCardToSide();
	int PlayWithSide();
	int Peek();
};

Deck::Deck() {
	Node* temp = new Node(1);
	top = temp;
	for (int i = 1; i < 13; i++) {
		temp = top;
		top->data = i + 1;
		top->next = temp;
	}
}

int Deck::PlayCard() {
	int temp = top->data;
	Node* toDelete = top;
	top = top->next;
	delete toDelete;
	return temp;
}

void Deck::AddCards(int c1) {
	Node* temp = top;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = new Node(c1);
}

int Deck::CountCards() {
	int counter = 0;
	Node* temp = top;
	while (temp != nullptr) {
		temp = temp->next;
		counter++;
	}
	return counter;
}

void Deck::MoveCardToSide() {
	/*if (pile.CardsInPile() == 5) {
		//throw error
	} */
	pile.AddToPile(PlayCard());
}

int Deck::Peek() {
	int temp = top->data;
	return temp;

