#include <iostream>
using namespace std;

struct Goods
{
    char *firm_name;
    char *product_name;
    char *sales_region;
    int selling_cost;
    char *delivery_time;
    int number_of_delivery_units;
};

struct Profit
{
    char *firm_name;
    int profitability;
};

void Output(Goods *inf, int n, Profit *firms, int n2)
{
    // ѕодсчЄт объЄма продаж каждой фирмы
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (firms[i].firm_name == inf[j].firm_name)
                firms[i].profitability += inf[j].number_of_delivery_units;
        }
    }
    // —ортировка фирм по объЄму продаж
    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n2 - i - 1; i++)
        {
            if (firms[j].profitability < firms[i].profitability) 
                swap(firms[j],firms[i]);
        }
    }
    
    char *region = "Kiev";
    
    for (int i = 0; i < n; i++)
    {
        if (region == inf[i].sales_region && inf[i].firm_name == firms[0].firm_name) // ¬ывод товаров согласно условию
        {
            cout << "Name of firm: " << inf[i].firm_name << endl;
            cout << "Name of product: " << inf[i].product_name << endl;
            cout << "Sales region: " << inf[i].sales_region << endl;
            cout << "Selling cost: " << inf[i].selling_cost << endl;
            cout << "Delivery time" << inf[i].delivery_time << endl;
            cout << "Number of delivery units: " << inf[i].number_of_delivery_units << endl;
            cout << endl;
        }
    }
}

int main()
{
    const int n = 9;
    Goods inf[] = {
        { "Borjomi", "water", "Kiev", 10, "14.06.17", 25 },
        { "Borjomi", "mineral", "Lviv", 15, "05.10.16", 17 },
        { "Borjomi", "water", "Kiev", 11, "12.08.17", 14 },
        { "Borjomi", "water", "Odessa", 10, "01.10.16", 14 },
        { "Sandora", "juice", "Kiev", 15, "30.06.17", 8 },
        { "Sandora", "fresh", "Lviv", 35, "12.12.16", 12 },
        { "Sandora", "icetea", "Rivne", 15, "21.03.17", 22 },
        { "Nesquick", "coffee", "Kiev", 40, "03.12.17", 32 },
        { "Nesquick", "cocoa", "Odessa", 37, "14.04.17", 8 }
    };
    
    const int n2 = 3;
    Profit firms[] = {
        { "Borjomi", 0},
        { "Sandora", 0},
        { "Nesquick", 0}
    };
    Output(inf, n, firms, n2);
    
}
