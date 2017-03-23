#include "ProcessProducts.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Product.hpp"

#ifndef MANUFACTURER_NAME_LENGTH
#define MANUFACTURER_NAME_LENGTH 30
#endif

#ifndef SHELL_LIFE_TYPE_LENGTH
#define SHELL_LIFE_TYPE_LENGTH 30
#endif

#ifndef NAME_LENGTH
#define NAME_LENGTH 30
#endif


Product* get_Products_from_fstream (int* size, std::fstream* infile)	{
	struct Buf {
		char* name;
		char* manufacturer;
		int cost;
		int shell_life;
		int count;
		/*dry...*/
		Buf* next;
	};

	Buf* head = new (std::nothrow) Buf;
	if (head == NULL)
	{
		std::cerr << "Memloc error." << std::endl;
		return NULL;
	}
	Buf* list = head;
	list->name = new (std::nothrow) char[NAME_LENGTH];
	list->manufacturer = new (std::nothrow) char[MANUFACTURER_NAME_LENGTH];
	if (list->name == NULL || list->manufacturer == NULL)
	{
		std::cerr << "Memloc error." << std::endl;
		return NULL;
	}
	int iter=1;
	while (
			(*infile) >>
			std::setw(NAME_LENGTH) >>
			list->name >>
			std::setw(MANUFACTURER_NAME_LENGTH) >>
			list->manufacturer >>
			list->cost >> list->shell_life >> list->count
		)
	{
		list->next = new(std::nothrow) Buf;
		if (list== NULL)
		{
			std::cerr << "Memloc error." << std::endl;
			return NULL;
		}
		list = list->next;
		list->name = new(std::nothrow) char[NAME_LENGTH];
		list->manufacturer = new(std::nothrow) char[MANUFACTURER_NAME_LENGTH];
		if (list->name == NULL || list->manufacturer == NULL)
		{
			std::cerr << "Memloc error." << std::endl;
			return NULL;
		}
		iter++;
	}
	list->next = NULL;
	if (iter == 1)
	{
		std::cerr << "Can't read from file" << std::endl;
		return NULL;
	}
	Product* Products = new Product[iter];
	*size = --iter;
	std::cout << "Name\tManufacturer\tCost\tShell-life\tCount"<< std::endl;
	for (int n=*size, iter = 0; iter<n; iter++)
	{
		list = head;
		/*Products[iter].set_all (list->name, list->manufacturer,
		list->cost, list->shell_life, list->count);*///Not debugged
		Products[iter].set_name(list->name);
		Products[iter].set_manufacturer(list->manufacturer);
		Products[iter].set_cost(list->cost);
		Products[iter].set_shell_life(list->shell_life);
		Products[iter].set_count(list->count);

		head = head->next;
		delete list;
		Products[iter].print_all();
	}
	Products[20] = Products[15];
	Products[20].print_all();
	Products[15].print_all();
	return Products;
}

void print_products_by_name (char* name, Product* Products, int size)	{
	if (Products == NULL || name == NULL)
	{
		std::cerr << "Eror at calling function \"print_products_by_name\"."
			<<"\nGot NULL"<< std::endl;
		return;
	}
	for (int iter=0; iter<size; iter++)
	{
		if (strcmp (name, Products[iter].get_name()) == 0)	{
			Products[iter].print_all();
		}
	}
}

void print_products_by_name_and_cost (char* name, int cost, Product* Products, int size)	{
	if (Products == NULL || name == NULL)
	{
		std::cerr << "Eror at calling function \"print_products_by_name_and_cost\"."
			<<"\nGot NULL"<< std::endl;
		return;
	}
	for (int iter=0; iter<size; iter++)
	{
		if (strcmp ( name, Products[iter].get_name() ) == 0
			&& cost >= Products[iter].get_cost() )	{
			Products[iter].print_all();
		}
	}
}
int convert_shell_life (int shell_life, const char* shell_life_type, int size)	{
	return 0;
}
void print_products_with_higher_shell_life (int shell_life, Product* Products, int size,
			char* shell_life_type)	{
	if (Products == NULL)
	{
		std::cerr << "Eror at calling function \"print_products_with_higher_shell_life\"."
			<<"\nGot NULL"<< std::endl;
		return;
	}
	for (int iter=0; iter<size; iter++)
	{
		if (shell_life < Products[iter].get_shell_life() )	{
			Products[iter].print_all();
		}
	}
}

void free_Products (Product* Products, int size)
{
	if (Products == NULL)
		return;
	/*for (int iter=size-1; iter>=0; iter--)
	    delete &Products[iter];*///Troubles with destructor
	delete[] Products;
}
