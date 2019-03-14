#include <iostream>
#include <limits>
#include <string>

using namespace std;

void input(double&, string = "");
void inputFood(double&);
string numberToWeekday(int);
double avgValue7by3(double[7][3]);
double min7by3(double[7][3]);
double max7by3(double[7][3]);
string plural(double);

int main()
{
	double foodValues[7][3]; // foodvalues[day][monkey]
	int dayInd, monkeyInd;
	for (dayInd = 0; dayInd < 7; dayInd++)
	{
		cout << "On " << numberToWeekday(dayInd) 
		<< ", how many pounds of food was consumed by:" << endl;
		for (monkeyInd = 0; monkeyInd < 3; monkeyInd++)
		{
			cout << "\tMonkey #" << monkeyInd + 1 << ":";
			inputFood(foodValues[dayInd][monkeyInd]);
		}
		cout << endl;
	}
	
	double average = avgValue7by3(foodValues);
	cout << "The average amount of food eaten per day per monkey was "
	<< average << "lb(s)" << endl;
	
	double minimum;
	minimum = min7by3(foodValues);
	cout << "The minimum amount of food eaten by single monkey during"
	<< " the entire week was " << minimum  << "lb(s)" << endl; 
	
	double maximum;
	maximum = max7by3(foodValues);
	cout << "The maximum amount of food eaten by single monkey during"
	<< " the entire week was " << maximum  << "lb(s)" << endl; 
	
	return 0;
}

void input(double& inp, string prompt)
{
	cout << prompt << " ";
	while (!(cin >> inp))
	{
		cout << "Whoops, please try again: ";
		cin.clear(); 
		cin.ignore(10000, '\n'); // clears any unread input
	}
	cin.ignore(10000, '\n');
}

void inputFood(double& pounds)
{
	input(pounds);
	while (pounds < 0)
	{
		input(pounds, "invalid (negative) food quantity -- re-enter");
	}
}

string numberToWeekday(int num)
{
	static string weekArray[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", 
	"Thursday", "Friday", "Saturday"};
	if (num < 0 or num > 6) cout << endl << "Unexpected behavior encountered"
	<< "in numberToWeekday function. num: " << num << endl;
	return weekArray[num];
}

double avgValue7by3(double array[7][3])
{
	double avg;
	for (int rowInd = 0; rowInd < 7; rowInd++)
		for (int colInd = 0; colInd < 3; colInd++)
			avg += array[rowInd][colInd] / 21;
	return avg;
}

double min7by3(double array[7][3])
{
	double min = numeric_limits<double>::max();
	for (int rowInd = 0; rowInd < 7; rowInd++)
		for (int colInd = 0; colInd < 3; colInd++)
			if (array[rowInd][colInd] < min)
				min = array[rowInd][colInd];
	return min;
}

double max7by3(double array[7][3])
{
	double max = -numeric_limits<double>::max();
	for (int rowInd = 0; rowInd < 7; rowInd++)
		for (int colInd = 0; colInd < 3; colInd++)
			if (array[rowInd][colInd] > max)
				max = array[rowInd][colInd];
	return max;
}

