module;

#include<iostream>
#include<iomanip>
#include<string>
#include<chrono>
#include<format>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>
#include<fstream>
import Container;
import Department;

export module Company;

export
class Company
{
private:
	Container<Department> v;
public:
	Company();

	void add(Department elem);
	void del(std::string name);
	void del(size_t i);
	void del_worse();
	void remove(size_t i, Department& source);
	void print(std::ostream_iterator<Department> it);
	void input(std::istream_iterator<Department> it);
	void statistic();
	std::vector<Department>& get();
	bool empty();
	~Company();
};


export
Company::Company()
{
	std::ifstream file("state.txt");
	std::istream_iterator<Department> in(file);
	v.input(in);
	file.close();
}

void Company::add(Department elem)
{
	v.add(elem);
}

export
void Company::del(std::string name)
{
	size_t i{};
	v.del(i);
}

export
void Company::del(size_t i)
{
	v.del(i);
}

export
void Company::del_worse()
{
	size_t department{}, employee{};
	double useful{ v.get()[0].get()[0].usefulness() }, tmp_useful{};
	for(int i{};i<v.size();++i)
		for (int j{};j<v.get()[i].size();++j)
		{
			tmp_useful = v.get()[i].get()[j].usefulness();
			if (useful > tmp_useful)
			{
				department = i;
				employee = j;
				useful = tmp_useful;
			}
		}
	v.get()[department].del(employee);
}

export
void Company::remove(size_t i, Department& source)
{
	std::copy(source.get().begin(), source.get().end(), std::back_inserter(v.get()[i].get()));
}

export
void Company::print(std::ostream_iterator<Department> it)
{
	v.print(it);
}

export
void Company::input(std::istream_iterator<Department> it)
{
	v.input(it);
}

void Company::statistic()
{
	unsigned int max_salary_department{}, min_salary_department{}, max_salary_company{},
		min_salary_company{ v.get()[0].get()[0].get_salary() }, sum_salary{}, k{};
	double useful{ v.get()[0].get()[0].usefulness() }, tmp_useful{};
	Employee best_employee{ v.get()[0].get()[0] };
	std::string** matrix = new std::string*[5];
	for (int i{}; i < 5; ++i)
		matrix[i] = new std::string[v.size()];

	for (Department i : v.get())
	{
		matrix[0][k] = i.get_name();
		matrix[1][k] = std::to_string(i.size());
		max_salary_department = v.get()[k].get()[0].get_salary();
		min_salary_department = v.get()[k].get()[0].get_salary();
		for (Employee j : i.get())
		{
			sum_salary += j.get_salary();
			tmp_useful = j.usefulness();
			if (tmp_useful > useful)
			{
				useful = tmp_useful;
				best_employee = j;
			}
			if (max_salary_department < j.get_salary())
				max_salary_department = j.get_salary();
			if(min_salary_department > j.get_salary())
				min_salary_department = j.get_salary();
		}
		matrix[2][k] = std::to_string(sum_salary);
		matrix[3][k] = std::to_string(max_salary_department);
		matrix[4][k] = std::to_string(min_salary_department);
		++k;
		sum_salary = 0;
		if (max_salary_company < max_salary_department)
			max_salary_company = max_salary_department;
		if (min_salary_company > min_salary_department)
			min_salary_company = min_salary_department;
	}

	std::cout << "Название отдела      ";
	for (int i{}; i < v.size(); ++i)
		std::cout << std::setw(15) << std::left << matrix[0][i];
	std::cout << '\n';
	std::cout << "Кол-во работников    ";
	for (int i{}; i < v.size(); ++i)
		std::cout << std::setw(15) << std::left << matrix[1][i];
	std::cout << '\n';
	std::cout << "Сумарная зарплата    ";
	for (int i{}; i < v.size(); ++i)
		std::cout << std::setw(15) << std::left << matrix[2][i];
	std::cout << '\n';
	std::cout << "Макс. зарплата       ";
	for (int i{}; i < v.size(); ++i)
		std::cout << std::setw(15) << std::left << matrix[3][i];
	std::cout << '\n';
	std::cout << "Мин. зарплата        ";
	for (int i{}; i < v.size(); ++i)
		std::cout << std::setw(15) << std::left << matrix[4][i];
	std::cout << "\n\n";
	std::cout << "Макс. зарплата в компании: " << max_salary_company << '\n';
	std::cout << "Мин. зарплата в компании : " << min_salary_company << '\n';
	std::cout << "Лучший сотрудник компании:\n\n";
	std::cout << best_employee << '\n';

	for (int i{}; i < 5; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

export
std::vector<Department>& Company::get()
{
	return v.get();
}

export
bool Company::empty()
{
	return v.empty();
}

Company::~Company()
{
	std::ofstream file("state.txt");
	std::ostream_iterator<Department> out(file,"===============\n");
	v.print(out);
	file.close();
}


