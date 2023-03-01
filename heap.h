#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
// #include <iostream>

template <typename T, typename PComparator = std::less<T> > //CHANGE TO LESS 
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> myheap;
	int m;
	PComparator c; 
};

// template <typename T>
// LList<T>::Item::Item(const T& v, Item* p, Item* n)
// : val(v), prev(p), next(n)
// {
// }

// template <typename T>
// LList<T>::LList() {
//   mHead = new Item(T(), nullptr, nullptr);
//   mTail = mHead;
//   mSize = 0;
// }

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) {
	this->m = m;
	this->c = c;
}

// template <typename T, typename PComparator>
// Heap<T, PComparator>::Heap() {
// 	m = 2;
// 	c = std::less<T>;
// }

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
	return myheap.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
	return (myheap.size()==0);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap



template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
		throw std::underflow_error("Heap is empty");
    // ================================
    // throw the appropriate exception
    // ================================
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return myheap[0];
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  //following adapted from heaps lecture slides (slide 47)
	myheap.push_back(item);
  if (myheap.size() > 1) {
    size_t parent = (myheap.size()-1)/m;
    // T& temp = NULL;
    size_t new_index = myheap.size()-1;
    while (parent >= 0 && c(myheap[new_index], myheap[parent]) && new_index != parent)
    {
      // temp = myheap[parent];
      // myheap[parent] = myheap[new_index];
			std::swap(myheap[new_index], myheap[parent]);
      new_index = parent;
      parent = parent/m;
    }
  }	
}

// We will start pop() for you to handle the case of 
// calling pop on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");
  }
	std::swap(myheap[0], myheap[myheap.size()-1]);
	// following was based on lab 6 heaps
	myheap.pop_back();
	if (myheap.empty() || myheap.size() == 1)
	{
		return;
	}
	std::size_t index = 0;
	while(true) {
		std::size_t first_index = index * m + 1;
		// if(first_index + 1 == myheap.size())
		// {
		// 	std::cout << "uh" << std::endl;
		// }
		std::size_t other_index = first_index++;
		T& current_item = myheap[index];
		std::size_t best_index = first_index;
		for (int i = 0; i < m-2; i++) //T ??
		{
			if (!c(myheap[first_index], myheap[other_index])) {
				first_index = other_index;
			}
			if (other_index+1 < myheap.size()) {
				other_index++;
			}
			// else {
			// 	i = m*m;
			// }
			if (c(myheap[first_index], myheap[best_index])) {
				best_index = first_index;
			}
		}
		if (best_index == index || c(current_item, myheap[best_index])) {
			break;
		}
		std::swap(current_item, myheap[best_index]);
		index = best_index;
	}



	// if (myheap.empty())
	// {
	// 	return;
	// }
	// std::size_t index = 0;
	// std::size_t best_index = 1;
	// T& current_item = myheap[index];
	// while(true) {
	// 	std::size_t first_index = index * m + 1;
	// 	std::size_t other_index = first_index++;
	// 	for (int i = 0; i < m-1; i++) //T ??
	// 	{
	// 		if (c(myheap[first_index], myheap[other_index])) {
	// 			other_index++;
	// 		}
	// 		else {
	// 			first_index = other_index;
	// 			other_index++;
	// 		}
	// 		if (myheap[first_index] > myheap[best_index]) {
	// 			best_index = first_index;
	// 		}
	// 	}
	// 	if (best_index == index || myheap[best_index] <= current_item) {
	// 		break;
	// 	}
	// 	// T& temp = current_item;
	// 	myheap[index] = myheap[best_index];
	// 	myheap[best_index] = current_item;
	// 	index = best_index;
	// }
}

#endif

