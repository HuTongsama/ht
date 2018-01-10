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
	Queue line(qs);

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
	Info info;			//information of simulation

	do
	{
		initInfo(info);
		line.clear();
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust))
			{
				if (line.isfull())
					info.turnaways++;
				else
				{
					info.customers++;
					temp.set(cycle);//cycle = time of arrival
					line.enqueue(temp);//add newcomer to line
				}
			}
			if (info.wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp);//attend next customer
				info.wait_time = temp.ptime();//for wait_time minutes
				info.line_wait += (cycle - temp.when());
				info.served++;
			}
			if (info.wait_time > 0)
				info.wait_time--;
			info.sum_line += line.queuecount();
		}

		if (info.customers > 0)
		{
			info.avg_wait = (double)info.line_wait / info.served;
			showInfo(info, cyclelimit);
		}
		else
			cout << "No customers!\n";
		if (info.avg_wait > 1)
		{
			cout << "average wait time is too long,"
				<< "the average number of customers per hour minus one." << endl;
			perhour--;
			min_per_cust = MIN_PER_HR / perhour;

		}
	} while (info.avg_wait > 1);

	cout << "Current average number of customers per hour is: " << perhour << endl;
	cout << "Done!\n";

	system("pause");
}
