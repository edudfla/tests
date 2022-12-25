#include <iostream>
#include <algorithm>
// g++ -O0 --pedantic -Wall delete_array.cc -o /tmp/delete_array && /tmp/delete_array
class array_item {
private:
	std::string m_container;
	int m_index_in_container;
public:
	array_item() :
	m_container("not set"),
	m_index_in_container(-1)
	{
		std::cout << "Item " << this << " is being created." << std::endl;
	}
	virtual ~array_item()
	{
		std::cout << "Item " << this << " (" << m_container << ", " << m_index_in_container << ") is being destroyed." << std::endl;
	}
	void set_info(const char *container, int index)
	{
		m_container = container;
		m_index_in_container = index;
	}
};

int main()
{
	constexpr auto num_items = 3;
	auto an_array_of_items = new array_item[num_items];
	for (auto i = 0; i < num_items; ++i ) {
		an_array_of_items[i].set_info("an_array_of_items", i);
	}
	delete [] an_array_of_items;
	return 0;
}
