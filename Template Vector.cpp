#include <iostream>
#include <cassert>
using namespace std;




template <class T>
class Vector {
private:
	T* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 16;
public:
	Vector() {
		_size = 0;
		_capacity = 16;
		_array = new T[_capacity]{};
	}

	Vector(size_t capacity)
	{
		_size = 0;
		_capacity = capacity;
		_array = new T[_capacity]{};
	}
	Vector(T* array, size_t size, size_t capacity) :Vector(capacity) {
		if (size <= capacity)
		{
			for (size_t i = 0; i < size; i++)
				_array[i] = array[i];
			_size = size;
		}
	}


	T* getData() const { return _array; }
	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }

	int& operator[](size_t index) {
		if (index < _size)
			return _array[index];

		else
			assert(!"Index out of range.");
	}

	void set_size(size_t size) {
		this->_size = size;
	}
	void set_capacity(size_t capacity) {
		this->_capacity = capacity;
	}
	void set_arr(T* arr, size_t size) {
		while (_capacity <= size) {
			_capacity *= 2;
		}
		_array = new T[size]{};
		for (size_t i = 0; i < size; i++)
		{
			_array[i] = arr[i];
		}
	}


	Vector& push_back(const T value) {
		if (_array == NULL)
			_array = new T[_size]{};



		_size++;
		if (_size == _capacity)
			_capacity *= 2;



		_array[_size - 1] = value;
		return *this;





	}
	Vector& push_front(const T value) {
		if (_array == NULL)
			_array = new T[_size]{};



		_size++;
		if (_size == _capacity)
			_capacity *= 2;



		for (size_t i = _size; i > 0; i--)
			_array[i] = _array[i - 1];



		_array[0] = value;





		return *this;
	}
	Vector& pop_back() {
		if (_size > 0) {
			_size--;
			_capacity = 16;
			if (_size >= _capacity)
				_capacity *= 2;
			_array[_size] = 0;
			return *this;
		}
		else
			assert(!"Index out of range!");
	}
	Vector& pop_front() {
		if (_size > 0) {
			_size--;
			_capacity = 16;
			if (_size >= _capacity)
				_capacity *= 2;




			for (size_t i = 0; i < _size; i++)
			{
				_array[i] = _array[i + 1];
			}



			return *this;
		}
		else
			assert(!"Index out of range!");
	}


	void delete_by_index(const size_t index) {
		_size--;
		_capacity = 16;
		if (_size >= _capacity)
			_capacity *= 2;



		for (size_t i = 0; i < index; i++)
			_array[i] = _array[i];



		for (size_t i = index; i < _size; i++)
			_array[i] = _array[i + 1];
	}
	size_t find(const T element) {
		for (size_t i = 0; i < _size; i++)
		{
			if (_array[i] == element)
				return i;
		}
		return -1;
	}
	size_t rfind(const T element) {



		for (size_t i = _size - 1; i > 0; i--)
		{
			if (_array[i] == element)
				return i;
		}
		return -1;
	}
	void sort(bool reverse = false) {



		for (size_t i = 0; i < _size; i++)
		{
			for (size_t j = i + 1; j < _size; j++)
			{
				if ((_array[i] > _array[j]) == reverse)
				{
					T temp = _array[i];
					_array[i] = _array[j];
					_array[j] = temp;
				}
			}
		}



	}
	void insert_by_index(const size_t index, const T element) {
		_size++;
		_capacity = 16;
		if (_size >= _capacity)
			_capacity *= 2;



		T* cpy = new T[_capacity]{};



		for (size_t i = 0; i < index; i++)
			cpy[i] = _array[i];



		cpy[index] = element;



		for (size_t i = index + 1; i < _size; i++)
			cpy[i] = _array[i - 1];



		delete[] _array;



		_array = cpy;



	}



	template<typename T>
	friend ostream& operator<<(ostream& print, Vector<T>& vctr);
	template<typename T>
	friend istream& operator>>(ostream& input, Vector<T>& vctr);
};



template <class T>
ostream& operator<<(ostream& print, Vector<T>& vctr)
{
	print << "Vector size: " << vctr.size() << endl;
	print << "Vector capacity: " << vctr.capacity() << endl;
	for (size_t i = 0; i < vctr.size(); i++)
	{
		print << vctr.getData()[i] << " ";
	}
	print << endl;
	return print;
}
template <class T>
istream& operator>>(istream& input, Vector<T>& vctr)
{
	size_t size = 0;
	size_t capacity = 0;
	cout << "Vector size: "; input >> size; cout << endl;
	cout << "Vector capacity: "; input >> capacity; cout << endl;



	T* new_arr = new T[capacity]{};
	for (size_t i = 0; i < size; i++)
	{
		cout << i + 1 << ". element: ";
		input >> new_arr[i]; cout << endl;
	}
	vctr.set_capacity(capacity);
	vctr.set_size(size);
	vctr.set_arr(new_arr, size);
	delete[] new_arr;
	return input;
}



void main()
{
	int* arr = new int[6] {11, 1, 3, 8, 2, 4};
	//cout << endl;


	Vector<int> v(arr, 6, 16);

	//cout << v[7];


	//v.delete_by_index(0);


	//cout << v;


	//cout << v.rfind(2);

	//cout << v;



	v.insert_by_index(1, 4);
	cout << v;
}