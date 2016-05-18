#pragma once
class Grand_Entier
{
private:
	long value;

public:
	Grand_Entier();
	Grand_Entier(long value);

	long get_value();
	Grand_Entier& operator+(Grand_Entier &other_grand_entier);
	Grand_Entier& operator*(Grand_Entier &other_grand_entier);
	Grand_Entier& operator-(Grand_Entier &other_grand_entier);
	Grand_Entier& operator/(Grand_Entier &other_grand_entier);

	~Grand_Entier();
};

