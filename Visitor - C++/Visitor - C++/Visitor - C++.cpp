#include <iostream>
using namespace std;

class Zoo;
class Cinema;
class Circus;

class IVisitor {
public:
	virtual void Visit(Zoo& ref) = 0;
	virtual void Visit(Cinema& ref) = 0;
	virtual void Visit(Circus& ref) = 0;
	virtual ~IVisitor() = default;
};

class Place {
public:
	virtual void Accept(IVisitor& v) = 0;
	virtual ~Place() = default;
};

class Zoo : public Place {
public:
	void Accept(IVisitor& v) override {
		v.Visit(*this);
	}
};

class Cinema : public Place {
public:
	void Accept(IVisitor& v) override {
		v.Visit(*this);
	}
};

class Circus : public Place {
public:
	void Accept(IVisitor& v) override {
		v.Visit(*this);
	}
};

class HolidayMaker : public IVisitor {
public:
	string value;
public:
	void Visit(Zoo& ref) override {
		value = "elephant in the zoo";
	}
	void Visit(Cinema& ref) override {
		value = "cinema - Lord of the Rings";
	}
	void Visit(Circus& ref) override {
		cout << "Clown in circus";
	}
};

int main() {
	Zoo zoo;
	Cinema cinema;
	Circus circus;
	Place* places[] = { &zoo, &cinema, &circus };

	for (auto place : places) {
		HolidayMaker visitor;
		place->Accept(visitor);
		cout << visitor.value << "\n";
	}
}