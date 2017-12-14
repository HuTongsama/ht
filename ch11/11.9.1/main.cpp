#include<iostream>
#include<cstdlib>//rand(),srand() prototypes
#include<ctime>//time() prototype
#include"vect.h"

int main() {
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	ofstream File;
	double distance, stepSize;
	double direction;
	Vector result(0.0, 0.0);
	Vector step;
	unsigned long steps = 0;
	File.open("randWalk.txt");
	if (File.is_open())
	{
		cout << "Enter the distance: ";
		cin >> distance;
		cout << "Enter the size of step: ";
		cin >> stepSize;
		if (distance > 0 && stepSize > 0)
		{
			File << "Target Distance: " << distance << ',';
			File << " Step Size: " << stepSize << endl;

			cout <<steps<<": "<< result << endl;
			File <<steps<<": "<<result << endl;
			while (result.magval() < distance)
			{
				direction = rand() % 360;
				step.reset(stepSize, direction, Vector::POL);
				result = result + step;
				steps++;
				cout << steps << ": " << result << endl;
				File << steps << ": " << result << endl;
			}
			cout << "After " << steps << " the subject has the following location:\n";
			File << "After " << steps << " the subject has the following location:\n";
			cout << result << '\n' << "or\n";
			File << result << '\n' << "or\n";
			result.polar_mode();
			cout << result << endl;
			File << result << endl;
			cout << "Average outward distance per step = " << result.magval() / steps << endl;
			File << "Average outward distance per step = " << result.magval() / steps << endl;
		}
		else
			cout << "Wrong input!\n";
	}
	else
		cout << "Fail to open file!\n";
	system("pause");
}
