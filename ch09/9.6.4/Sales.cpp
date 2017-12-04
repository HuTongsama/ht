#include "Sales.h"
#include<iostream>
void SALES::setSales(Sales & s, const double ar[], int n)
{
	int count = n <= QUARTERS ? n : QUARTERS;
	if (count > 0)
	{
		s.max = ar[0];
		s.min = ar[0];
		s.average = 0;
		for (int i = 0; i < count; i++)
		{
			s.sales[i] = ar[i];
			if (ar[i] > s.max)
				s.max = ar[i];
			if (ar[i] < s.min)
				s.min = ar[i];
			s.average += ar[i];
		}
		for (int i = count; i < QUARTERS; i++)
			s.sales[i] = 0;
		s.average /= count;
	}
	else
	{
		for (int i = 0; i < QUARTERS; i++)
			s.sales[i] = 0;
		s.average = 0;
		s.max = 0;
		s.min = 0;
	}
}

void SALES::setSales(Sales & s)
{
	std::cout << "Enter sales: ";
	int i = 0;
	while (i<QUARTERS&&std::cin>>s.sales[i])
	{
		if(i<QUARTERS-1)
			std::cout << "Next sales: ";
		i++;
	}
	s.max = s.sales[0];
	s.min = s.sales[0];
	s.average = s.sales[0];
	for (int i = 1; i < QUARTERS; i++)
	{
		if (s.sales[i] > s.max)
			s.max = s.sales[i];
		if (s.sales[i] < s.min)
			s.min = s.sales[i];
		s.average += s.sales[i];
	}
	s.average /= QUARTERS;
}

void SALES::showSales(const Sales & s)
{
	std::cout << "Sales: ";
	for (int i = 0; i < QUARTERS; i++)
		std::cout << s.sales[i] << '\t';
	std::cout <<std:: endl;
	std::cout << "Average: " << s.average << '\n';
	std::cout << "Max: " << s.max << '\n';
	std::cout << "Min: " << s.min << '\n';
}
