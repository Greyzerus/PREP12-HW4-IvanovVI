#include "Product.hpp"
#include <iostream>
#include <fstream>
#include <string.h>

Product::Product (
	char* name,
    char* manufacturer,
    int cost,
    int shell_life,
    int count
	)	/*:
	name(NULL),
    manufacturer(0),
    cost(0),
    shell_life(0),
    count(0)
	char cur_sl_type ('h')*/
{
	if (name)
		this->name = name;
	if (manufacturer)
		this->manufacturer = manufacturer;
	if (cost)
		this->cost = cost;
	if (shell_life)
		this->shell_life = shell_life;
	if (count)
		this->count = count;
}


Product::~Product(void)
{
	if (this->name != NULL)
		delete[] this->name;
	this->name = NULL;
	if (this->manufacturer != NULL)
		delete[] this->manufacturer;
	this->manufacturer = NULL;
}

/*void Product::set_all (char* name, char* manufacturer,
		int cost, int shell_life, int count)
		{
		    Product.set_name(name);
		    Product.set_manufacturer(manufacturer);
		    Product.set_cost(cost);
		    Product.set_shell_life(shell_life);
		    Product.set_count(count);
		}*///Not debugged

Product& Product::operator=(const Product& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	if (name) {
		delete[] name;
		name = NULL;
	}
	if (manufacturer)	{
		delete[] manufacturer;
		manufacturer = NULL;
	}
	if (rhs.name) {
		size_t name_len = strlen(rhs.name) + 1;
		name = new char[name_len];
		memcpy(name, rhs.name, name_len);
	}
	if (rhs.manufacturer) {
		size_t man_len = strlen(rhs.manufacturer) + 1;
		manufacturer = new char[man_len];
		memcpy (manufacturer, rhs.manufacturer, man_len);
	}
	cost = rhs.cost;
	shell_life = rhs.shell_life;
	count = rhs.count;
	return *this;
}


	void Product::set_name(char* name)	{
		this->name = name;
	}
    void Product::set_manufacturer (char* manufacturer)	{
		this->manufacturer = manufacturer;
	}
    void Product::set_cost (int cost)	{
		this->cost = cost;
	}
    void Product::set_shell_life (int shell_life)	{
		this->shell_life = shell_life;
	}
    void Product::set_count (int count)	{
		this->count = count;
	}


	const char* Product::get_name(){
		return name;
	}
    const char* Product::get_manufacturer(){
		return manufacturer;
	}
    int Product::get_cost(){
		return cost;
	}
    int Product::get_shell_life (){
		return shell_life;
	}
    int Product::get_count (){
		return count;
	}

    void Product::print_name(){
		if (name)
		std::cout << this->name <<'\t';
	}
    void Product::print_manufacturer (){
		if (manufacturer)
		std::cout << this->manufacturer <<'\t';
	}
    void Product::print_cost (){
		std::cout << this->cost <<'\t';
	}
    void Product::print_shell_life (){
		std::cout << this->shell_life <<'\t'<<'\t';
	}
    void Product::print_count (){
		std::cout << this->count <<'\t';
	}
	void Product::print_all ()	{
		print_name();
		print_manufacturer ();
		print_cost ();
		print_shell_life ();
		print_count ();
		std::cout << std::endl;
	}
