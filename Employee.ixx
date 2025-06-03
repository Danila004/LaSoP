module;

#include<iostream>
#include<string>
#include<chrono>
#include<format>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>
#include<compare>
export module Employee;

export enum class Position{ Manager, SManager, Accountant, Director};
export enum class Gender{Man, Woman};

export
class Employee
{
	
	std::string name{}, surname{}, patronymic{};
	std::chrono::year_month_day start_date{}, end_date{};
	Position position;
	Gender gender;
	unsigned int salary{};
	bool state{};
public:
	Employee(){}
	Employee(std::string name, std::string surname, std::string patronymic, Position position, Gender gender, unsigned int salary, 
		std::chrono::year_month_day start_date, std::chrono::year_month_day end_date, bool state):name(name),surname(surname),patronymic(patronymic),
		position(position),gender(gender),salary(salary), start_date(start_date), end_date(end_date),state(state) {}
	std::string get_surname() const;
	std::string get_name() const;
	std::chrono::year_month_day get_start_date() const;
	std::chrono::year_month_day get_end_date() const;
	unsigned int get_salary() const;
	Gender get_gender() const;
	bool get_state() const;
	double usefulness();

	friend std::istream& operator>>(std::istream& in, Employee& e);
	friend std::ostream& operator<<(std::ostream& out, const Employee& e);
	bool operator==(const Employee& e);
	std::string to_string() const;
};



export std::istream& operator>>(std::istream& in, Employee& e)
{
	std::string border{};
	in >> border;
	if (border.find('=') != std::string::npos || border == "")
		throw std::invalid_argument("================");
	
	e.surname = border;
	int year{}, month{}, day{};
	std::string g{}, p{};
	in >> e.name >> e.patronymic >> day >> month >> year;
	e.start_date = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
	in >> day >> month >> year;
	e.end_date = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
	in >> p >> g >> e.salary >> e.state;

	if (p <=> "Manadger" == 0) e.position = Position(0);
	else if (p <=> "SManadger" == 0) e.position = Position(1);
	else if (p <=> "Accountant" == 0) e.position = Position(2);
	else if (p <=> "Director" == 0) e.position = Position(3);


	if (g <=> "Man" == 0) e.gender = Gender(0);
	else if (g <=> "Woman" == 0) e.gender = Gender(1);
	
	return in;
}

export std::ostream& operator<<(std::ostream& out, const Employee& e)
{
	return out << e.to_string();
}


std::string Employee::get_surname() const
{
	return surname;
}

std::string Employee::get_name() const
{
	return name;
}

std::chrono::year_month_day Employee::get_start_date() const
{
	return start_date;
}

std::chrono::year_month_day Employee::get_end_date() const
{
	return end_date;
}

unsigned int Employee::get_salary() const
{
	return salary;
}

Gender Employee::get_gender() const
{
	return gender;
}

bool Employee::get_state() const
{
	return state;
}

double Employee::usefulness()
{
	return 50000/salary + (int(position) + 1) * (int(gender) + 1);
}

bool Employee::operator==(const Employee& e)
{
	return this->name <=> e.name == 0 && this->surname <=> e.surname == 0 && this->patronymic <=> e.patronymic == 0 && this->start_date <=> e.start_date == 0 &&
		this->end_date <=> e.end_date == 0 && this->salary <=> e.salary == 0 && this->state <=> e.state == 0 && this->position <=> e.position == 0 && this->gender <=> e.gender == 0;
}

std::string Employee::to_string() const
{
	std::string res{};
	int day{}, month{}, year{};
	res += surname + " " + name + " " + patronymic + "\n" +
		   std::format("{} {} {}", static_cast<unsigned>(start_date.day()), static_cast<unsigned>(start_date.month()), start_date.year()) + "\n" +
		   std::format("{} {} {}", static_cast<unsigned>(end_date.day()), static_cast<unsigned>(end_date.month()), end_date.year()) + "\n";
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
