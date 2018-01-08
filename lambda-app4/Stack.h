#pragma once

namespace DTStruct
{
/*
	template<class T>
	class Stack
	{
	public:

	Stack(T Elm)
	{
	}

	virtual ~Stack()
	{
	}

	private:
	int stkptr;

	};
*/

/**************************************************************************************************/
template<class T>
class Stack {

public:
	Stack(int max = 500);
	Stack(const Stack<T>& obj);
	virtual ~Stack();

	//operations
	void push(T t);
	T& pop();
	const T& peek(int Depth) const;

protected:
	int _MaxSize;
	T * _data;
	int _stkptr;
};

template<class T>
Stack<T>::Stack(const Stack<T>& obj)
{
	_data = obj._data;
	_MaxSize = obj._MaxSize;
	_stkptr = obj._stkptr;
}

template<class T>
Stack<T>::Stack(int max = 500)
{
	_data = new (500 * sizeof(T));
}

template<class T>
Stack<T>::~Stack()
{
	delete[] _data;
}

template<class T>
T& Stack<T>::pop()
{
	if (_stkptr >= 0)
		return _data[_stkptr];
	if (_stkptr > 0)
		_stkptr--;
}

template<class T>
void Stack<T>::push(T t)
{
	if(stkptr < _MaxSize)
		_data[stkptr++] = t;
}

}
