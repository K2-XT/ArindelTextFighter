//mergesort.h: Contains the mergesort function implementation
#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <queue>

//Prototypes
template <class T>
void mergesort(std::queue<T>&);

template <class T>
void split(std::queue<T>&, std::queue<T>&, std::queue<T>&);

//void merge(): Merges Two Queues in Order.
template <class T>
void merge(std::queue<T>& base, std::queue<T>& lhs, std::queue<T>& rhs) {
	//While one queue not empty...
	while (!lhs.empty() || !rhs.empty()) {
		//If both are not empty...
		if (!lhs.empty() && !rhs.empty()) {
			//If the lhs is more than rhs...
			if (lhs.front() >= rhs.front()) {
				//Push lhs to front and pop lhs.
				base.push(lhs.front());
				lhs.pop();
			}
			//Otherwise, do the same with rhs.
			else {
				base.push(rhs.front());
				rhs.pop();
			}
		}
		//If lhs is not empty, but rhs empty...
		else if (!lhs.empty()) {
			//Automatically push to front.
			base.push(lhs.front());
			lhs.pop();
		}
		//Otherwise, rhs is not empty.
		else {
			//Push rhs to front.
			base.push(rhs.front());
			rhs.pop();
		}
	}
}

//void mergesort(): Calls Split to Split Queues in Half Until Only One Variable per Queue. Then Calls Merge to Merge Queues Together in Order.
template <class T>
void mergesort(std::queue<T>& base) {
	//If the queue is not only one variable...
	if (base.size() > 1) {
		//Split into two queues.
		std::queue<T> lhs;
		std::queue<T> rhs;
		split(base, lhs, rhs);
		mergesort(lhs);
		mergesort(rhs);
		//After the process of splitting the queues doesn to one variable works, merge all together.
		merge(base, lhs, rhs);
	}
}

//void split(): Splits the Queue Inserted Into Halves
template <class T>
void split(std::queue<T>& base, std::queue<T>& lhs, std::queue<T>& rhs) {
	//While the base queue is not empty...
	while (!base.empty()) {
		//If base is not empty...
		if (!base.empty()) {
			//Push base front to lhs.
			lhs.push(base.front());
			base.pop();
			//If still not empty...
			if (!base.empty()) {
				//Push base to rhs.
				rhs.push(base.front());
				base.pop();
			}
		}
	}
}


#endif
