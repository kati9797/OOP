#include "CarPart.h"

CarPart::CarPart()
{
	id = "Unknown";
	name = "Unknown";
	description = "Unknown";
}

CarPart::CarPart(const MyString& newId, const MyString& newName, const MyString& newDescription)
{
	setId(newId);
	setName(newName);
	setDescription(newDescription);
}

void CarPart::setId(const MyString& newId)
{
	id = newId;
}

void CarPart::setName(const MyString& newName)
{
	name = newName;
}

void CarPart::setDescription(const MyString& newDescription)
{
	description = newDescription;
}

const MyString& CarPart::getId() const
{
	return id;
}

const MyString& CarPart::getName() const
{
	return name;
}

const MyString& CarPart::getDescription() const
{
	return description;
}
