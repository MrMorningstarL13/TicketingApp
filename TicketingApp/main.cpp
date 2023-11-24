#define _CRT_SECURE_NO_WARNINGS
#include <string>;
#include <iostream>;
#include <regex>

using namespace std;

//enum ticketEvent = {Theater, Movie, Football};

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

	Ticket() : id(1) {
		this->section = "";
		this->row = 0;
		this->seat = 0;
		this->price = 0;
		this->noOfPriceChanges = 0;
		this->priceHistory = nullptr;
	}

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

	//Setters

	void setSection(string section) {
		if (section != "Court 1" || section != "Court 2") {
			throw exception("This is not an available section!");
		}
		this->section = section;
	}

	void setRow(int row) {
		if (row != (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13)){
			throw exception("This row does not exist!");
		}
		this->row = row;
	}

	void setSeat(int seat) {
		if (seat != (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24)) {
			throw exception("This seat does not exist!");
		}
		this->seat = seat;
	}

	void setPrice(int price) {
		if (price < 20 || price>1000) {
			throw exception("This price is invalid");
		 }
		this->price = price;
	}

	//overloading of operator =
	Ticket& operator=(const Ticket& t)
	{
		if (this != &t)
		{
			this->section = t.section;
			this->row = t.row;
			this->seat = t.seat;
			this->price = t.price;
			this->noOfPriceChanges = t.noOfPriceChanges;

			if (this->priceHistory != nullptr)
			{
				delete[] this->priceHistory;
			}

			if (t.priceHistory != nullptr)
			{
				this->priceHistory = new int[t.noOfPriceChanges];
				for (int i = 0; i < this->noOfPriceChanges; i++)
				{
					this->priceHistory[i] = t.priceHistory[i];
				}
			}
		}

		return *this;
	}
};



int main() {

	return 0;
}