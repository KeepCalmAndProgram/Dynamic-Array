#ifndef  DynamicArray_h
#define  DynamicArray_h

template<class T>
class DynamicArray {

public:

	T* arry;
	T* array_second;

	int array_size;
	int magnification_of_the_array;
	int number_of_nodes;

	DynamicArray() {

	}
	~DynamicArray() {

	}

	void create_array();
	void magnification();

	void insert_end(const T& data);

	void change_item_by_index(int index, const T& data);
	void return_data(int index);
	void display_list(int number_of_nodes);

	void remove_all_nodes();

private:

};



template<class T>
inline void DynamicArray<T>::create_array()
{
	arry = new T[this->array_size];
	number_of_nodes = 0;
}

template<class T>
inline void DynamicArray<T>::magnification()
{
	long int magnificat = 0;
	magnificat = this->array_size * this->magnification_of_the_array;
	array_second = new T[magnificat];

	for (int i = 0; i < array_size / 2; i++) {
		array_second[i] = arry[i];
	}
	delete[] arry;
	arry = array_second;

}

template<class T>
inline void DynamicArray<T>::insert_end(const T& data)
{
	this->number_of_nodes++;

	if (this->array_size >= this->number_of_nodes) {
		arry[number_of_nodes - 1] = data;
	}
	else {
		magnification_of_the_array = 2;
		array_size = this->array_size * this->magnification_of_the_array;
		if (array_size == 0)
			array_size = 1;
		magnification();
		arry[number_of_nodes - 1] = data;
	}
}

template<class T>
void DynamicArray<T>::remove_all_nodes() {

	delete[] arry;
}

template<class T>
inline void DynamicArray<T>::change_item_by_index(int index, const T& data) {

	if (this->number_of_nodes < index)
	{
		std::cout << "index out of range..." << std::endl;
		return;
	}

	for (int i = 0; i < this->number_of_nodes; i++)
	{
		if (i == index)
		{
			std::cout << "\nElement " << arry[i] << " Found. Under the index : " << index << std::endl;
			arry[i] = data;
			std::cout << "Exchange for : " << data << "Under the index : " << index << std::endl;
			break;
		}
	}
}
template<class T>
inline void DynamicArray<T>::return_data(int index) {

	if (this->number_of_nodes < index)
	{
		std::cout << "index out of range..." << std::endl;
		return;
	}

	for (int i = 0; i < this->number_of_nodes; i++)
	{
		if (i == index)
		{
			std::cout << "\nElement " << arry[i] << " Found. Under the index : " << index << std::endl;
			break;
		}
	}
}
template<class T>
inline void DynamicArray<T>::display_list(int number_of_nodes) {

	if (number_of_nodes < this->number_of_nodes) {

		std::cout << "\nNumber of nodes : " << this->number_of_nodes << std::endl;

		for (int i = 0; i < number_of_nodes; i++) {
			std::cout << "Element [ " << i << " ] : " << arry[i] << std::endl;
		}
	}
	else {
		std::cout << "\nNumber of nodes : " << this->number_of_nodes << std::endl;

		for (int i = 0; i < this->number_of_nodes; i++) {
			std::cout << "Element [ " << i << " ] : " << arry[i] << std::endl;
		}
	}
	std::cout << "Array size : " << this->number_of_nodes << std::endl;
	std::cout << "\n";

}
#endif