#include "emp.h"
using std::cout;
using std::cin;
using std::endl;
using std::getline;

abstr_emp::~abstr_emp() {}

void abstr_emp::ShowAll() const
{
	cout << fname << ',' << lname << ":\n";
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	getline(cin, fname);
	cout << "Enter last name: ";
	getline(cin, lname);
	cout << "Enter job: ";
	getline(cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
	os << e.fname << ',' << e.lname;
	return os;
}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

manager::manager(const manager & m):abstr_emp(m)
{
	inchargeof = m.InChargeOf();
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "In Charge of :" << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	cin.get();
}

fink::fink(const fink & e):abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	getline(cin, reportsto);
}

highfink::highfink(const highfink & h):abstr_emp(h)
{
	InChargeOf() = h.InChargeOf();
	ReportsTo() = h.ReportsTo();
}

void highfink::ShowAll() const
{
	manager::ShowAll();
	cout << "Reportsto: " << ReportsTo() << endl;
}

void highfink::SetAll()
{
	manager::SetAll();
	cout << "Enter reportsto: ";
	getline(cin, ReportsTo());
}
