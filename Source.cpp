#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
#include<algorithm>
#include<chrono>
#include<Windows.h>
import Company;
import Employee;
import Department;


//�������� ������� ������
//����������� ���������� ���������� ��� ���������� ���������, ���������
//�� ��������� ������� � ����������, ��������, ���������, �������� ������;
//���������� ��������� ������� � ����������, ��������������, ��������
//�����������; ������� �� ��������(��.������ 2) �� ������ � ������������� ������
//� ����������� ����������� � ������ �����.
//�������� �������� ���������� ����������, ������� ��������� ��� ��� ����
//� ��������� �������� ��������(�� ���� ����).�������� ����������� �������
//������ ������������ ���������� �� ������ � ����������� ������� ������
//������������ ���������� �� ��������.
//������������� ����� ���������� �� ���� �������� : ������� ���� ���������
//������ � ���������� ����������� � ��������� �����, ���������� � ����������
//������ c����������� � ������, � ���� ������ ����������� � ���������� ������
//����������� �� ���� ��������, ���������� � ������ ����������.

short menu()
{
	std::cout << "\n�������� ������:\n";
	std::cout << "1.�������� �������\n";
	std::cout << "2.������� �������\n";
	std::cout << "3.�������� �������\n";
	std::cout << "4.������� �������\n";
	std::cout << "5.������������� �� �������\n";
	std::cout << "6.����������\n";
	std::cout << "7.������� ������� ���������� ������\n";
	std::cout << "8.��������� ������ � �������\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 8 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

short main_menu()
{
	std::cout << "\n�������� ������:\n";
	std::cout << "1.�������� �����\n";
	std::cout << "2.������� �����\n";
	std::cout << "3.���������� � �������\n";
	std::cout << "4.������� ����������\n";
	std::cout << "5.������� ������ ������� ����������\n";
	std::cout << "6.����������\n";
	std::cout << "7.��������� ������\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 7 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

short input_menu()
{
	std::cout << "\n�������� ������ �����:\n1.� �������\n2.�� �����\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

short selection_menu()
{
	std::cout << "\n�������� ������ ��� �������:\n";
	std::cout << "1.����������\n";
	std::cout << "2.��������� � ������ �����\n";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

void end_menu(bool& exit)
{
	std::cout << "\n1. ����������\n2. ��������� ������\n->";
	int end;
	std::cin >> end;
	if (std::cin.fail() || end <=> 1 == std::strong_ordering::less || end <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	end == 1 ? exit = false : exit = true;
}

short output_menu()
{
	std::cout << "\n�������� ������ ������\n1. � �������\n2. � ����\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 6 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

short submenu_for_del_or_change()
{
	std::cout << "\n�������� ������\n1. �� ��������\n2. �� �������\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 6 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

short submenu_for_selection()
{
	std::cout << "\n�������� ���� �������:\n";
	std::cout << "1.�������\n";
	std::cout << "2.��������\n";
	std::cout << "3.���\n";
	std::cout << "4.���������� � �����\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 4 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice;
}

bool submenu_for_gender()
{
	std::cout << "\n�������� ���\n1. �������\n2. �������\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice == 1 ? 0 : 1;
}

bool submenu_for_sorting()
{
	std::cout << "\n�������� �������\n1. ������\n2. ��������\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return choice == 1 ? 0 : 1;
}

std::string check_file()
{
	std::cout << "������� ��� ����� ��� ����������\n->";
	std::string file;
	std::cin >> file;
	file = file + ".txt";
	std::ifstream ifile(file);
	if (!ifile || ifile.peek() == EOF)
		throw std::invalid_argument("���������� ��������");
	return file;
}


size_t input_index(auto& x)
{
	size_t right_border = x.get().size() - 1, index{};
	std::cout << "������� ������(�� 0 �� " + std::to_string(right_border) + "):\n->";
	std::cin >> index;
	if (std::cin.fail() || index <=> 0 == std::strong_ordering::less || index <=> right_border == std::strong_ordering::greater) throw std::invalid_argument("���������� ��������");
	return index;
}

void input_surnames(std::string& left, std::string& right)
{
	std::cout << "������� ����� ������� ���������\n->";
	std::cin >> left;
	std::cout << "������� ������ ������� ���������\n->";
	std::cin >> right;
}

void input_salary(size_t& left, size_t& right)
{
	std::cout << "������� ����� ������� ���������\n->";
	std::cin >> left;
	if (std::cin.fail() || left <=> 0 == std::strong_ordering::less) throw std::invalid_argument("���������� ��������");
	std::cout << "������� ������ ������� ���������\n->";
	std::cin >> right;
	if (std::cin.fail() || right <=> 0 == std::strong_ordering::less) throw std::invalid_argument("���������� ��������");
}

std::chrono::year_month_day input_date()
{
	int day{}, month{}, year{};
	std::cout << "������� ����(� ������� ����,�����,��� ����� ������):\n->";
	std::cin >> day >> month >> year;
	if (std::cin.fail() || !(day <=> 0 == std::strong_ordering::greater && day <=> 32 == std::strong_ordering::less) ||
		!(month <=> 0 == std::strong_ordering::greater && month <=> 12 == std::strong_ordering::less) &&
		!(year <=> 1000 == std::strong_ordering::greater && year <=> 2026 == std::strong_ordering::less)) throw std::invalid_argument("���������� ��������");
	return std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
}

void example_employee()
{
	std::string res{ "\n������:\n" };
	res += std::string("���: ������ ���� ��������\n") +
		"���� ������ ������: 10 12 2010\n" +
		"���� ����������: 10 12 2020(��� 0 0 0000 ���� ��� ����)\n" +
		"���������: Manadger(��� SManadger, Accountant, Director)\n" +
		"���: Man(��� Woman)\n" +
		"��������: 10000\n" +
		"���������� � �����: 1(��� 0)\n";
	std::cout << res;
}

template<typename T>
void output_department_or_company(auto& source, std::string name)
{
	if (output_menu() <=> 1 == 0)
	{
		std::cout << "\n";
		if (name != "") std::cout << name << "\n\n";
		std::ostream_iterator<T> out(std::cout, (std::is_same<T, Department>::value ? "====================\n" : "\n"));
		source.print(out);
	}
	else
	{
		std::ofstream file(check_file());
		if (name != "") std::cout << name << "\n\n";
		std::ostream_iterator<T> out(file, (std::is_same<T, Department>::value ? "====================\n" : "\n"));
		source.print(out);
		file.close();
	}
}

void work_with_department(Company& x, size_t i)
{
	bool exit{};
	do
	{
		try
		{
			Department tmp;
			switch (menu())
			{
			case 1:
			{
				example_employee();
				std::cout << "\n������� ���������:\n";
				std::istream_iterator<Employee> in(std::cin);
				//std::copy(in, eos, std::back_inserter(x.get()[i]));
				x.get()[i].input(in);
				std::cin.clear();
				std::cin.ignore(std::cin.rdbuf()->in_avail());
				break;
			}
			case 2:
			{
				if (!x.get()[i].empty())
				{
					if (submenu_for_del_or_change() <=> 1 == 0)
					{
						example_employee();
						std::cout << "\n������� ����������:\n\n";
						std::istream_iterator<Employee> in(std::cin);
						if (std::cin.fail())
						{
							std::cout << "����������� ����� ����������\n";
							std::cin.clear();
							std::cin.ignore(std::cin.rdbuf()->in_avail());
						}
						else x.get()[i].del(*in);
					}
					else
						x.get()[i].del(input_index(x.get()[i]));
					std::cout << "\n�������� ��������� �������\n\n";
				}
				else std::cout << "\n������. ����� ����\n";
				break;
			}
			case 3:
			{
				if (!x.get()[i].empty())
				{
					int choice{ submenu_for_del_or_change() };
					example_employee();
					std::cout << "\n������� ����������, ������� ��������:\n\n";
					std::istream_iterator<Employee> in_new(std::cin);
					if (std::cin.fail())
						throw std::invalid_argument("���������� ��������");
					if (choice <=> 1 == 0)
					{
						std::cout << "\n������� ����������, �������� ��������:\n\n";
						std::istream_iterator<Employee> in_old(std::cin);
						if (std::cin.fail())
							throw std::invalid_argument("���������� ��������");
						x.get()[i].change(*in_old, *in_new);
					}
					else x.get()[i].change(*in_new, input_index(x.get()[i]));
					std::cout << "\n������ ��������� �������\n\n";
				}
				else std::cout << "\n������. ����� ����\n";
				break;
			}
			case 4:
			{
				if (!x.get()[i].empty())
				{
					switch (submenu_for_selection())
					{
					case 1:
					{
						std::string rborder{}, lborder{};
						input_surnames(lborder, rborder);
						std::function<bool(const Employee& a)> lambda = [&rborder, &lborder](const Employee& elem)
							{if (elem.get_surname() <=> lborder == std::strong_ordering::greater && elem.get_surname() <=> rborder == std::strong_ordering::less)
							return true; return false; };
						tmp = x.get()[i].select(lambda);
						break;
					}
					case 2:
					{
						size_t lborder{}, rborder{};
						input_salary(lborder, rborder);
						std::function<bool(const Employee& a)> lambda = [&lborder, &rborder](const Employee& elem)
							{if (elem.get_salary() <=> lborder == std::strong_ordering::greater && elem.get_salary() <=> rborder == std::strong_ordering::less)
							return true; return false; };
						tmp = x.get()[i].select(lambda);
						break;
					}
					case 3:
					{
						if (!submenu_for_gender())
						{
							std::function<bool(const Employee& a)> lambda = [](const Employee& elem)
								{if (elem.get_gender() <=> Gender::Man == 0) return true; return false; };
							tmp = x.get()[i].select(lambda);
						}
						else
						{
							std::function<bool(const Employee& a)> lambda = [](const Employee& elem)
								{if (elem.get_gender() <=> Gender::Woman == 0) return true; return false; };
							tmp = x.get()[i].select(lambda);
						}
						break;
					}
					case 4:
					{
						const std::chrono::year_month_day date{ input_date() };
						const std::chrono::year_month_day default_date(std::chrono::year(0), std::chrono::month(0), std::chrono::day(0));

						std::function<bool(const Employee& a)> lambda = [&date, &default_date](const Employee& elem)
							{
								if (elem.get_state() && (elem.get_start_date() <=> date == std::strong_ordering::less || elem.get_start_date() <=> date == 0) &&
									(elem.get_end_date() <=> default_date == 0 || (elem.get_end_date() <=> date == std::strong_ordering::greater || elem.get_end_date() <=> date == 0)))
									return true;
								return false;
							};

						tmp = x.get()[i].select(lambda);
						break;
					}
					}

					if (selection_menu() <=> 1 == 0)
					{
						if (output_menu() <=> 1 == 0)
						{
							std::ostream_iterator<Employee> out(std::cout, "\n");
							tmp.print(out);
						}
						else
						{
							std::ofstream file(check_file());
							std::ostream_iterator<Employee> out(file, "\n");
							tmp.print(out);
							file.close();
						}
					}
					else
					{
						size_t index{ input_index(x.get()[i]) };
						if (index <=> i == 0) std::cout << "\n��� ��������� ��� � ��������� ������\n";
						else
						{
							x.remove(index, tmp);
							std::cout << "\n����������� ������ �������\n";
						}
					}
				}
				else std::cout << "\n������. ����� ����\n";
				break;
			}
			case 5:
				if (!x.get()[i].empty())
				{
					if (!submenu_for_sorting())
					{
						std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
							{
								return a.get_surname() <=> b.get_surname() == std::strong_ordering::less || a.get_surname() <=> b.get_surname() == 0 &&
									a.get_name() <=> b.get_name() == std::strong_ordering::less;
							};
						x.get()[i].sort(compare);
					}
					else
					{
						std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
							{
								return a.get_surname() <=> b.get_surname() == std::strong_ordering::greater || a.get_surname() <=> b.get_surname() == 0 &&
									a.get_name() <=> b.get_name() == std::strong_ordering::greater;
							};
						x.get()[i].sort(compare);
					}
				}
				else std::cout << "\n������. ����� ����\n";
				break;
			case 6:
				if (!x.get()[i].empty())
				{
					output_department_or_company<Employee>(x.get()[i], x.get()[i].get_name());
				}
				else std::cout << "\n� �����. ����� ����\n";
				break;
			case 7:
			{
				if (!x.get()[i].empty())
				{
					x.get()[i].del_worse();
					std::cout << "\n�������� ������ �������\n";
				}
				else std::cout << "\n� �����. ����� ����\n";
				break;
			}
			case 8:
				exit = true;
				break;
			}
			
		}
		catch (std::exception ex)
		{
			std::cout << '\n' << ex.what() << '\n';
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			if (x.empty()) end_menu(exit);
		}

	} while (!exit);
}

void input_department(Company& x)
{
	if (input_menu() == 1)
	{
		example_employee();
		std::cout << "\n������� ����� �����:\n";
		std::istream_iterator<Department> in(std::cin);
		x.input(in);
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	}
	else
	{
		std::ifstream file(check_file());
		std::istream_iterator<Department> in(file);
		x.input(in);
		file.close();
	}
}

int find_index(Company& x, std::string name)
{
	int index{ -1 };
	for (auto i : x.get())
	{
		if (i.get_name() == name)
			return index + 1;
		else ++index;
	}
	throw std::invalid_argument("��� ������ ������");
}

std::string input_department_name()
{
	std::cout << "\n������� �������� ������, ������� ������ �������:\n\n->";
	std::string name{};
	std::cin >> name;
	return name;
}

void input_company(Company& x, bool& exit)
{
	if (input_menu() == 1)
	{
		example_employee();
		std::cout << "\n������� ��������, �������� ����������� �� ������ ������� ������� ���� ======================. ����� ������ ������� ������� ��� ��������. � ����� ����� �������� ���� ����� ������ ================:\n";
		std::istream_iterator<Department> in(std::cin);
		x.input(in);
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
	}
	else
	{
		std::ifstream file(check_file());
		std::istream_iterator<Department> in(file);
		x.input(in);
		file.close();
	}
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool exit{};
	Company x;
	do
	{
		try
		{
			if (x.empty())
				input_company(x, exit);

			if (!x.empty())
			{
				switch (main_menu())
				{
				case 1:
				{
					input_department(x);
					break;
				}
				case 2:
				{
					if (submenu_for_del_or_change() <=> 1 == 0)
						x.del(find_index(x, input_department_name()));
					else
						x.del(input_index(x));
					std::cout << "\n�������� ��������� �������, ���� ����� ����� ���� � ��������\n\n";
					break;
				}
				case 3:
				{
					if (submenu_for_del_or_change() <=> 1 == 0)
					{
						int index{ find_index(x, input_department_name()) };
						work_with_department(x, index);
					}
					else 
						work_with_department(x, input_index(x));
					break;
				}
				case 4:
					x.statistic();
					break;
				case 5:
					x.del_worse();
					std::cout << "\n�������� ������ �������\n";
					break;
				case 6:
				{
					output_department_or_company<Department>(x, "");
					break;
				}
				case 7:
					exit = true;
					break;
				}
			}

		}
		catch (std::exception ex)
		{
			std::cout << '\n' << ex.what() << '\n';
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			if (x.empty()) end_menu(exit);
		}
		
	} while (!exit);
	
	return 0;
}
