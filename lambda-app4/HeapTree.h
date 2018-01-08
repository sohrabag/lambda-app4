#pragma once
#include <memory>

/**************************************************************************************************/
/*										Heap Tree implementation								  */
template<class T>
class HeapTree
{
public:
	HeapTree(int maxsize=20);
	HeapTree(const HeapTree * obj);
	virtual ~HeapTree()
	{
		//traverse the tree and destroy all the nodes.
		RemoveTree();
	}

	//methods and operations
	void Insert(T k);
	void unheap(int k); // k is the index of the node in the array
	void down_heap(T k);
	void RemoveTree();
	bool IsEmpty();
	friend  ostream& operator<<(ostream& out, HeapTree ht);
	//data members
protected:
	//Heap Tree is an array of only keys with maximum size of N
	T * _data;
	int _N;	//maxsize of the array.
	int _maxSize;//current position where we are at
};

ostream& operator<<(ostream& out, HeapTree<char> ht) {
	for (int i = 1; i < ht._N; i++)
		out << ht._data[i] << " ";
	out << "\n";

	return out;
}

template<class T>
HeapTree<T>::HeapTree(int maxsize) {

	try {
		_maxSize = maxsize;
		_data = (int*)calloc (_maxSize + 1, sizeof(int));
		::memset(_data, 0, sizeof(int));
		_N = 1;
	}
	catch (bad_alloc& ba) {
		cout << ba.what() << endl;
	}
}

template<class T>
HeapTree<T>::HeapTree(const HeapTree *obj){
	_data = obj->_data;
	_N = obj->_N;
	_maxSize = obj->_maxSize;
}

template<class T>
void HeapTree<T>::Insert(T k){
	try {
		if ( 1 > _N && _N > _maxSize ) throw std::out_of_range("zereshk");
			_data[_N++] = k;	//one item added to the heap --> violation of heap condition at this point!?
			//call unheap to remove the violation of heap condition as we mentioned above.
			unheap(_N-1);
	}
	catch (exception ex) {
		cerr << ex.what() << endl;
	}
}

template<class T>
bool HeapTree<T>::IsEmpty() {
	return _N == 1;
}

//unheap swims up the tree to fix violation of priority queue condition
//each parent must be larger that its children
template<class T>
void HeapTree<T>::unheap(int k){
	try{
		//check _data is not empty.
		if (IsEmpty())	return;

		while ( k > 1 && ( _data[k/2] < _data[k] ) )
		{
			//swap carefully
			T t; t = _data[k / 2]; _data[k / 2] = _data[k]; _data[k] = t;
			//swim up the heap from child to the parent.
			k = k / 2;
		}
	}
	catch(bad_alloc& ba){
		cerr << ba.what() << endl;
}

	return;
}

//sink top-down the heap tree. this is when the parent is less than the children 
//so that it is necessary to reHeapify the tree.
template<class T>
void HeapTree<T>::down_heap(T k) {
	try {

	}
	catch(exception ex) {
		cerr << ex.what() << endl;
	}

	return;
}

template<class T>
void HeapTree<T>::RemoveTree() {
	try {
		if(_data) delete [] _data;
	}
	catch (exception ex) {
		cerr << ex.what() << endl;
	}
}


