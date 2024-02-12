#include<algorithm>
#include<vector>

#include "Store.h"

Store::Store()
{
    make_heap(m_orders.begin(), m_orders.end(), [](const Order& a, const Order& b) 
        {
            return true;
        });
}

Store::~Store()
{

}

void Store::add(Order order)
{
    m_orders.push_back(order);
    //std::push_heap(m_orders.begin(), m_orders.end());
}

std::vector<Order> Store::get()
{
    return m_orders;
}
