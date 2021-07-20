#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <memory>
#include <cstddef>
#include <algorithm>

template <class T>
class Vec {
public:
	//Type define
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef	T value_type;
	typedef T& reference;
	typedef const T& const_reference;


	//Constructor
	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	//Destructor
	~Vec() { uncreate(); }
	//Assignment
	Vec& operator=(const Vec&);
	//Index
	T& operator[] (size_type i) { return data[i]; }
	const T& operator[] (size_type i) const { return data[i]; }

	void push_back(const T& val) {
		if (avail == limit)
			grow();
		unchecked_append(val);
	}

	size_type size() const { return avail - data; };

	//Iterator
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

	bool empty() const { return data == avail; }
	void clear();

private:
	iterator data;
	iterator avail;
	iterator limit;

	std::allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);
	void uncreate();
	void grow();
	void unchecked_append(const T&);
};

template <class T>
void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator b, const_iterator e) {
	data = alloc.allocate(e - b);
	limit = avail = std::uninitialized_copy(b, e, data);
}

template <class T>
void Vec<T>::uncreate() {
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, limit - data);
	}
	data = limit = avail = 0;
}

template <class T>
Vec<T>& Vec<T>::operator= (const Vec& rhs) {
	if (&rhs != this) {
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T>
void Vec<T>::grow() {
	size_type new_size = std::max((limit - data) * 2, ptrdiff_t(1));

	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

template <class T>
void Vec<T>::clear() {
	iterator it = avail;
	while (it != data)
		alloc.destroy(--it);
	avail = data;
}

#endif
#pragma once