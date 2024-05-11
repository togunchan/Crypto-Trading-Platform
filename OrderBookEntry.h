#pragma once

#include <string>

enum class OrderBookType
{
    bid,
    ask,
    unknown,
    asksale,
    bidsale
};

class OrderBookEntry
{
public:
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType,
                   std::string username = "dataset");

    static OrderBookType stringToOTderBookType(std::string s);

    static bool compareByTimestamp(OrderBookEntry &e1, OrderBookEntry &e2);
    static bool compareByPriceAsc(OrderBookEntry &e1, OrderBookEntry &e2);
    static bool compareByPriceDesc(OrderBookEntry &e1, OrderBookEntry &e2);

    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    std::string username;
};