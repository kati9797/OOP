#pragma once
#include "MyString.h"

class CarPart
{
private:
	MyString id;
	MyString name;
	MyString description;
public:
	CarPart();
	CarPart(const MyString&, const MyString&, const MyString&);

	void setId(const MyString&);
	void setName(const MyString&);
	void setDescription(const MyString&);
	const MyString& getId() const;
	const MyString& getName() const;
	const MyString& getDescription() const;
};
