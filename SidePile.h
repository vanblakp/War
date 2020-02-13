#pragma once
using namespace std;

class SidePile {
private:
	int pile[5];
public:
	int CardsInPile();
	void AddToPile(int i);
	int TakeFromPile();
};

int SidePile::CardsInPile() {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (pile[i] != 0) {
			counter += 1;
		}
	}
	return counter;
}

void SidePile::AddToPile(int i) {
	/*if (CardsInPile() == 5) {
		//throw error
	}*/
	int counter = 0;
	while (pile[counter] != 0) {
		counter += 1;
	}
	pile[counter] = i;
}

int SidePile::TakeFromPile() {
	if (CardsInPile() == 0) {
		throw value;
	}
	int counter = 4, temp;
	while (pile[counter] == 0) {
		counter -= 1;
	}
	temp = pile[counter];
	pile[counter] = 0;
	return temp;
}

int SidePile::TakeFromPile(){}
