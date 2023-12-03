#define _CRT_SECURE_NO_WARNINGS
#include<string>;
#include<iostream>;

using namespace std;

//enum eventType = {THEATER, MOVIE, FOOTBALL};

class User
{
	char* name;
	string phoneNumber;
	int age;
	string* friends;
	int noFriends;

//2 constructors with parameters

	User(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	User(const char* name, string phoneNumber, int age, string* friends, int noFriends) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->phoneNumber = phoneNumber;
		this->age = age;
		this->noFriends = noFriends;
		this->friends = new string[noFriends];
		for (int i = 0; i < noFriends; i++) {
			this->friends[i] = friends[i];
		}
	}

//copy constructor

	User(const User& u) {
		this->name = new char[strlen(u.name) + 1];
		strcpy(this->name, u.name);
		this->phoneNumber = u.phoneNumber;
		this->age = u.age;
		this->noFriends = u.noFriends;
		this->friends = new string[u.noFriends];
		for (int i = 0; i < u.noFriends; i++) {
			this->friends[i] = u.friends[i];
		}
	}

//destructor

	~User() {
		if (this->name != nullptr) {
			delete[] this->name;
			this->name = nullptr;
		}
		else {
			this->name = nullptr;
		}
		if (this->friends != nullptr) {
			delete[] this->friends;
			this->friends = nullptr;
		}
		else {
			this->friends = nullptr;
		}
	}

//setters

	void setName(char* name) {
		if (this->name != nullptr) {
			delete[] this->name;
		}

		if (name != nullptr) {
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
	}

	void setPhoneNumber(string phoneNumber) {
		this->phoneNumber = phoneNumber;
	}

	void setAge(int age) {
		this->age = age;
	}

	void setFriendsAndNr(string* friends, int newNrFriends) {
		if (this->friends != nullptr) {
			delete[] this->friends;
		}

		if (friends != nullptr) {
			this->friends = new string[newNrFriends];
			for (int i = 0; i < newNrFriends; i++) {
				this->friends[i] = friends[i];
			}
		}
		else {
			this->friends = nullptr;
		}
		this->noFriends = newNrFriends;
	}

	void setNrFriends(int newNrFriends) {
		this->noFriends = newNrFriends;
	}

//getters


	char* getName() {
		return this->name;
	}

	string getPhoneNumber() {
		return this->phoneNumber;
	}

	int getAge() {
		return this->age;
	}

	string* getFriends() {
		string* copy;
		copy = new string[noFriends];
		for (int i = 0; i < noFriends; i++) {
			copy[i] = this->friends[i];
		}
		return copy;
	}

	int getNoFriends() {
		return this->noFriends;
	}


//2 generic methods

	void showUser() {
		cout << this->name << " " << this->age << " " << this->age << "\n";
	}

	void addFriend(string newFriend) {
		string* copyFriends;
		if (newFriend.length()>3) {
			copyFriends = new string[noFriends + 1];
			for (int i = 0; i < noFriends; i++) {
				copyFriends[i] = this->friends[i];
			}

			copyFriends[noFriends] = newFriend;
			noFriends += 1;

			delete[] this->friends;
			this->friends = new string[noFriends];
			for (int i = 0; i < noFriends; i++) {
				this->friends[i] = copyFriends[i];
			}

			delete[] copyFriends;
		}
		else {
			throw exception("Name of new friend is invalid!");
		}
	}


//operator=

	User& operator=(const User& u) {
		if (this != &u) {
			this->name = new char[strlen(u.name) + 1];
			strcpy(this->name, u.name);
			this->phoneNumber = u.phoneNumber;
			this->age = u.age;
			this->noFriends = u.noFriends;
			this->friends = new string[u.noFriends];
			for (int i = 0; i < u.noFriends; i++) {
				this->friends[i] = u.friends[i];
			}
		}

		return *this;
	}


//>>
	friend istream& operator>>(istream& in, User& u);

//<<
	friend ostream& operator<<(ostream& out, User u);

//operator[], cast operator, operator!, operator==

	string& operator[](int index) {
		if (friends != nullptr && index > 0 && index < noFriends) {
			return friends[index];
		}
	}

	bool operator!() {
		return this->noFriends < 0;
	}

	operator int() {
		return this->age;
	}

	bool operator==(const User& u) {
		return this->age == u.age;
	}

	bool operator>=(const User& u) {
		return this->age >= u.age;
	}

};

ostream& operator<<(ostream& out, User u) {
	out << u.name << " " << u.age << " " << u.phoneNumber << " " << u.noFriends << "\n";
	return out;
}

istream& operator>>(istream& in, User& u) {
	cout << "User name: ";
	char* buffer=nullptr;
	in >> buffer;
	u.setName(buffer);

	cout << "Phone number: ";
	string buffer1 = "";
	in >> buffer1;
	u.setPhoneNumber(buffer1);

	cout << "Age: ";
	int iBuffer = 0;
	in >> iBuffer;
	u.setAge(iBuffer);

	cout << "Number of friends you are coming with: ";
	iBuffer = 0;
	in >> iBuffer;
	u.setNrFriends(iBuffer);

	return in;
}

enum Category { Movie, Theater, Football, Basketball};

class Event
{
	string name;
	string date;
	Category category;
	string organizers[10];
	string* sponsors;
	int noOfSponsors;
	static int noOfEvents;
	int ticketsLeft;


public:

	//2 constructors with parameters
	Event(string name, string date, Category category, int tickets) {
		this->name = name;
		this->date = date;
		this->category = category; 
		this->ticketsLeft = tickets;
	}

	Event(string organizers, string* sponsors, int noOfSponsors) {
		for (int i = 0; i < 10; i++) {
			this->organizers[i] = organizers[i];
		}

		this->sponsors = new string[noOfSponsors];
		for (int i = 0; i < noOfSponsors; i++) {
			this->sponsors[i] = sponsors[i];
		}

		this->noOfSponsors = noOfSponsors;
	}

	//copy constructor

	Event(Event& e) {
		this->name = e.name;
		this->date = e.date;
		this->category = e.category;
		for (int i = 0; i < 10; i++) {
			this->organizers[i] = e.organizers[i];
		}

		this->sponsors = new string[e.noOfSponsors];
		for (int i = 0; i < e.noOfSponsors; i++) {
			this->sponsors[i] = e.sponsors[i];
		}

		this->noOfSponsors = e.noOfSponsors;
		this->ticketsLeft = e.ticketsLeft;
	}

	//destructor

	~Event() {
		if (this->sponsors != nullptr) {
			delete[] this->sponsors;
		}
		if (this->organizers != nullptr) {
			delete[] this->organizers;
		}
	}

	//setters

	void setName(string name) {
		if (name.length() < 5 || name.length()>40) {
			throw exception("Name invalid!");
		} else this->name = name;
	}

	void setDate(string date) {
		this->date = date;
	}

	void setCategory(Category category) {
		this->category = category;
	}

	void setSponsors(string* sponsors) {
		if (this->sponsors != nullptr) {
			delete[]this->sponsors;
		}
		if (sponsors != nullptr) {
			this->sponsors = new string[noOfSponsors];
			for (int i = 0; i < noOfSponsors; i++) {
				this->sponsors[i] = sponsors[i];
			}
		}
		else {
			this->sponsors = nullptr;
		}
	}

	void setNoOfSponsors(int noOfSponsors) {
		this->noOfSponsors = noOfSponsors;
	}

	void setTicketsLeft(int ticketsLeft) {
		this->ticketsLeft = ticketsLeft;
	}

	//getters
	string getName() {
		return this->name;
	}
	
	string getDate() {
		return this->date;
	}

	Category getCategory() {
		return this->category;
	}

	string* getOrganizers() {
		string copy[10];
		for (int i = 0; i < 10; i++) {
			copy[i] = this->organizers[i];
		}
		return copy;
	}

	int getNoOfSponsors() {
		return this->noOfSponsors;
	}

	string* getSponsors() {
		string* copy;
		copy = new string[this->noOfSponsors];
		for (int i = 0; i < noOfSponsors; i++) {
			copy[i] = this->sponsors[i];
		} 
		return copy;
	}

	int getTicketsLeft() {
		return this->ticketsLeft;
	}

	//2 generic methods

	void showEvent() {
		cout << this->name << " " << this->date << " " << this->category << "\n";
	}

	void showTicketsLeft() {
		cout<<this->name<<" "<<this->ticketsLeft<<"\n";
	}
	//operator=

	Event& operator=(const Event& e) {
		if (this != &e) {
			this->name = e.name;
			this->date = e.date;
			this->category = e.category;
			for (int i = 0; i < 10; i++) {
				this->organizers[i] = e.organizers[i];
			}

			this->sponsors = new string[e.noOfSponsors];
			for (int i = 0; i < e.noOfSponsors; i++) {
				this->sponsors[i] = e.sponsors[i];
			}

			this->noOfSponsors = e.noOfSponsors;
			this->ticketsLeft = e.ticketsLeft;
		}
	}

	//>>
	friend istream& operator>>(istream& in, Event e);

	//<<
	friend ostream& operator<<(ostream& out, Event e);

	//operator[], cast operator, operator!, operator==

	string& operator[](int index) {
		if (sponsors != nullptr && index > 0 && index < noOfSponsors) {
			return sponsors[index];
		}
	}

	bool operator!() {
		return this->ticketsLeft<100;
	}

	operator int() {
		return this->ticketsLeft;
	}

	bool operator==(const Event& e) {
		return this->name == e.name;
	}

	bool operator>=(const Event& e) {
		return this->noOfSponsors >= e.noOfSponsors;
	}
};

ostream& operator<<(ostream& out, Event e) {
	out << "NAME: " << e.name << "\nDATE: " << e.date;
	return out;
}

istream& operator>>(istream& in, Event& e) {
	cout << "Event name: ";
	string buffer;
	in >> buffer;
	e.setName(buffer);

	cout << "Event date: ";
	string buffer1;
	in >> buffer1;
	e.setDate(buffer1);

	return in;
}

int Event::noOfEvents = 0;


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

		this->price = 0;
		this->noOfPriceChanges = 0;
		this->priceHistory = nullptr;

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

		this->row = 0;
		this->seat = 0;

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

	//a method that prints the ticket

	void showTicket() {
		cout << "Ticket " << this->id << " for the section " << this->section <<" , row " << this->row <<" and seat "<<this->seat<<"\n";
	}

	//a method that modifies the price of the ticket
	void changePrice(int newPrice) {
		cout << "Old ticket price is " << this->price << "\n";

		this->price = newPrice;

		cout << "New ticket price is " << this->price << "\n";
	}

	//Getters

	string getSection() {
		return this->section;
	}

	int getId() {
		return this->id;
	}

	int getRow() {
		return this->row;
	}

	int getSeat() {
		return this->seat;
	}

	int getPrice() {
		return this->price;
	}

	int getPriceChanges() {
		return this->noOfPriceChanges;
	}

	int* getPriceHistory() {
		int* copy;
		if (this->priceHistory != nullptr) {
			copy = new int[this->noOfPriceChanges];
			for (int i = 0; i < this->noOfPriceChanges; i++) {
				copy[i] = this->priceHistory[i];
			}
		}
		else {
			copy = nullptr;
		}

		return copy;
	}


	//Setters

	void setSection(string section) {
		if (section != "Court 1" || section != "Court 2") {
			throw exception("This is not an available section!");
		}
		this->section = section;
	}

	void setRow(int row) {
		if (row <1 || row>20){
			throw exception("This row does not exist!");
		}
		this->row = row;
	}

	void setSeat(int seat) {
		if (seat <1|| seat>50) {
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

	void setNoPriceChanges(int priceChanges) {
		if (priceChanges < 0) {
			throw exception("This number of price changes is invalid!");
		}
		this->noOfPriceChanges = priceChanges;
	}

	void setPriceHistory(int* prices) {
		if (this->priceHistory != nullptr) {
			delete[] this->priceHistory;
		}

		if (prices != nullptr) {
			this->priceHistory = new int[this->noOfPriceChanges];
			for (int i = 0; i < this->noOfPriceChanges; i++) {
				this->priceHistory[i] = prices[i];
			}
		}
		else {
			this->priceHistory = nullptr;
		}
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

	friend ostream& operator<<(ostream& out, Ticket t);
	friend istream& operator>>(istream& in, Ticket t);

	//operator[], cast operator, operator!, operator==

	int& operator[](int index) {
		if (priceHistory != nullptr && index > 0 && index < noOfPriceChanges) {
			return priceHistory[index];
		}
	}

	bool operator!() {
		return this->price < 350;
	}

	operator float() {
		float averagePrice=0;
		float sum = 0;

		for (int i = 0; i < noOfPriceChanges; i++) {
			sum += priceHistory[i];
		}

		averagePrice = sum / noOfPriceChanges;

		return averagePrice;
	}

	bool operator==(const Ticket& t) {
		return this->price == t.price;
	}

	bool operator >=(const Ticket& t) {
		return this->price >= t.price;
	}
};

int Ticket::noOfTickets=0;

ostream& operator<<(ostream& out, Ticket t) {
	out <<"ID: " << t.id << "\nPRICE: " << t.price << "\nSECTION: " << t.section << "\nROW: " << t.row << "\nSEAT: " << t.seat << "\n";
	return out;
};

istream& operator>>(istream& in, Ticket& t) {
	cout << "Ticket price: ";
	int iBuffer;
	in >> iBuffer;
	t.setPrice(iBuffer);

	string sBuffer;
	cout << "Ticket section: ";
	in >> sBuffer;
	t.setSection(sBuffer);

	iBuffer = 0;
	cout << "Ticket row: ";
	in >> iBuffer;
	t.setRow(iBuffer);

	iBuffer = 0;
	cout << "Ticket seat: ";
	in >> iBuffer;
	t.setSeat(iBuffer);

	return in;
};

int main() {
	cout << "Constructor1 with some parameters-----------\n";
	Ticket t1(3,"Court 1", 3, 7);
	cout << t1;
	Ticket t2;
	t2 = t1;
	t1.showTicket();
	int i=t1.getPrice();
	cout << i<<"\n";
	t1.setPrice(450);
	i = t1.getPrice();
	cout << i<<"\n";
	t1.changePrice(600);

	cout << "\n--------------------------------------------\n";

	return 0;
}