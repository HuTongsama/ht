#include<iostream>
#include<cstdlib>
#include<ctime>
#include"queue.h"

using namespace std;

const int MIN_PER_HR = 60;
//is there a new customer?
bool newcustomer(double x)
{
	return (rand()*x / RAND_MAX < 1);
}
struct Info
{
	long turnaways; //turned away by full queue
	long customers; //joined the queue
	long served;	//served during the simulation
	long sum_line;	//cumulative line length
	int wait_time;	//time until autoteller is free
	long line_wait; //cumulative time in line
	double avg_wait;//average wait time
};
void initInfo(Info &i)
{
	i.turnaways = 0;
	i.customers = 0;
	i.served = 0;
	i.sum_line = 0;
	i.wait_time = 0;
	i.line_wait = 0;
	i.avg_wait = 0;
}
void showInfo(const Info &info,long cyclelimit)
{
	cout << "customers accepted: " << info.customers << endl;
	cout << "customers served: " << info.served << endl;
	cout << "\tturnaways: " << info.turnaways << endl;
	cout << "average queue size: ";
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << (double)info.sum_line / cyclelimit << endl;
	cout << "average wait time: "
		<< info.avg_wait << " minutes\n";
}

int main() {
	srand(time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line_1(qs),line_2(qs);//line of ATM1 and ATM2

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	//simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR*hours;
	cout << "Enter the average number of customers per hour:";
	double perhour;//average # of arrival per hour
	cin >> perhour;
	double min_per_cust;//average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;			//new customer data
	Info ATM1_info;		//information of ATM1 simulation
	Info ATM2_info;		//information of ATM2 simulation
	do
	{
		initInfo(ATM1_info);
		initInfo(ATM2_info);
		line_1.clear();
		line_2.clear();
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line_1.isfull()&&line_2.isfull())
					ATM1_info.turnaways++;
				else if (line_1.queuecount()>line_2.queuecount())
				{
					ATM2_info.customers++;
					temp.set(cycle);
					line_2.enqueue(temp);
				}
				else
				{
					ATM1_info.customers++;
					temp.set(cycle);//cycle = time of arrival
					line_1.enqueue(temp);//add newcomer to line
				}
			}
			if (ATM1_info.wait_time <= 0 && !line_1.isempty())
			{
				line_1.dequeue(temp);//attend next customer
				ATM1_info.wait_time = temp.ptime();//for wait_time minutes
				ATM1_info.line_wait += (cycle - temp.when());
				ATM1_info.served++;
			}
			if (ATM2_info.wait_time <= 0 && !line_2.isempty())
			{
				line_2.dequeue(temp);
				ATM2_info.wait_time = temp.ptime();
				ATM2_info.line_wait += (cycle - temp.when());
				ATM2_info.served++;
			}
			if (ATM1_info.wait_time > 0)
				ATM1_info.wait_time--;
			if (ATM2_info.wait_time > 0)
				ATM2_info.wait_time--;
			ATM1_info.sum_line += line_1.queuecount();
			ATM2_info.sum_line += line_1.queuecount();
		}

		if (ATM1_info.customers > 0 || ATM2_info.customers > 0)
		{
			ATM1_info.avg_wait = (double)ATM1_info.line_wait / ATM1_info.served;
			ATM2_info.avg_wait = (double)ATM2_info.line_wait / ATM2_info.served;
			cout << "ATM1:\n";
			showInfo(ATM1_info, cyclelimit);
			cout << "ATM2:\n";
			showInfo(ATM2_info, cyclelimit);
		}
		else
			cout << "No customers!\n";
		if ((ATM1_info.avg_wait+ATM2_info.avg_wait)/2 > 1)
		{
			cout << "average wait time is too long,"
				<< "the average number of customers per hour minus one." << endl;
			perhour--;
			min_per_cust = MIN_PER_HR / perhour;

		}
	} while ((ATM1_info.avg_wait+ATM2_info.avg_wait)/2 > 1);

	cout << "Current average number of customers per hour is: " << perhour << endl;
	cout << "Done!\n";

	system("pause");
}
