module;

#include<iostream>
#include<string>
#include<chrono>
#include<format>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>
export module Employee;

export enum class Position{ Manager, SManager, Accountant, Director};
export enum class Gender{Man, Woman};

export
struct Employee
{
	
	std::string name{}, surname{}, patronymic{};
	std::chrono::year_month_day start_date{}, end_date{};
	Position position;
	Gender gender;
	unsigned int salary{};
	bool state{};

	Employee(){}
	Employee(std::string name, std::string surname, std::string patronymic, Position position, Gender gender, unsigned int salary, 
		std::chrono::year_month_day start_date, std::chrono::year_month_day end_date, bool state):name(name),surname(surname),patronymic(patronymic),
		position(position),gender(gender),salary(salary), start_date(start_date), end_date(end_date),state(state) {}

	friend std::istream& operator>>(std::istream& in, Employee& e);
	friend std::ostream& operator<<(std::ostream& out, const Employee& e);
	bool operator==(const Employee& e);
	std::string to_string() const;
};

export
template<typename T>
class Company
{
private:
	std::vector<T> v;
public:
	Company() {}
	
	void add(T elem);
	void del(T elem);
	void del(size_t i);
	void change(T elem, size_t i);
	void print(std::ostream_iterator<T> it);
	void input(std::istream_iterator<T> it);
	void sort(std::function<bool(T &a, T &b)>& compare);
	std::vector<T>& get();
	bool empty();
};



export template<typename T>
void Company<T>::add(T elem)
{
	v.push_back(elem);
}

export template<typename T>
void Company<T>::del(T elem)
{
	std::erase(v,elem);
}

export template<typename T>
void Company<T>::del(size_t i)
{
	if (v.size() > i)
		v.erase(v.begin() + i);
}

export template<typename T>
void Company<T>::change(T elem, size_t i)
{
	if (v.size() > i)
		v[i] = elem;
}

export template<typename T>
void Company<T>::print(std::ostream_iterator<T> it)
{
	std::copy(v.begin(), v.end(), it);
}

export template<typename T>
void Company<T>::input(std::istream_iterator<T> it)
{
	std::istream_iterator<T> eos;
	std::copy(it, eos, std::back_inserter(v));
}

export template<typename T>
void Company<T>::sort(std::function<bool(T& a, T& b)>& compare)
{
	std::sort(v.begin(), v.end(), compare);
}

template<typename T>
std::vector<T>& Company<T>::get()
{
	return v;
}

template<typename T>
bool Company<T>::empty()
{
	return v.size() == 0;
}

export std::istream& operator>>(std::istream& in, Employee& e)
{
	int year{}, month{}, day{};
	std::string g{}, p{};
	in >> e.surname >> e.name >> e.patronymic>>day>>month>>year;
	e.start_date = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
	in >> day >> month >> year;
	e.end_date = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
	in >> p >> g >> e.salary >> e.state;

	if (p == "Manadger") e.position = Position(0);
	else if (p == "SManadger") e.position = Position(1);
	else if (p == "Accountant") e.position = Position(2);
	else if (p == "Director") e.position = Position(3);


	if (g == "Man") e.gender = Gender(0);
	else if (g == "Woman") e.gender = Gender(1);
	
	return in;
}

export std::ostream& operator<<(std::ostream& out, const Employee& e)
{
	return out << e.to_string();
}


bool Employee::operator==(const Employee& e)
{
	return this->name == e.name && this->surname == e.surname && this->patronymic == e.patronymic && this->start_date == e.start_date &&
		this->end_date == e.end_date && this->salary == e.salary && this->state == e.state && this->position == e.position && this->gender == e.gender;
}

std::string Employee::to_string() const
{
	std::string res{};
	res += name + " " + surname + " " + patronymic + "\n" +
		   std::format("{}", start_date) + "\n" +
		   std::format("{}", end_date) + "\n";
	switch (position)
	{
	case Position::Manager:
		res += "Manadger\n";
		break;
	case Position::SManager:
		res += "SManadger\n";
		break;
	case Position::Accountant:
		res += "Accountant\n";
		break;
	case Position::Director:
		res += "Director\n";
		break;
	}

	switch (gender)
	{
	case Gender::Man:
		res += "Man\n";
		break;
	case Gender::Woman:
		res += "Woman\n";
		break;
	}
	res += std::to_string(salary) + "\n" +
		   std::to_string(state) + "\n";
	return res;
}
