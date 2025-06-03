//Выполнил Шелухин Данила

//Сотрудник» представляет собой структуру с полями : имя; фамилия, отчество, дата
//трудоустройства(использовать одну из предлагаемых языком структур); дата
//увольнения(может не быть); должность — перечисление, пол — перечисление,
//заработная плата.Выборка сотрудников производится путем указания
//пользователем подходящего интервала по одному из критериев : фамилия, зарплата.
//Выборка всех сотрудников - мужчин и выборка всех сотрудников - женщин.Выборка
//всех сотрудников, которые числились в штате в указанный пользователем день.
//Шаблонный класс должен иметь дополнительный метод сортировки.Добавить
//в меню возможность отсортировать сотрудников по имени и по фамилии в прямом
//и обратном порядке.


#include<iostream>
#include<fstream>
#include<string>
#include<typeinfo>
#include<algorithm>
#include<chrono>
#include<Windows.h>
import Company;
import Employee;


short menu()
{
	std::cout << "\nВыберете задачу:\n";
	std::cout << "1.Добавить элемент\n";
	std::cout << "2.Удалить элемент\n";
	std::cout << "3.Изменить элемент\n";
	std::cout << "4.Создать выборку\n";
	std::cout << "5.Отсортировать по фамилии\n";
	std::cout << "6.Напечатать\n";
	std::cout << "7.Завершить работу\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 7 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice;
}

short input_menu()
{
	std::cout << "\nВыберите способ ввода:\n1.С консоли\n2.Из файла\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice;
}

void end_menu(bool& exit)
{
	std::cout << "\n1. Продолжить\n2. Завершить работу\n->";
	int end;
	std::cin >> end;
	if (std::cin.fail() || end <=> 1 == std::strong_ordering::less || end <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	end == 1 ? exit = false : exit= true;
}

short output_menu()
{
	std::cout << "\nВыберите способ вывода\n1. В консоль\n2. В файл\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 6 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice;
}

short submenu_for_del_or_change()
{
	std::cout << "\nВыберите способ\n1. По значению\n2. По индексу\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 6 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice;
}

short submenu_for_selection()
{
	std::cout << "\nВыберете ключ выборки:\n";
	std::cout << "1.Фамилия\n";
	std::cout << "2.Зарплата\n";
	std::cout << "3.Пол\n";
	std::cout << "4.Нахождение в штате\n\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 4 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice;
}

bool submenu_for_gender()
{
	std::cout << "\nВыберите пол\n1. Мужской\n2. Женский\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice == 1 ? 0 : 1;
}

bool submenu_for_sorting()
{
	std::cout << "\nВыберите порядок\n1. Прямой\n2. Обратный\n->";
	short choice;
	std::cin >> choice;
	if (std::cin.fail() || choice <=> 1 == std::strong_ordering::less || choice <=> 2 == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return choice == 1 ? 0 : 1;
}

std::string check_file()
{
	std::cout << "Введите имя файла без расширения\n->";
	std::string file;
	std::cin >> file;
	file = file + ".txt";
	std::ifstream ifile(file);
	if (!ifile || ifile.eof())
		throw std::invalid_argument("Невалидный аргумент");
	return file;
}


size_t input_index(Company<Employee>& x)
{
	size_t right_border = x.get().size() - 1, index{};
	std::cout << "Введите индекс(от 0 до " + std::to_string(right_border) + "):\n->";
	std::cin >> index;
	if (std::cin.fail() || index <=> 0 == std::strong_ordering::less || index <=> right_border == std::strong_ordering::greater) throw std::invalid_argument("Невалидный аргумент");
	return index;
}

void input_surnames(std::string& left, std::string& right)
{
	std::cout << "Введите левую границу интервала\n->";
	std::cin >> left;
	std::cout << "Введите правую шраницу интервала\n->";
	std::cin >> right;
}

void input_salary(size_t& left, size_t& right)
{
	std::cout << "Введите левую границу интервала\n->";
	std::cin >> left;
	if (std::cin.fail() || left <=> 0 == std::strong_ordering::less) throw std::invalid_argument("Невалидный аргумент");
	std::cout << "Введите правую шраницу интервала\n->";
	std::cin >> right;
	if (std::cin.fail() || right <=> 0 == std::strong_ordering::less) throw std::invalid_argument("Невалидный аргумент");
}

std::chrono::year_month_day input_date()
{
	int day{}, month{}, year{};
	std::cout << "Введите дату(в формате день,число,год через пробел):\n->";
	std::cin >> day >> month >> year;
	if (std::cin.fail() || !(day <=> 0 == std::strong_ordering::greater && day <=> 32 == std::strong_ordering::less) || 
		!(month <=> 0 == std::strong_ordering::greater && month <=> 12 == std::strong_ordering::less) && 
		!(year <=> 1000 == std::strong_ordering::greater && year <=> 2026 == std::strong_ordering::less)) throw std::invalid_argument("Невалидный аргумент");
	return std::chrono::year_month_day(std::chrono::year(year), std::chrono::month(month), std::chrono::day(day));
}

void example_employee()
{
	std::string res{"\nПример:\n"};
	res += std::string("ФИО: Иванов Иван Иванович\n") +
						"Дата начала работы: 10 12 2010\n" +
						"Дата увольнения: 10 12 2020(или 0 0 0000 если нет даты)\n" +
						"Должность: Manadger(или SManadger, Accountant, Director)\n" +
						"Пол: Man(или Woman)\n" +
						"Зарплата: 10000\n" +
						"Нахождение в штате: 1(или 0)\n";
	std::cout << res;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Company<Employee> bmw;
	bool exit{};
	do
	{
		try
		{
			if (bmw.empty())
			{
				if (input_menu() == 1)
				{
					example_employee();
					std::cout << "\nВведите сотрудков:\n";
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
			}

			if (!bmw.empty())
			{
				Company<Employee> tmp;
				switch (menu())
				{
				case 1:
				{
					example_employee();
					std::cout << "\nВведите сотрудков:\n";
					std::istream_iterator<Employee> in(std::cin);
					bmw.input(in);
					std::cin.clear();
					std::cin.ignore(std::cin.rdbuf()->in_avail());
					break;
				}
				case 2:
				{
					if (submenu_for_del_or_change() <=> 1 == 0)
					{
						example_employee();
						std::cout << "\nВведите сотрудника:\n\n";
						std::istream_iterator<Employee> in(std::cin);
						if (std::cin.fail())
							throw std::invalid_argument("Неправильно ввели сотрудника\n");
						else bmw.del(*in);
					}
					else
						bmw.del(input_index(bmw));
					std::cout << "\nУдаление проведено успешно\n\n";
					break;
				}
				case 3:
				{
					int choice{ submenu_for_del_or_change() };
					example_employee();
					std::cout << "\nВведите сотрудника, которым замените:\n\n";
					std::istream_iterator<Employee> in_new(std::cin);
					if (std::cin.fail())
						throw std::invalid_argument("Невалидный аргумент");
					if (choice <=> 1 == 0)
					{
						std::cout << "\nВведите сотрудника, которого замените:\n\n";
						std::istream_iterator<Employee> in_old(std::cin);
						if (std::cin.fail())
							throw std::invalid_argument("Невалидный аргумент");
						bmw.change(*in_old, *in_new);
					}
					else bmw.change(*in_new, input_index(bmw));
					std::cout << "\nЗамена проведена успешно\n\n";
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
						std::function<bool(const Employee& a)> lambda = [&rborder, &lborder](const Employee& elem)
							{if (elem.get_surname() <=> lborder == std::strong_ordering::greater && elem.get_surname() <=> rborder == std::strong_ordering::less) 
							return true; return false; };
							tmp = bmw.select(lambda);
						break;
					}
					case 2:
					{
						size_t lborder{}, rborder{};
						input_salary(lborder, rborder);
						std::function<bool(const Employee& a)> lambda = [&lborder, &rborder](const Employee& elem)
							{if (elem.get_salary() <=> lborder == std::strong_ordering::greater && elem.get_salary() <=> rborder == std::strong_ordering::less) 
							return true; return false; };
							tmp = bmw.select(lambda);
						break;
					}
					case 3:
					{
						if (!submenu_for_gender())
						{
							std::function<bool(const Employee& a)> lambda = [](const Employee& elem)
								{if (elem.get_gender() <=> Gender::Man == 0) return true; return false; };
								tmp = bmw.select(lambda);
						}
						else
						{
							std::function<bool(const Employee& a)> lambda = [](const Employee& elem)
								{if (elem.get_gender() <=> Gender::Woman == 0) return true; return false; };
								tmp = bmw.select(lambda);
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

						tmp = bmw.select(lambda);
						break;
					}
					}
					if (output_menu() <=> 1 == 0)
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
								return a.get_surname() <=> b.get_surname() == std::strong_ordering::less || a.get_surname() <=> b.get_surname() == 0 && 
									a.get_name() <=> b.get_name() == std::strong_ordering::less;
							};
						bmw.sort(compare);
					}
					else
					{
						std::function<bool(Employee& a, Employee& b)> compare = [](Employee& a, Employee& b)
							{
								return a.get_surname() <=> b.get_surname() == std::strong_ordering::greater || a.get_surname() <=> b.get_surname() == 0 && 
									a.get_name() <=> b.get_name() == std::strong_ordering::greater;
							};
						bmw.sort(compare);
					}
					break;
				case 6:
					if (output_menu() <=> 1 == 0)
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

		}
		catch (std::exception ex)
		{
			std::cout << '\n' << ex.what() << '\n';
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			if (bmw.empty()) end_menu(exit);
		}

	} while (!exit);

	return 0;
}










/*const std::chrono::year_month_day elem_start_date(elem.get_start_date());
								const std::chrono::year_month_day elem_end_date(elem.get_end_date());
								if (elem.get_state() && (elem_start_date <=> date == std::strong_ordering::less || elem_start_date <=> date == 0) &&
									(elem_end_date <=> default_date == 0 || (elem_end_date <=> date == std::strong_ordering::greater || elem_end_date <=> date == 0)))
									return true;
								return false;*/