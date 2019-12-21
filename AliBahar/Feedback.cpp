#include "Feedback.h"
#include "Product.h"
#include "Vendor.h"
#include "Costumer.h"

feedback::feedback(const char* newDate, const char* newDescription, const Costumer& newCtm, const vendor& newVen)
	: costumerP(&newCtm), vendorP(&newVen)
{
	cout << "In Feedback's c'tor for " << newVen.getUserName() << endl;

	delete[] date;
	date = new char[strlen(newDate) + 1];
	strcpy(date, newDate);

	setDescription(newDescription);
}

feedback::~feedback()
{
	cout << "In Feedback's d'tor for " << vendorP->getUserName() << endl;

	delete[] date;
	delete[] description;
}

const Costumer* feedback::getCostumer() const
{
	return costumerP;
}

const vendor* feedback::getVendor() const
{
	return vendorP;
}

char* feedback::getDate() const
{
	return date;
}

void feedback::setDescription(const char* newDcp)
{
	delete[] description;
	description = new char[strlen(newDcp) + 1];
	strcpy(description, newDcp);
}

char* feedback::getDescription() const
{
	return description;
}