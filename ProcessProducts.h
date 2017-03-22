#ifndef PREP12_HW4_IVANOVVI_PROCESS_PRODUCTS_H
#define PREP12_HW4_IVANOVVI_PROCESS_PRODUCTS_H
#include <fstream>
#include <iostream>
#include "Product.hpp"

Product* get_Products_from_fstream (int* size, std::fstream* istreamptr);
void print_products_by_name (char* name, Product*, int size);
void print_products_by_name_and_cost (char* name, int cost, Product*, int size);
void print_products_with_higher_shell_life (int shell_life, Product*, int size, char* shell_life_type = "h");
void free_Products (Product*, int size);

#endif //PREP12_HW4_IVANOVVI_PROCESS_PRODUCTS_H
