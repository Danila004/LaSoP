module;

#include<iostream>
#include<string>
#include<chrono>
#include<format>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>


export module Container;

export
template<typename T>
class Container
{
private:
	std::vector<T> v;
public:
	Container() {}

	void add(T elem);
	void del(T elem);
	void del(size_t i);
	void change(T elem, size_t i);
	void change(T old_elem, T new_elem);
	void print(std::ostream_iterator<T> it) const;
	void input(std::istream_iterator<T> it);
	void sort(std::function<bool(T& a, T& b)>& compare);
	Container<T> select(std::function<bool(const T& a)>& lambda);
	std::vector<T>& get();
	bool empty();
	void clear();
	int size();
};

export template<typename T>
void Container<T>::clear()
{
	v.clear();
}

export template<typename T>
int Container<T>::size()
{
	return v.size();
}

export template<typename T>
void Container<T>::add(T elem)
{
	v.push_back(elem);
}

export template<typename T>
void Container<T>::del(T elem)
{
	std::erase(v, elem);
}

export template<typename T>
void Container<T>::del(size_t i)
{
	if (v.size() > i)
		v.erase(v.begin() + i);
}

export template<typename T>
void Container<T>::change(T elem, size_t i)
{
	if (v.size() > i)
		v[i] = elem;
}

template<typename T>
void Container<T>::change(T old_elem, T new_elem)
{
	auto it = std::find(v.begin(), v.end(), old_elem);
	if (it != v.end())
		*it = new_elem;
}

export template<typename T>
void Container<T>::print(std::ostream_iterator<T> it) const
{
	std::copy(v.begin(), v.end(), it);
}

export template<typename T>
void Container<T>::input(std::istream_iterator<T> it)
{
	std::istream_iterator<T> eos;
	std::copy(it, eos, std::back_inserter(v));
}

export template<typename T>
void Container<T>::sort(std::function<bool(T& a, T& b)>& compare)
{
	std::sort(v.begin(), v.end(), compare);
}

template<typename T>
Container<T> Container<T>::select(std::function<bool(const T& a)>& lambda)
{
	Container tmp;
	std::copy_if(v.begin(), v.end(), std::back_inserter(tmp.v), lambda);
	return tmp;
}

template<typename T>
std::vector<T>& Container<T>::get()
{
	return v;
}

template<typename T>
bool Container<T>::empty()
{
	return v.size() <=> 0 == 0;
}
