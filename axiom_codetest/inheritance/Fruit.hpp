//Fruit.hpp
#include <string>

using namespace std;

class Fruit
{
    public:
    //constructor/destructor
        Fruit();
        ~Fruit();

        void Identify();
        void SetID(string idx);
		string GetID();

    private:
        string id;

};

class Banana : public Fruit
{
    public:
    //constructor/destructor
        Banana();
        ~Banana();
};

class Tangerine : public Fruit
{
    public:
    //constructor/destructor
        Tangerine();
        ~Tangerine();
};

class Pear : public Fruit
{
    public:
    //constructor/destructor
        Pear();
        ~Pear();
};


