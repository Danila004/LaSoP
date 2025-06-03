module;

#include<iostream>
#include<string>
#include<chrono>
#include<format>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>
import Container;
import Employee;

export module Department;

export
class Department
{
private:
	Container<Employee> v;
	std::string name{};
public:
	Department() {}

	void add(Employee elem);
	void del(Employee elem);
	void del(size_t i);
	void del_worse();
	void change(Employee elem, size_t i);
	void change(Employee old_elem, Employee new_elem);
	void print(std::ostream_iterator<Employee> it) const;
	void input(std::istream_iterator<Employee> it);
	void sort(std::function<bool(Employee& a, Employee& b)>& compare);
	Department select(std::function<bool(const Employee& a)>& lambda);
	std::vector<Employee>& get();
	bool empty();
	void clear();
	int size();
	void set_name(std::string name);
	std::string get_name() const;
	friend std::istream& operator>>(std::istream& stream, Department& x);
	friend std::ostream& operator<<(std::ostream& stream, Department& x);
};


export
void Department::add(Employee elem)
{
	v.add(elem);
}

export
void Department::del(Employee elem)
{
	v.del(elem);
}

export
void Department::del(size_t i)
{
	v.del(i);
}

export
void Department::del_worse()
{
	size_t index{};
	double useful{ v.get()[0].usefulness() }, tmp_useful{};
	for (int i{}; i < v.size(); ++i)
	{
		tmp_useful = v.get()[i].usefulness();
		if (useful > tmp_useful)
		{
			useful = tmp_useful;
			++index;
		}
	}
	v.del(index);
}

export
void Department::change(Employee elem, size_t i)
{
	v.change(elem, i);
}

export
void Department::change(Employee old_elem, Employee new_elem)
{
	v.change(old_elem, new_elem);
}

export
void Department::print(std::ostream_iterator<Employee> it) const
{
	v.print(it);
}

export
void Department::input(std::istream_iterator<Employee> it)
{
	v.input(it);
}

export
void Department::sort(std::function<bool(Employee& a, Employee& b)>& compare)
{
	v.sort(compare);
}

export
Department Department::select(std::function<bool(const Employee& a)>& lambda)
{
	Department tmp;
	tmp.v = v.select(lambda);
	return tmp;
}

export
std::vector<Employee>& Department::get()
{
	return v.get();
}

export
bool Department::empty()
{
	return v.empty();
}

export
void Department::clear()
{
	v.clear();
}

export
int Department::size()
{
	return v.size();
}

export
void Department::set_name(std::string name)
{
	this->name = name;
}

export
std::string Department::get_name() const
{
	return name;
}

export
std::istream& operator>>(std::istream& stream, Department& x)
{
	x.clear();
	stream >> x.name;
	try
	{
		std::istream_iterator<Employee> in(stream);
		x.input(in);
	}
	catch (std::exception ex) { }
	return stream;
}

export
std::ostream& operator<<(std::ostream& stream, const Department& x)
{
	stream << x.get_name() << "\n\n";
	std::ostream_iterator<Employee> out(stream, "\n");
	x.print(out);
	return stream;
}
