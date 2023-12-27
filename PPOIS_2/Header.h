#pragma once
#include <string>
#include <vector>
#include <iostream>
/**

    @class   Food
    @brief   class for representation of food
    @details ~

**/
class Food
{
private: std::string _name, _taste; int _price, _position_in_menu;
public:
 /**
     @brief Food object constructor
 **/
	Food();
 /**
     @brief Food object constructor
     @param  - name
     @param  - taste
     @param  - price
 **/
	Food(std::string, std::string, int);
 /**
     @brief  getter
     @retval  - price
 **/
	int get_price();
 /**
     @brief  getter
     @retval  - name
 **/
	std::string get_name() ;
 /**
     @brief  getter
     @retval  - taste
 **/
	std::string get_taste() ;
 /**
     @brief  getter
     @retval  - position in menu
 **/
	int get_position() ;
 /**
     @brief Setter for position
     @param  - position
 **/
	void set_position(int);
};
/**

    @class   Song
    @brief   class for representation of song
    @details ~

**/
class Song
{
private:
	std::string _style, _name, _author; int _rating;
public:
 /**
     @brief Song object constructor
 **/
	Song();
 /**
     @brief Song object constructor
     @param  - style
     @param  - name
     @param  - author
     @param  - rating
 **/
	Song(std::string, std::string, std::string, int);
 /**
     @brief  getter
     @retval  - style 
 **/
	std::string get_style();
 /**
     @brief  getter
     @retval  - author
 **/
	std::string get_author();
 /**
     @brief  getter
     @retval  - name
 **/
	std::string get_name();
 /**
     @brief  getter
     @retval  - rating
 **/
	int get_rating();
};
/**

    @class   Human
    @brief   class for same scheme of child procceses
    @details ~

**/
class Human
{
protected: int _age, _money; std::string _name, _surname;
public:
 /**
     @brief method for buying food
     @param  - object of Food class
 **/
	void buy_food(Food&);
 /**
     @brief Human object constructor
 **/
	Human();
 /**
     @brief Human object constructor
     @param  - name
     @param  - surname
     @param  - money
     @param  - age
 **/
	Human(std::string, std::string, int, int);
 /**
     @brief  getter
     @retval  - name
 **/
	std::string get_name();
 /**
     @brief  getter
     @retval  - surname
 **/
	std::string get_surname();
 /**
     @brief  getter
     @retval  - money
 **/
	int get_money();
 /**
     @brief  getter
     @retval  - age
 **/
	int get_age();
};
/**

    @class   Worker
    @brief   Class for same scheme for child procceses
    @details ~

**/
class Worker : public Human
{
protected: int _salary;
public:
 /**
     @brief method for earning money
 **/
	void earn_money();
 /**
     @brief tips
     @param size of tip
 **/
	void get_tips(int);
 /**
     @brief  getter
     @retval  - sallary
 **/
	int get_salary();
 /**
     @brief Worker object constructor
 **/
	Worker();
 /**
     @brief Worker object constructor
     @param  - name
     @param  - surname
     @param  - money
     @param  - age
     @param  - salary
 **/
	Worker(std::string, std::string, int, int, int);
};
/**

    @class   Cook
    @brief   class for shiefs
    @details ~

**/
class Cook : public Worker
{
public:
 /**
     @brief Main method
     @param  - place in menu
     @param  - storage
 **/
	void cook_food(int, std::vector<int>&);
    /**
        @brief Cook object constructor
    **/
    Cook();
    /**
        @brief Cook object constructor
        @details just like Worker
    **/
    Cook(std::string, std::string, int,int,int);
};
/**

    @class   Musician
    @brief   class for Musicians in a Kafe
    @details ~

**/
class Musician : public Worker
{
private:
	std::string _main_style; std::vector<Song> _song_of_this_author;
public:
 /**
     @brief Just sing
 **/
	void Sing();
 /**
     @brief Musician object constructor
 **/
	Musician();
    /**
    @brief Cook object constructor
    @details just like Worker
**/
    Musician(std::string, std::string, int,int,int, std::string);
    /**
        @brief  getter
        @retval  - style
    **/
    std::string get_style();
    /**
    @brief  getter
    @retval  - songs
**/
    std::vector<Song> get_songs();
};
/**

    @class   Guest
    @brief   visitors of Kafe
    @details ~

**/
class Guest : private Human
{
private:
	std::vector<int> _order_list;
public:
 /**
     @brief give_tips
     @param  - amount of tips
     @param  - Works who tipped
 **/
	void give_tips(int, Worker&);
 /**
     @brief Make order
     @param  - food wich requested
 **/
	void order(Food&);
 /**
     @brief  getter
     @retval  - order_list
 **/
	std::vector<int>& get_order_list();
 /**
     @brief emptier of order list
 **/
	void empty_order_list();
 /**
     @brief Guest object constructor
 **/
	Guest();
 /**
     @brief Guest object constructor
     @details Init just like Human
 **/
	Guest(std::string, std::string, int,int);
};
/**

    @class   Waiter
    @brief   
    @details ~

**/
class Waiter :
	public Worker
{
public:
 /**
     @brief take order from guest
     @param  - Guest
     @param  - Cook
     @param  - storage
 **/
	void take_order(Guest&, Cook&, std::vector<int>&);
 /**
     @brief give orders to cook
     @param  - place in menu
     @param  - Cook
     @param  - storage
 **/
	void bring_order_to_cook(int, Cook&, std::vector<int>&);
 /**
     @brief Clear order list of guest
     @param  - Guest
 **/
	void bring_food_to_guest(Guest&);
 /**
     @brief Waiter object constructor
 **/
	Waiter();
 /**
     @brief Waiter object constructor
     @details just like Worker
 **/
	Waiter(std::string, std::string, int, int, int);
};
/**

    @class   Kafe
    @brief   
    @details ~

**/
class Kafe
{
private: std::string _name, _adres; int _star_count, _revenue, _budjet, _number_of_places; std::vector<Cook> _cooks; std::vector<Waiter> _waiters; std::vector<Musician> _musicians; std::vector<Guest> _queue; std::vector<Food> _menu;  std::vector<int> _storage;
	   void set_storage(std::vector<int>&);
public:
 /**
     @brief Kafe object constructor
 **/
	Kafe();
 /**
     @brief Kafe object constructor
     @param  - name
     @param  - adres
     @param  - budjet
     @param  - revenue
     @param  - star_count
     @param  - number_of_places
 **/
	Kafe(std::string, std::string, int, int, int, int);
 /**
     @brief hire waiters
     @param  - Waiter
 **/
	void hire_waiter(Waiter&);
    /**
    @brief hire cooks
    @param  - Cooks
**/
	void hire_cook(Cook&);
    /**
    @brief hire musicians
    @param  - Musician
**/
	void hire_musician(Musician&);
 /**
     @brief add food in menu
     @param  - Food
 **/
	void add_to_menu(Food&);
 /**
     @brief change name of Kafa
     @param  - new name
 **/
	void change_name(std::string);
 /**
     @brief  getter
     @retval  - adres of menu
 **/
	std::vector<Food>& get_menu();
 /**
     @brief  getter
     @retval  - revenue
 **/
	int get_revenue();
 /**
     @brief  getter
     @retval  - name
 **/
	std::string get_name();
 /**
     @brief  getter
     @retval  - adres
 **/
	std::string get_adres();
 /**
     @brief  getter
     @retval  - stars
 **/
	int get_stars();
 /**
     @brief  getter
     @retval  - budjet
 **/
	int get_budjet();
 /**
     @brief  getter
     @retval  - number_of_places
 **/
	int get_number_of_places();
 /**
     @brief place Guest into queue
     @param  - Guest
 **/
	void add_to_queue(Guest&);
 /**
     @brief  getter
     @retval  - adres of storage
 **/
	std::vector<int>& get_storage();
 /**
     @brief Main proccesing of queue
 **/
	void work_procces();
 /**
     @brief  getter
     @retval  - list of cooks
 **/
	std::vector<Cook>& get_cooks_list();
/**
    @brief  getter
    @retval  - list of waiters
**/
	std::vector<Waiter>& get_waiters_list();
/**
    @brief  getter
    @retval  - list of musicians
**/
	std::vector<Musician>& get_musicians_list();
};
/**

    @class   BusinessManagment
    @brief   class of managment
    @details ~

**/
class BusinessManagment
{
private: std::vector<Worker> _clerks; std::vector<Kafe> _kafe_chain; int _budjet;
public:
 /**
     @brief BusinessManagment object constructor
 **/
	BusinessManagment();
 /**
     @brief BusinessManagment object constructor
     @param  -  budjet
 **/
	BusinessManagment(int);
 /**
     @brief metod for making money
 **/
	void earn_money();
 /**
     @brief buy active(Kafe)
     @param  - Kafe
 **/
	void buy_kafe(Kafe&);
 /**
     @brief hire new worker
     @param  - Worker
 **/
	void hire_clerk(Worker&);
 /**
     @brief making report
 **/
	void print_report();
 /**
     @brief  getter
     @retval  - list of clerks
 **/
	std::vector<Worker>& get_clerks();
 /**
     @brief  getter
     @retval  - list of kafes
 **/
	std::vector<Kafe>& get_kafes();
 /**
     @brief  getter
     @retval  - budjet
 **/
	int get_budjet();
};