#include "Fruit.hpp"
#include <string>
#include <iostream>

using namespace std;

Fruit::Fruit()
{
    this->id="Fruit";
}

Fruit::~Fruit()
{
    this->id="";
    if(this)
        delete this;
}

void Fruit::Identify()
{
    cout << "I am a " << Fruit::GetID() << endl;
}

void Fruit::SetID(string idx)
{
    this->id = idx;
}

string Fruit::GetID()
{
	return this->id;
}

Banana::Banana()
{
    Fruit::SetID("Banana");
}


Banana::~Banana()
{
    Fruit::SetID("");
    if(this)
        delete this;
}

Tangerine::Tangerine()
{
    Fruit::SetID("Tangerine");
}

Tangerine::~Tangerine()
{
    Fruit::SetID("");
    if(this)
        delete this;
}

Pear::Pear()
{
    Fruit::SetID("Pear");
}

Pear::~Pear()
{
    Fruit::SetID("");
    if(this)
        delete this;
}


