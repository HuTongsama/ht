#pragma once
#include<iostream>
namespace SALES
{
	class Sales
	{
	public:
		//copies the lesser of 4 or n items from the array ar
		//to the member sales[] of *this and computes and stores
		//the average ,maximum,and minimum values of the entered items;
		//remaining elements of sales ,if any,set to 0
		Sales(const double ar[],int n);
		//gathers sales for 4 quarters interactively, stores them
		//in the sales[],and computes and stores the average,maximum
		//,minimum values
		Sales();
		~Sales();
		void showSales()const;

	private:
		static const int QUARTERS = 4;
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	Sales::Sales()
	{
		std::cout << "Enter sales: ";
		std::cin >> sales[0];
		average = sales[0];
		max = sales[0];
		min = sales[0];

		for (int i = 1; i < QUARTERS; i++)
		{
			std::cout << "Next sales: ";
			std::cin >> sales[i];
			average += sales[i];
			if (max < sales[i])
				max = sales[i];
			if (min > sales[i])
				min = sales[i];
		}
		average /= QUARTERS;
	}

	inline Sales::Sales(const double ar[], int n)
	{
		int len = n < QUARTERS ? n : QUARTERS;
		if (len > 0)
		{
			max = ar[0];
			min = ar[0];
			average = 0;
			for (int i = 0; i < len; i++)
			{
				sales[i] = ar[i];
				average += ar[i];
				if (max < ar[i])
					max = ar[i];
				if (min > ar[i])
					min = ar[i];
			}
			average /= len;
			for (int j = len; j < QUARTERS; j++)
				sales[j] = 0;
		}
		else
			std::cout << "Wrong input!\n";
	}

	Sales::~Sales()
	{
	}
	inline void Sales::showSales() const
	{
		std::cout << "Sales: ";
		for (int i = 0; i < QUARTERS; i++)
			std::cout << sales[i] << '\t';
		std::cout << std::endl;
		std::cout << "Average: " << average << '\n';
		std::cout << "Maximum: " << max << '\n';
		std::cout << "Minimum: " << min << '\n';
	}
}
