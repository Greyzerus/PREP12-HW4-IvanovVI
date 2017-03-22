#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>

#ifndef PREP12_HW4_IVANOVVI_PRODUCT_HPP
#define PREP12_HW4_IVANOVVI_PRODUCT_HPP

#ifndef MANUFACTURER_NAME_LENGTH
#define MANUFACTURER_NAME_LENGTH 30
#endif

#ifndef SHELL_LIFE_TYPE_LENGTH
#define SHELL_LIFE_TYPE_LENGTH 30
#endif

#ifndef NAME_LENGTH
#define NAME_LENGTH 30
#endif


class Product {
public:
    Product (
	char* name = NULL,
    char* manufacturer = NULL,
    int cost = 0,
    int shell_life = 0,
    int count = 0
		);
    Product (const Product& rhs);
    ~Product(void);
	Product& operator=(const Product& rhs);

    /*void set_all (char* name, char* manufacturer,
		int cost, int shell_life, int count);*///Not debugged
    void set_name(char* name);
    void set_manufacturer (char* manufacturer);
    void set_cost (int cost);
    void set_shell_life (int shell_life);
    void set_count (int count);

    const char* get_name();
    const char* get_manufacturer();
    int get_cost();
    int get_shell_life ();
    int get_count ();

    void print_name();
    void print_manufacturer ();
    void print_cost ();
    void print_shell_life ();
    void print_count ();
	void print_all ();

private:
    char* name;
    char* manufacturer;
    int cost;
    int shell_life;
    int count;
};


#endif //PREP12_HW4_IVANOVVI_PRODUCT_HPP
