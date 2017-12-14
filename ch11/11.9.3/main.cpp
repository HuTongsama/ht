#include<iostream>
#include<cstdlib>
#include<ctime>
#include"vect.h"

int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	double target;
	double dstep;
	unsigned int N;
	cout << "Enter the N: ";
	if (cin >> N)
	{
		double *pd = new double[N];
		int i = 0;
		cout << "Enter target distance (q to quit): ";
		while (i<N&&cin >> target)
		{
			unsigned long steps = 0;
			cout << "Enter step length: ";
			if (!(cin >> dstep))
				break;
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}
			pd[i] = steps;
			result.reset(0.0, 0.0);
			i++;
			if(i<N)
				cout<< "Enter target distance (q to quit): ";
		}
		double Max = pd[0];
		double Min = pd[0];
		double sum = pd[0];
		for (int i = 1; i < N; i++)
		{
			if (pd[i] > Max)
				Max = pd[i];
			if (pd[i] < Min)
				Min = pd[i];
			sum += pd[i];
		}
		cout << "Max Steps: " << Max << '\n';
		cout << "Min Steps: " << Min << '\n';
		cout << "Average Steps: " << sum / N << endl;
	}
	system("pause");
}
