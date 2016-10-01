


//  Name: Christopher Teti                                Z# :23293126
//	Course : Foundations of Computer Science(COP3014)
//	Professor : Dr.Lofton Bullard
//	Due Date 09/12/2016: Due Time 11:59pm:
//									  Total Points : 20

//										  Assignment 2 : call_stats.cpp
 /*Description : 
 in this program we declared a new class called call_record. from there we pointed customer_record to call_record to retriev
 the infomration declared inside the class. We used customer_record.the variables we needed to perform the actions in each function.
we had three funtions for input, process and output.
				*/
				
				



//Include the following

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

/*********************************************************
//Following is the declaration of a call record
**********************************************************/ 
class call_record
{
	public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};


//Prototypes for your functions: Input, Output, and Process will go here

void Input(ifstream &, call_record &);
void Output(const call_record &);
void Process(const call_record &);

//Function Implementations will go here

///*************************************************************************************
//Name:  Input
//Precondition: State what is true before the function is called.
// Example: the varialbes (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the varaibles (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, relays, and call_length) from the user and store in call record.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void Input(ifstream & in, call_record & customer_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{

	in >> customer_record.cell_number;
	in >> customer_record.relays;
	in >> customer_record.call_length;
}

///*************************************************************************************
//Name:  Output
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************


void Output(const call_record & customer_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/


	cout << right << setw(5) << customer_record.cell_number << "   ";
	cout << right << setw(5) << customer_record.relays << "   ";
	cout << right << setw(5) << customer_record.call_length << "   ";
	cout << right << setw(5) << customer_record.net_cost << "   ";
	cout << right << setw(5) << customer_record.tax_rate << "   ";
	cout << right << setw(5) << customer_record.call_tax << "   ";
	cout << right << setw(5) << customer_record.total_cost << endl;


}

///*************************************************************************************
//Name:  Process
//Precondition: The state what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does (purpose).
//*************************************************************************************

//Note: there is one 1 input/output parameter
void Process(call_record & customer_record)
{
	//this is an example of a stub
	//Step 1: put your code here to determine the net_cost using the formula: 




	if ((customer_record.relays >= 0) && (customer_record.relays <= 5)) {
		customer_record.tax_rate = 0.01;
	}
	else if ((customer_record.relays >= 6) && (customer_record.relays <= 11)) {
		customer_record.tax_rate = 0.03;
	}

	else if ((customer_record.relays >= 12) && (customer_record.relays <= 20)) {
		customer_record.tax_rate = .05;
	}

	else if ((customer_record.relays >= 21) && (customer_record.relays <= 50)) {
		customer_record.tax_rate = .08;
	}
	else {
		customer_record.tax_rate = 0.12;
	}
	customer_record.net_cost = customer_record.relays / 50.0 * .40 * customer_record.call_length;

	customer_record.call_tax = customer_record.net_cost*customer_record.tax_rate;


	customer_record.total_cost = customer_record.net_cost + customer_record.call_tax;

}

//Here is your driver to test the program
int main()
{

	call_record customer_record;

	ifstream in;    //declaring an input file stream
	in.open("call_data.txt");

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof())
		{
			Input(in, customer_record);
			Process(customer_record);
			Output(customer_record);
		}
	}

	in.close();

	return 0;
}

