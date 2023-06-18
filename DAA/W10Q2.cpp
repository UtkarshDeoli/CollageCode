#include <iostream>

#include <algorithm>
struct Item
{
    int weight;
    int value;
};
bool compareItems(const Item &a, const Item &b)
{
    double ratioA = (double)a.value / a.weight;
    double ratioB = (double)b.value / b.weight;
    return ratioA > ratioB;
}
void fractionalKnapsack(Item *items, int N, int capacity)
{
    std::sort(items, items + N, compareItems);
    double totalValue = 0.0;
    int remainingCapacity = capacity;
    for (int i = 0; i < N; i++)
    {
        if (remainingCapacity == 0)
            break;
        if (items[i].weight <= remainingCapacity)
        {
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
            std::cout << "Item " << i + 1 << ": Fraction = 1" << std::endl;
        }
        else
        {
            double fraction = (double)remainingCapacity / items[i].weight;
            totalValue += fraction * items[i].value;
            std::cout << "Item " << i + 1 << ": Fraction = " << fraction << std::endl;
            remainingCapacity = 0;
        }
    }
    std::cout << "Maximum value: " << totalValue << std::endl;
}
int main()
{
    int N; // Number of items
    std::cin >> N;
    Item *items = new Item[N];
    // Input weights of the items
    for (int i = 0; i < N; i++)
    {
        std::cin >> items[i].weight;
    }
    // Input values of the items
    for (int i = 0; i < N; i++)
    {
        std::cin >> items[i].value;
    }
    int capacity; // Maximum capacity of knapsack
    std::cin >> capacity;
    fractionalKnapsack(items, N, capacity);
    delete[] items;
    return 0;
}