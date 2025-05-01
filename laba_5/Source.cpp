#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
#include<algorithm>
#include<chrono>
#include<Windows.h>
import Employee;

template<typename T>
void correct(T& x, int start, int end, const char* message)
{
	bool isError;
	do
	{
		std::cout << message;
		std::cin >> x;
		isError = true;
		if (!std::cin.fail() && x >= start && x <= end)
			isError = false;
		else
		{
			std::cout << "�� ����� ������������ ��������\n";
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		}
	} while (isError);
}

//short menu()
//{
//
//	std::cout << "\n�������� ������:\n";
//	std::cout << "1.�������� �������\n";
//	std::cout << "2.������� �������\n";
//	std::cout << "3.�������� �������\n";
//	std::cout << "4.������� �������\n";
//	std::cout << "5.�������������\n";
//	std::cout << "6.����������\n\n";
//	short choice;
//	correct(choice, 1, 6, "->");
//	return choice;
//}
//
//short input_menu()
//{
//	std::cout << "\n�������� ������ �����:\n1.� �������\n2.�� �����\n\n";
//	short choice;
//	correct(choice, 1, 2, "->");
//	return choice;
//}
//
//void end_menu(bool& exit)
//{
//	std::cout << "\n1. ����������\n2. ��������� ������\n";
//	int end;
//	correct(end, 1, 2, "->");
//	if (end == 2)
//		exit = true;
//
//}
//
//short output_menu()
//{
//	std::cout << "\n�������� ������ ������\n1. � �������\n2. � ����\n";
//	short x;
//	correct(x, 1, 2, "->");
//	return x;
//}
//
//short submenu_for_del()
//{
//	std::cout << "\n�������� ������ ��������\n1. �� ��������\n2. �� �������\n";
//	short x;
//	correct(x, 1, 2, "->");
//	return x;
//}
//
//short submenu_for_selection()
//{
//	std::cout << "\n�������� ���� �������:\n";
//	std::cout << "1.�������\n";
//	std::cout << "2.��������\n";
//	std::cout << "3.���\n";
//	std::cout << "4.���������� � �����\n\n";
//	short choice;
//	correct(choice, 1, 6, "->");
//	return choice;
//}
//
//bool submenu_for_gender()
//{
//	std::cout << "\n�������� ���\n1. �������\n2. �������\n";
//	short x;
//	correct(x, 1, 2, "->");
//	return x == 1 ? 0 : 1;
//}
//
//bool submenu_for_sorting()
//{
//	std::cout << "\n�������� �������\n1. ������\n2. ��������\n";
//	short x;
//	correct(x, 1, 2, "->");
//	return x == 1 ? 0 : 1;
//}
//
//bool check_file(std::string& file_name)
//{
//	std::cout << "������� ��� ����� ��� ����������\n->";
//	std::string file;
//	std::cin >> file;
//	file = file + ".txt";
//	std::ifstream ifile(file);
//	if (ifile)
//	{
//		if (ifile.eof())
//		{
//			ifile.close();
//			return false;
//		}
//		else ifile.close();
//	}
//	else return false;
//	file_name = file;
//	return true;
//}

//void data_for_action(std::string& name, std::string& surname, std::string& patronymic, Position& position, Gender& gender, unsigned int& salary,
//	std::chrono::year_month_day& start_date, std::chrono::year_month_day& end_date,bool& state)
//{
//	int day{}, month{}, year{}, tmp{};
//	std::cout << "������� ��� ���������:\n ->";
//	std::cin >> name;
//	std::cout << "������� ������� ���������:\n ->";
//	std::cin >> surname;
//	std::cout << "������� �������� ���������:\n ->";
//	std::cin >> patronymic;
//	std::cout << "������� ���� ������ � ��������(� ������� ����,�����,��� ����� ������):\n";
//	correct(day, 1, 31, "->");
//	correct(month, 1, 12, "->");
//	correct(year, 1, 2100, "->");
//	start_date = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
//	std::cout << "������� ���� ����������(� ������� ����,�����,��� ����� ������/���� �� ���, ������� 0 0 0):\n";
//	correct(day, 0, 31, "->");
//	correct(month, 0, 12, "->");
//	correct(year, 0, 2100, "->");
//	end_date = std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
//	std::cout << "������� ��������� ��������� ������(0 - Manadger, 1 - SManadger, 2 - Accountant, 3 - Director):\n";
//	correct(tmp, 0, 3, "->");
//	position = Position(tmp);
//	std::cout << "������� ��� ��������� ������(0 - Man, 1 - Woman):\n";
//	correct(tmp, 0, 1, "->");
//	gender = Gender(tmp);
//	std::cout << "������� �������� ���������:\n";
//	correct(salary, 0, 1000000, "->");
//	std::cout << "��������� � �����(1 - ��, 0 - ���):\n";
//	correct(state, 0, 1, "->");
//}
//
//size_t input_index(Company<Employee>& x)
//{
//	size_t right_border = x.get().size() - 1, index{};
//	std::cout << "������� ������(�� 0 �� " + std::to_string(right_border) + "):\n";
//	correct(index, 0, right_border, "->");
//	return index;
//}
//
//void input_surnames(std::string& left, std::string& right)
//{
//	std::cout << "������� ����� ������� ���������\n";
//	std::cin >> left;
//	std::cout << "������� ������ ������� ���������\n";
//	std::cin >> right;
//}
//
//void input_salary(size_t& left, size_t& right)
//{
//	std::cout << "������� ����� ������� ���������\n";
//	correct(left, 0, 1000000, "->");
//	std::cout << "������� ������ ������� ���������\n";
//	correct(right, 0, 1000000, "->");
//}
//
//std::chrono::year_month_day input_date()
//{
//	int day{}, month{}, year{};
//	std::cout << "������� ����(� ������� ����,�����,��� ����� ������):\n";
//	correct(day, 1, 31, "->");
//	correct(month, 1, 12, "->");
//	correct(year, 1, 2100, "->");
//	return std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
//}
//
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	Company<Employee> bmw;
//	bool exit{}, input{};
//	std::string file_name{};
//	do
//	{
//
//		
//		if (!input)
//		{
//			if (input_menu() == 1)
//			{
//				std::istream_iterator<Employee> in(std::cin);
//				bmw.input(in);
//				std::cin.clear();
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//			}
//			else
//			{
//				if (check_file(file_name))
//				{
//					std::ifstream file(file_name);
//					std::istream_iterator<Employee> in(file);
//					bmw.input(in);
//					file.close();
//				}
//			}
//			if(!bmw.get().empty()) input = true;
//		}
//
//		if (input)
//		{
//			Company<Employee> tmp;
//			switch (menu())
//			{
//			case 1:
//			{
//				std::cout << "\n������� ���������:\n";
//				std::istream_iterator<Employee> in(std::cin), eos;
//				std::copy(in, eos, std::back_inserter(bmw.get()));
//				std::cin.clear();
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//				break;
//			}
//			case 2:
//			{
//				if (submenu_for_del() == 1)
//				{
//					std::cout << "\n������� �����������:\n";
//					std::istream_iterator<Employee> in(std::cin), eos;
//					while (in != eos)
//					{
//						Employee e = *in;
//						bmw.del(e);
//						++in;
//					}
//					std::cin.clear();
//					std::cin.ignore(std::cin.rdbuf()->in_avail());
//				}
//				else
//				{
//					bmw.del(input_index(bmw));
//				}
//				break;
//			}
//			case 3:
//			{
//				size_t index{ input_index(bmw) };
//				std::cout << "\n������� ����������:\n";
//				std::istream_iterator<Employee> in(std::cin);
//				std::istream_iterator<Employee> eos;
//				std::cin.clear();
//				std::cin.ignore(std::cin.rdbuf()->in_avail());
//				if(in != eos) bmw.change(*in, index);
//				break;
//			}
//			case 4:
//			{
//				switch (submenu_for_selection())
//				{
//				case 1:
//				{
//					std::string rborder{}, lborder{};
//					input_surnames(lborder, rborder);
//					std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [&rborder, &lborder](const Employee& elem) {if (elem.surname > lborder && elem.surname < rborder) return true; return false; });
//					break;
//				}
//				case 2:
//				{
//					size_t lborder{}, rborder{};
//					input_salary(lborder, rborder);
//					std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [&lborder, &rborder](const Employee& elem) {if (elem.salary >= lborder && elem.salary <= rborder) return true; return false; });
//					break;
//				}
//				case 3:
//				{
//					if (!submenu_for_gender())
//						std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [](const Employee& elem) {if (elem.gender == Gender::Man) return true; return false; });
//					else
//						std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [](const Employee& elem) {if (elem.gender == Gender::Woman) return true; return false; });
//					break;
//				}
//				case 4:
//				{
//					const std::chrono::year_month_day date{ input_date() };
//					const std::chrono::year_month_day default_date(std::chrono::year(0), std::chrono::month(0), std::chrono::day(0));
//
//					auto lambda = [&date, &default_date](const Employee& elem)
//						{
//							const std::chrono::year_month_day elem_start_date(elem.start_date);
//							const std::chrono::year_month_day elem_end_date(elem.end_date);
//							if (elem.state && elem_start_date >= date && (elem_end_date == default_date || elem_end_date >= date))
//								return true;
//							return false;
//						};
//					std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), lambda);
//					break;
//				}
//				}
//				if (output_menu() == 1)
//				{
//					std::ostream_iterator<Employee> out(std::cout);
//					tmp.print(out);
//				}
//				else
//				{
//					if (check_file(file_name))
//					{
//						std::ofstream file(file_name);
//						std::ostream_iterator<Employee> out(file);
//						tmp.print(out);
//						file.close();
//					}
//				}
//				break;
//					
//			}
//			case 5:
//				if (!submenu_for_sorting())
//				{
//					std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
//						{
//							return a.surname < b.surname || a.surname == b.surname && a.name < b.name;
//						};
//					bmw.sort(compare);
//				}
//				else
//				{
//					std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
//						{
//							return a.surname > b.surname || a.surname == b.surname && a.name > b.name;
//						};
//					bmw.sort(compare);
//				}
//				break;
//			case 6:
//				if (output_menu() == 1)
//				{
//					std::ostream_iterator<Employee> out(std::cout);
//					bmw.print(out);
//				}
//				else
//				{
//					if (check_file(file_name))
//					{
//						std::ofstream file(file_name);
//						std::ostream_iterator<Employee> out(file);
//						bmw.print(out);
//						file.close();
//					}
//				}
//				break;
//			}
//		}
//		
//		end_menu(exit);
//
//	} while (!exit);
//	
//	
//
//	return 0;
//}


short menu()
{
	std::cout << "\n�������� ������:\n";
	std::cout << "1.�������� �������\n";
	std::cout << "2.������� �������\n";
	std::cout << "3.�������� �������\n";
	std::cout << "4.������� �������\n";
	std::cout << "5.�������������\n";
	std::cout << "6.����������\n";
	std::cout << "7.��������� ������\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice < 1 || choice > 7) throw std::invalid_argument("���������� ��������");
	return choice;
}

short input_menu()
{
	std::cout << "\n�������� ������ �����:\n1.� �������\n2.�� �����\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice < 1 || choice > 2) throw std::invalid_argument("���������� ��������");
	return choice;
}

void end_menu(bool& exit)
{
	std::cout << "\n1. ����������\n2. ��������� ������\n->";
	int end;
	std::cin >> end;
	if (std::cin.fail() || end < 1 || end > 2) throw std::invalid_argument("���������� ��������");
	end == 1 ? exit = false : exit= true;
}

short output_menu()
{
	std::cout << "\n�������� ������ ������\n1. � �������\n2. � ����\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice < 1 || choice > 6) throw std::invalid_argument("���������� ��������");
	return choice;
}

short submenu_for_del()
{
	std::cout << "\n�������� ������ ��������\n1. �� ��������\n2. �� �������\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice < 1 || choice > 6) throw std::invalid_argument("���������� ��������");
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
	if (std::cin.fail() || choice < 1 || choice > 4) throw std::invalid_argument("���������� ��������");
	return choice;
}

bool submenu_for_gender()
{
	std::cout << "\n�������� ���\n1. �������\n2. �������\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice < 1 || choice > 2) throw std::invalid_argument("���������� ��������");
	return choice == 1 ? 0 : 1;
}

bool submenu_for_sorting()
{
	std::cout << "\n�������� �������\n1. ������\n2. ��������\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice < 1 || choice > 2) throw std::invalid_argument("���������� ��������");
	return choice == 1 ? 0 : 1;
}

std::string check_file()
{
	std::cout << "������� ��� ����� ��� ����������\n->";
	std::string file;
	std::cin >> file;
	file = file + ".txt";
	std::ifstream ifile(file);
	if (!ifile || ifile.eof())
		throw std::invalid_argument("���������� ��������");
	return file;
}


size_t input_index(Company<Employee>& x)
{
	size_t right_border = x.get().size() - 1, index{};
	std::cout << "������� ������(�� 0 �� " + std::to_string(right_border) + "):\n->";
	std::cin >> index;
	if (std::cin.fail() || index < 0 || index > right_border) throw std::invalid_argument("���������� ��������");
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
	if (std::cin.fail() || left < 0) throw std::invalid_argument("���������� ��������");
	std::cout << "������� ������ ������� ���������\n->";
	std::cin >> right;
	if (std::cin.fail() || right < 0) throw std::invalid_argument("���������� ��������");
}

std::chrono::year_month_day input_date()
{
	int day{}, month{}, year{};
	std::cout << "������� ����(� ������� ����,�����,��� ����� ������):\n->";
	std::cin >> day >> month >> year;
	if (std::cin.fail() || !(day>0 && day <32) || !(month > 0 && month < 12) && !(year > 1000 && year < 2026)) throw std::invalid_argument("���������� ��������");
	return std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
}

void example_employee()
{
	std::string res{"\n������:\n"};
	res += std::string("���: ������ ���� ��������\n") +
						"���� ������ ������: 10 12 2010\n" +
						"���� ����������: 10 12 2020\n" +
						"���������: Manadger(��� SManadger, Accountant, Director)\n" +
						"���: Man(��� Woman)\n" +
						"��������: 10000\n" +
						"���������� � �����: 1(��� 0)\n";
	std::cout << res;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Company<Employee> bmw;
	bool input{}, exit{};
	do
	{
		try
		{
			if (!input)
			{
				if (input_menu() == 1)
				{
					example_employee();
					std::cout << "\n������� ���������:\n";
					std::istream_iterator<Employee> in(std::cin);
					bmw.input(in);
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
				}
				else
				{
					std::ifstream file(check_file());
					std::istream_iterator<Employee> in(file);
					bmw.input(in);
					file.close();
				}
				if(bmw.get().size() != 0) input = true;
			}

			if (input)
			{
				Company<Employee> tmp;
				switch (menu())
				{
				case 1:
				{
					example_employee();
					std::cout << "\n������� ���������:\n";
					std::istream_iterator<Employee> in(std::cin), eos;
					std::copy(in, eos, std::back_inserter(bmw.get()));
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					break;
				}
				case 2:
				{
					if (submenu_for_del() == 1)
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
						else bmw.del(*in);
					}
					else
						bmw.del(input_index(bmw));
					break;
				}
				case 3:
				{
					size_t index{ input_index(bmw) };
					example_employee();
					std::cout << "\n������� ����������:\n\n";
					std::istream_iterator<Employee> in(std::cin);
					if (std::cin.fail())
					{
						std::cout << "����������� ����� ����������\n";
						std::cin.clear();
						std::cin.ignore(std::cin.rdbuf()->in_avail());
					}
					else bmw.change(*in, index);
					break;
				}
				case 4:
				{
					switch (submenu_for_selection())
					{
					case 1:
					{
						std::string rborder{}, lborder{};
						input_surnames(lborder, rborder);
						std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [&rborder, &lborder](const Employee& elem) {if (elem.surname > lborder && elem.surname < rborder) return true; return false; });
						break;
					}
					case 2:
					{
						size_t lborder{}, rborder{};
						input_salary(lborder, rborder);
						std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [&lborder, &rborder](const Employee& elem) {if (elem.salary >= lborder && elem.salary <= rborder) return true; return false; });
						break;
					}
					case 3:
					{
						if (!submenu_for_gender())
							std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [](const Employee& elem) {if (elem.gender == Gender::Man) return true; return false; });
						else
							std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), [](const Employee& elem) {if (elem.gender == Gender::Woman) return true; return false; });
						break;
					}
					case 4:
					{
						const std::chrono::year_month_day date{ input_date() };
						const std::chrono::year_month_day default_date(std::chrono::year(0), std::chrono::month(0), std::chrono::day(0));

						auto lambda = [&date, &default_date](const Employee& elem)
							{
								const std::chrono::year_month_day elem_start_date(elem.start_date);
								const std::chrono::year_month_day elem_end_date(elem.end_date);
								if (elem.state && elem_start_date >= date && (elem_end_date == default_date || elem_end_date >= date))
									return true;
								return false;
							};

						std::copy_if(bmw.get().begin(), bmw.get().end(), std::back_inserter(tmp.get()), lambda);
						break;
					}
					}
					if (output_menu() == 1)
					{
						std::ostream_iterator<Employee> out(std::cout,"\n");
						tmp.print(out);
					}
					else
					{
						std::ofstream file(check_file());
						std::ostream_iterator<Employee> out(file,"\n");
						tmp.print(out);
						file.close();
					}
					break;

				}
				case 5:
					if (!submenu_for_sorting())
					{
						std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
							{
								return a.surname < b.surname || a.surname == b.surname && a.name < b.name;
							};
						bmw.sort(compare);
					}
					else
					{
						std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
							{
								return a.surname > b.surname || a.surname == b.surname && a.name > b.name;
							};
						bmw.sort(compare);
					}
					break;
				case 6:
					if (output_menu() == 1)
					{
						std::cout << "\n";
						std::ostream_iterator<Employee> out(std::cout,"\n");
						bmw.print(out);
					}
					else
					{
						std::ofstream file(check_file());
						std::ostream_iterator<Employee> out(file,"\n");
						bmw.print(out);
						file.close();
					}
					break;
				case 7:
					exit = true;
					break;
				}
			}

			if(!exit)
				end_menu(exit);
		}
		catch (std::invalid_argument ex)
		{
			std::cout << '\n' << ex.what() << '\n';
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		}

	} while (!exit);

	return 0;
}