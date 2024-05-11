#pragma once

#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class OrderBook
{
public:
    /** Construct, reading a csv data file */
    OrderBook(std::string filename);
    /** return vector of all known products in the dataset */
    std::vector<std::string> getKnownProducts();
    /** return vector of Oders according to the sent filters */
    std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);
    /** return the earlist time in the orderbook */
    std::string getEarliestTime();
    /** return the next time after the sent time in the orderbook. If there is no next timestamp, wraps around to the start */
    std::string getNextTime(std::string timestamp);

    void insertOrder(OrderBookEntry &order);

    std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

    static double getHighPrice(std::vector<OrderBookEntry> &orders);
    static double getLowPrice(std::vector<OrderBookEntry> &orders);

private:
    std::vector<OrderBookEntry> orders;
};