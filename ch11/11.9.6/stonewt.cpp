#include "stonewt.h"
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = Stonewt::float_pound;
}
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn*Lbs_per_stn + lbs;
	mode = Stonewt::stones;
}
Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	mode = Stonewt::stones;
}
Stonewt::~Stonewt()
{
}
void Stonewt::setMode(Mode m)
{
	mode = m;
}
Stonewt Stonewt::operator+(const Stonewt &s)const
{
	return Stonewt(pounds + s.pounds);
}
Stonewt Stonewt::operator-(const Stonewt & s) const
{
	if (pounds - s.pounds >= 0)
		return Stonewt(pounds - s.pounds);
	else
		return Stonewt();
}
Stonewt Stonewt::operator*(double n) const
{
	if (n >= 0)
		return Stonewt(pounds*n);
	else
		return Stonewt();
}
bool Stonewt::operator>(const Stonewt & s) const
{
	return pounds > s.pounds;
}
bool Stonewt::operator<(const Stonewt & s) const
{
	return pounds < s.pounds;
}
bool Stonewt::operator>=(const Stonewt & s) const
{
	return pounds >= s.pounds;
}
bool Stonewt::operator<=(const Stonewt & s) const
{
	return pounds <= s.pounds;
}
bool Stonewt::operator==(const Stonewt & s) const
{
	return pounds == s.pounds;
}
bool Stonewt::operator!=(const Stonewt & s) const
{
	return pounds != s.pounds;
}
std::ostream &operator<<(std::ostream & os, const Stonewt s)
{
	if (s.mode == Stonewt::stones)
	{
		os << s.stone << " stone, " << s.pds_left << " pounds\n";
	}
	else if (s.mode == Stonewt::int_pound)
	{
		os << int(s.pounds) << " pounds in int\n";
	}
	else
	{
		os << s.pounds << " pounds int float\n";
	}
	return os;
}
