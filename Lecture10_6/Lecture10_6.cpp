#include <iostream>
#include <initializer_list>
#include <cassert>

class	IntArray
{
private:
	int		m_length = 0;
	int		*m_data = nullptr;

public:
	IntArray(const std::initializer_list<int> & il)
	{
		m_length = (int)il.size();
		m_data = new int[m_length];
		initialize(il);
	}

	~IntArray()
	{
		delete[] m_data;
	}

	void	initialize(const std::initializer_list<int>& il)
	{
		int	count = 0;
		for (auto& ele : il)
		{
			m_data[count] = ele;
			++count;
		}
	}

	void	reset()
	{
		int count = 0;
		for (; count < m_length; ++count)
			m_data[count] = 0;
	}

	void	resize(const int size)
	{
		assert(size >= 0);
		int	*tmp;
		tmp = m_data;
		m_data = new int[size];
		if (m_length < size)
			for (int i = 0; i < m_length; ++i)
				m_data[i] = tmp[i];
		else
			for (int i = 0; i < size; ++i)
				m_data[i] = tmp[i];
		m_length = size;
		delete[] tmp;
	}

	void	insertBefore(const int& value, const int& ix)
	{
		resize(++m_length);
		for (int i = m_length - 1; i > ix; --i)
			m_data[i] = m_data[i - 1];
		m_data[ix] = value;
	}

	void	remove(const int& ix)
	{
		assert(ix >= 0);
		assert(ix < m_length);
		if (m_length == 0)
			return ; //error
		for (int i = ix; i < m_length - 1; ++i)
			m_data[i] = m_data[i + 1];
		resize(--m_length);
	}

	void	push_back(const int& value)
	{
		resize(++m_length);
		m_data[m_length - 1] = value;
	}

	friend	std::ostream& operator << (std::ostream& out, IntArray& intarr)
	{
		for (int i = 0; i < intarr.m_length; ++i)
			out << intarr.m_data[i] << " ";
		return (out);
	}
};

int	main()
{
	IntArray my_arr{ 1, 3, 5, 7, 9 };
	std::cout << my_arr << std::endl;

	my_arr.insertBefore(10, 1);
	std::cout << my_arr << std::endl;
	my_arr.remove(3);
	std::cout << my_arr << std::endl;
	my_arr.push_back(13);
	std::cout << my_arr << std::endl;
}