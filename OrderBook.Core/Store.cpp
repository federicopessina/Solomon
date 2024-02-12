#include<algorithm>
#include<vector>

#include "Store.h"

Store::Store()
{
    make_heap(m_orders.begin(), m_orders.end(), [](Order& a, Order& b)  
        { 
            double aPrice = a.getPrice();
            return false; 
        });
}

Store::~Store()
{

}

void Store::add(Order order)
{
    m_orders.push_back(order);
    std::push_heap(m_orders.begin(), m_orders.end(), [](const Order& a, const Order& b) { return false; });
}

std::vector<Order> Store::get() const
{
    return m_orders;
}
