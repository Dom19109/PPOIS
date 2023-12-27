#include "D:\Проекты\PPOIS_2_test\PPOIS_2_test\Header.h"

Food::Food()
{
	_name = "NONE";
	_taste = "NONE";
	_price = 0;
	_position_in_menu = -1;
}

Food::Food(std::string name, std::string taste, int price)
{
	_name = name;
	_taste = taste;
	_price = price;
	_position_in_menu = -1;
}

int Food::get_price() 
{
	return _price;
}

std::string Food::get_name()
{
	return _name;
}

std::string Food::get_taste()
{
	return _taste;
}

int Food::get_position() 
{
	return _position_in_menu;
}

void Food::set_position(int position)
{
	_position_in_menu = position;
}

void Human::buy_food(Food& Needed_food)
{
	_money -= Needed_food.get_price();
}

Human::Human()
{
	_name = "G";
	_surname = "G";
	_age = 0;
	_money = 0;
}

Human::Human(std::string name, std::string surname, int money, int age)
{
	_name = name;
	_surname = surname;
	_age = age;
	_money = money;
}

std::string Human::get_name()
{
	return _name;
}

std::string Human::get_surname()
{
	return _surname;
}

int Human::get_money()
{
	return _money;
}

int Human::get_age()
{
	return _age;
}

void Worker::earn_money()
{
	_money += _salary;
}

void Worker::get_tips(int tips)
{
	_money += tips;
}

int Worker::get_salary()
{
	return _salary;
}

Worker::Worker() : Human()
{
	_salary = 0;
}

Worker::Worker(std::string name, std::string surname, int money, int age, int salary) : Human(name, surname, money, age)
{
	_salary = salary;
}

void Cook::cook_food(int position_of_food, std::vector<int>& storage)
{
	storage[position_of_food-1]++;
}

Cook::Cook() : Worker()
{}

Cook::Cook(std::string name, std::string surname, int money, int age, int salary) : Worker(name, surname, money, age, salary)
{}

void Musician::Sing()
{
	std::cout << "Just sing\n";
}

Musician::Musician() : Worker()
{}

Musician::Musician(std::string name, std::string surname, int money, int age, int salary, std::string style) : Worker(name, surname, money, age, salary)
{
	_main_style = style;
}

std::string Musician::get_style()
{
	return _main_style;
}

std::vector<Song> Musician::get_songs()
{
	return std::vector<Song>();
}

void Guest::give_tips(int tips, Worker& Tipped_worker)
{
	Tipped_worker.get_tips(tips);
	_money -= tips;
}

void Guest::order(Food& Requested_food)
{
	_money-=Requested_food.get_price();
	_order_list.push_back(Requested_food.get_position());
}

std::vector<int>& Guest::get_order_list()
{
	return _order_list;
}

void Guest::empty_order_list()
{
	_order_list.clear();
}

Guest::Guest() : Human()
{}

Guest::Guest(std::string name, std::string surname, int money, int age) : Human(name, surname, money, age)
{}

void Waiter::take_order(Guest& Served_guest, Cook& Working_cook, std::vector<int>& storage)
{
	size_t size_of_order = Served_guest.get_order_list().size();
	for (size_t i = 0; i < size_of_order; i++)
		bring_order_to_cook(Served_guest.get_order_list()[i], Working_cook, storage);
	bring_food_to_guest(Served_guest);
}

void Waiter::bring_order_to_cook(int cooked_food, Cook& Working_cook, std::vector<int>& storage)
{
	return Working_cook.cook_food(cooked_food, storage);
}

void Waiter::bring_food_to_guest(Guest& Served_guest)
{
	Served_guest.empty_order_list();
}

Waiter::Waiter() : Worker()
{}

Waiter::Waiter(std::string name, std::string surname, int money, int age, int salary) : Worker(name,surname,money,age,salary)
{}

void Kafe::set_storage(std::vector<int>& new_storage)
{
	_storage = new_storage;
}

Kafe::Kafe()
{
	_name = "NONE";
	_adres = "NONE";
	_star_count = 0;
	_revenue = 0;
	_budjet = 0;
	_number_of_places = 0;
}

Kafe::Kafe(std::string name, std::string adres, int rating, int revenue, int budjet, int number_of_places)
{
	_name = name;
	_adres = adres;
	_star_count = rating;
	_revenue = revenue;
	_budjet = budjet;
	_number_of_places = number_of_places;
}

void Kafe::hire_waiter(Waiter& New_worker)
{
	_waiters.push_back(New_worker);
}

void Kafe::hire_cook(Cook& New_worker)
{
	_cooks.push_back(New_worker);
}

void Kafe::hire_musician(Musician& New_worker)
{
	_musicians.push_back(New_worker);
}

void Kafe::add_to_menu(Food& New_food)
{
	_menu.push_back(New_food);
	_storage.push_back(0);
	New_food.set_position(_menu.size());
}

void Kafe::change_name(std::string name)
{
	_name = name;
}

std::vector<Food>& Kafe::get_menu()
{
	return _menu;
}

int Kafe::get_revenue() 
{
	return _revenue;
}

std::string Kafe::get_name()
{
	return _name;
}

std::string Kafe::get_adres()
{
	return _adres;
}

int Kafe::get_stars()
{
	return _star_count;
}

int Kafe::get_budjet()
{
	return _budjet;
}

int Kafe::get_number_of_places()
{
	return _number_of_places;
}


void Kafe::add_to_queue(Guest& Waiting_guest)
{
	_queue.push_back(Waiting_guest);
}

std::vector<int>& Kafe::get_storage()
{
	return _storage;
}

void Kafe::work_procces()
{
	size_t number_of_guest = _queue.size(), number_of_waiters = _waiters.size(), number_of_cooks = _cooks.size(); 
	for (size_t i = 0, j = 0, k = 0; i < number_of_guest; i++, j++, k++)
	{
		if (j > number_of_waiters-1)
			j = 0;
		if (k > number_of_cooks-1)
			k = 0;
		_waiters[j].take_order(_queue[i], _cooks[k], _storage);
	}
	_queue.clear();
}

std::vector<Cook>& Kafe::get_cooks_list()
{
	return _cooks;
}

std::vector<Waiter>& Kafe::get_waiters_list()
{
	return _waiters;
}

std::vector<Musician>& Kafe::get_musicians_list()
{
	return _musicians;
}

BusinessManagment::BusinessManagment()
{
	_budjet = 0;
}

BusinessManagment::BusinessManagment(int budjet)
{
	_budjet = budjet;
}

void BusinessManagment::earn_money()
{
	size_t amount_of_kafe = _kafe_chain.size();
	for (size_t i = 0; i < amount_of_kafe; i++)
		_budjet += _kafe_chain[i].get_revenue();
}

void BusinessManagment::buy_kafe(Kafe& New_kafe)
{
	_kafe_chain.push_back(New_kafe);
}

void BusinessManagment::hire_clerk(Worker& New_worker)
{
	_clerks.push_back(New_worker);
}

void BusinessManagment::print_report()
{
	std::cout << "Amount of clerks\t" << _clerks.size() << "\n";
	size_t amount_of_kafe = _kafe_chain.size();
	std::cout << "Amount of kafe\t" << amount_of_kafe << "\n";
	std::cout << "Budjet" << _budjet << "\n";
	int month_revenue = 0;
	for (size_t i = 0; i < amount_of_kafe; i++)
		month_revenue += _kafe_chain[i].get_revenue();
	std::cout << "Month revenue" << month_revenue << "\n";
}

std::vector<Worker>& BusinessManagment::get_clerks()
{
	return _clerks;
}

std::vector<Kafe>& BusinessManagment::get_kafes()
{
	return _kafe_chain;
}

int BusinessManagment::get_budjet()
{
	return _budjet;
}

Song::Song()
{
	_style = "NONE";
	_name = "NONE";
	_author = "NONE";
	_rating = 0;
}

Song::Song(std::string style, std::string name, std::string author, int rating)
{
	_style = style;
	_name = name;
	_author = author;
	_rating = rating;
}

std::string Song::get_style()
{
	return _style;
}

std::string Song::get_author()
{
	return _author;
}

std::string Song::get_name()
{
	return _name;
}

int Song::get_rating()
{
	return _rating;
}
