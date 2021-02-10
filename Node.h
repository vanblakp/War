#pragma once
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int i) {
		data = i;
		next = nullptr;
	}
}
