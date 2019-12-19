#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include "DynamicArray.h"
#include <iostream>
#include <ctime>


struct some_object {
	int number;
	char letter;
	char* x;

	some_object() : x(new char{ 'x' }) {}
	~some_object()
	{
		delete x;
	}
	some_object(const some_object& n)
	{
		number = n.number;
		letter = n.letter;
		x = new char;
		*x = *n.x;
	}
	some_object& operator=(const some_object& n)
	{
		if (&n == this)
			return *this;
		number = n.number;
		letter = n.letter;
		*x = *n.x;
		return *this;
	}

	bool operator ==(const some_object& value_number) const {
		return (number == value_number.number && letter == value_number.letter);
	}

	bool operator <(const some_object& value_number) const {
		return (this->number < value_number.number);
	}

	bool operator >(const some_object& value_number) const {
		return (this->number > value_number.number);
	}
};

std::ostream& operator<<(std::ostream& out, const some_object& so) {
	return(out << so.number << so.letter);
}


std::ostream& operator<<(std::ostream& out, const std::string& so) {
	return(out << so.c_str() << " ");
}

int main() {

	const int MAX_ORDER = 6;

	DynamicArray<some_object>* dynamic_array = new DynamicArray<some_object>();

	some_object* so = new some_object;

	dynamic_array->array_size = 10;
	dynamic_array->create_array();

	const  int n = pow(10, MAX_ORDER);

	clock_t begin, end;
	double time_spent;
	double max_time_per_element = 0.0;

	for (int i = 0; i < n; i++) {
		so->number = rand() % 1000 + 1;
		so->letter = rand() % ('z' - 'a' + 1) + 'a';

		begin = clock();

		dynamic_array->insert_end(*so);

		end = clock();

		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		if (time_spent > max_time_per_element) {
			max_time_per_element = time_spent;
			std::cout << "Maximum time : " << max_time_per_element << "\nIndex : " << dynamic_array->number_of_nodes - 1 << std::endl;
		}
	}

	clock_t  t2 = clock();

	so->number = rand() % 1000 + 1;
	so->letter = rand() % ('z' - 'a' + 1) + 'a';

	dynamic_array->change_item_by_index(1, *so);
	dynamic_array->return_data(5);

	dynamic_array->display_list(100);

	dynamic_array->remove_all_nodes();

	delete dynamic_array;
	delete so;