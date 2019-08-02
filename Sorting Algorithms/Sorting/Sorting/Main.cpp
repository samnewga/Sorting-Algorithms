#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include "LinkedList.h"

// Function prototypes and their parameters
void insert_sort(LinkedList<int> & List);
void recur_sort(LinkedList<int> & List, Node<int>* prev);
void display_list(LinkedList<int> & List);

// Main function with two command line arguments
int main(int argc, char* argv[]) 
{
	// Creating our linked list
	LinkedList<int> SortLL;

	// If the command line arguments are not return a cout with a error print message saying to insert a file to run the sorting algorithm
	if (argv[1] == NULL || argv[2] == NULL)
	{
		std::cout << "There are not enough arguments. Please enter the file to sort and the number to indicate the sorting algorithm.\n";
	}

	// Else look for when the command line arguments are not null that runs our main functions
	else
	{
		// Labeling our file as infile and pass it in as argv 1
		// Using strings
		// Label our start and end for our clock function
		std::ifstream infile(argv[1]);
		std::string line;
		clock_t start;
		clock_t duration;

		// If the infile is open we run this
		if (infile.is_open())
		{
			// Using stoi to convert the string in the data file to integers, and then close the infile
			while (std::getline(infile, line))
			{
				SortLL.insert(std::stoi(line, nullptr, 10));
			}
			infile.close();

			std::cout << "Sorting the list:\n";

			// If second command line argument value is 1, we run insertion sort algorithm
			if (argv[2] == "1")
			{
				start = clock();
				insert_sort(SortLL);
				duration = clock() - start;
			}
			// If second command line argument value is 2, we run insertion sort algorithm
			else if(argv[2] == "2")
			{
				start = clock();
				recur_sort(SortLL, SortLL.get_tail());
				duration = clock() - start;
			}
			// If second command line argument is not 1 or 2, return error message
			else
			{
				std::cout << "ERROR: Improper command line argument value" << std::endl;
			}

			// Our timing function that uses a float and divides the duration by clocks per second and then displays it
			std::cout << "\nTime it took to sort: " << (float)duration/(CLOCKS_PER_SEC/1000) << " milliseconds" << std::endl;

			// If the sorted linked list is less than or equal to 100 we display it, otherwise we skip the display function
			if (SortLL.get_size() <= 100)
			{
				display_list(SortLL);
			}
		}
		// Else for when the file couldn't be opened
		else
		{
			std::cout << "ERROR: File could not be opened.\n";
		}
	}

	system("pause");
	return 0;
}

// Insertion sorting function
void insert_sort(LinkedList<int> & List)
{
	if (List.get_head() == nullptr)
	{
		return;
	}
	else
	{
		auto current = List.get_head();
		while (current->get_next() != nullptr)
		{
			current = current->get_next();
			auto sorted = current->get_prev();
			int sort_val = current->get_data();
			int temp = 0;

			while (sorted != nullptr && sorted->get_data() > sort_val)
			{
				temp = sorted->get_data();
				sorted->set_data(sort_val);
				sorted->get_next()->set_data(temp);
				sorted = sorted->get_prev();
			}
		}
	}
}

// Recursive sorting function
void recur_sort(LinkedList<int> & List, Node<int>* prev)
{
	if (prev == List.get_head())
	{
		return;
	}
	else
	{
		recur_sort(List, prev->get_prev());

		auto sorted = prev->get_prev();
		int sort_val = prev->get_data();
		int temp = 0;

		while (sorted != nullptr && sorted->get_data() > sort_val)
		{
			temp = sorted->get_data();
			sorted->set_data(sort_val);
			sorted->get_next()->set_data(temp);
			sorted = sorted->get_prev();
		}
	}
}

// Display our linkedlist 
void display_list(LinkedList<int> & List)
{
	auto current = List.get_head();
	std::cout << "List:\n";
	while (current != nullptr)
	{
		std::cout << current->get_data() << std::endl;
		current = current->get_next();
	}
	std::cout << std::endl;
}