#define _CRT_SECURE_NO_WARNINGS
#include <string>;
#include <iostream>;

using namespace std;

class User
{

private:
	const int id;
	string name;
	string phoneNumber;

};


class Ticket
{
	const int id;
	string section;
	int row;
	int seat;
	int price;
	int noOfPriceChanges;
	int* priceHistory;

	static int noOfTickets;

public:

	Ticket(int id, string section, int row, int seat) : id(id)
	{
		this->section = section;
		this->seat = seat;
		this->row = row;

		noOfTickets++;
	}

	Ticket(int id, int price, int noOfPriceChanges, int* priceHistory) :id(id)
	{
		this->price = price;
		this->noOfPriceChanges = noOfPriceChanges;

		if (priceHistory != nullptr)
		{
			this->priceHistory = new int[noOfPriceChanges];
			for (int i = 0; i< noOfPriceChanges; i++) {
				this->priceHistory[i] = priceHistory[i];
			}
		}
		else {
			this->priceHistory = nullptr;
		}

		noOfTickets++;
	}

	Ticket(const Ticket& t) : id(t.id) 
	{
		this->section = t.section;
		this->seat = t.seat;
		this->row = t.row;
		this->price = t.price;
		this->noOfPriceChanges = t.noOfPriceChanges;

		if (t.priceHistory != nullptr)
		{
			this->priceHistory = new int[noOfPriceChanges];
			for (int i = 0; i < noOfPriceChanges; i++) {
				this->priceHistory[i] = t.priceHistory[i];
			}
		}
		else {
			this->priceHistory = nullptr;
		}

		noOfTickets++;
	}

	~Ticket()
	{
		if (this->priceHistory != nullptr)
		{
			delete[] this->priceHistory;
		}
	}

};



int main() {

	return 0;
}