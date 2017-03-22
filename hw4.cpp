#define SHELL_LIFE_TYPE_LENGTH 30
#define NAME_LENGTH 30
#define MANUFACTURER_NAME_LENGTH 30

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "ProcessProducts.h"
#include "Product.hpp"



int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Not enough or too much arguments\n"
        << "Please enter name of file that contain product data - \n"
        << "Product entries in format:\n"
        << "product_name\nproduct_manufacturer\ncost\nshell-life(hours)\ncount"
		<< std::endl;
		system ("pause");
        return -1;
    }
    std::fstream infile (argv[1],  std::ios_base::in);
    if ( ! infile ) {
        std::cerr << "Error, can't open file: " << argv[1] << std::endl;
        return -2;
    }
	int size;
    Product* Products = get_Products_from_fstream (&size, &infile);
	if (Products == NULL)
		return -1;
	infile.close();


    std::cout << "Enter product name for searching: "<< std::flush;
    char* name;
	name = new char[NAME_LENGTH+1];

	std::cin >> std::setw(NAME_LENGTH) >> name;
	name[NAME_LENGTH] = '\0';
    print_products_by_name (name, Products, size);

    int cost;
    std::cout << "Enter product name and max cost for searching: "<<std::flush;
    std::cin >> std::setw(NAME_LENGTH) >> name >> cost;
    print_products_by_name_and_cost (name, cost, Products, size);
    std::cout << "Enter product's min shell-life: " <<std::flush;
	int shell_life;
    std::cin >> shell_life;
    print_products_with_higher_shell_life (shell_life, Products, size);
	free_Products (Products, size);

}
