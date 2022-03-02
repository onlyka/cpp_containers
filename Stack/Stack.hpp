#ifndef __STACK_HPP_
# define __STACK_HPP_

# include "../vector/vector.hpp"
# include <stdexcept>
namespace ft{
template <typename T, typename Cont = ft::vector<T> >
class Stack
{
	public:
		explicit Stack(const Cont &cont = Cont()){}
		Stack(const Stack<T, Cont> & old): _cont(old.getter()){}
		Stack &operator=(const Stack &old);
		~Stack(){}
		void		push(T const &src);
		void		pop();
		T&			top() const;
		const T&	top();
		bool		empty() const;
		const Cont&	getter() const;
		std::size_t	size() const;

	private:
		Cont	_cont;
};

template <typename T, typename Cont>
void Stack<T, Cont>::push(T const &elem)
{
	_cont.push_back(elem);
}

template <typename T, typename Cont>
void Stack<T, Cont>::pop()
{
	if (_cont.empty())
	{
		throw std::out_of_range("Stack<>::pop ():"
			   	" empty stack");
	}
	_cont.pop_back();
}

template <typename T, typename Cont>
T& Stack<T, Cont>::top() const
{
	if (_cont.empty())
	{
		throw std::out_of_range("Stack<>::top():"
				" empty stack");
	}
	return _cont.back();
}

template <typename T, typename Cont>
const T& Stack<T, Cont>::top()
{
	if (_cont.empty())
	{
		throw std::out_of_range("Stack<>::top():"
				" empty stack");
	}
	return _cont.back();
}

template <typename T, typename Cont>
bool Stack<T, Cont>::empty() const
{
	return _cont.empty();
}

template <typename T, typename Cont>
const Cont& Stack<T, Cont>::getter() const
{
	return _cont;
}

template <typename T, typename Cont>
std::size_t Stack<T, Cont>::size() const
{
	return _cont.size();
}

template <typename T, typename Cont>
Stack<T, Cont>& Stack<T, Cont>::operator=(const Stack &old)
{
	_cont = old.getter();
	return *this;
}

template< class T, class Cont >
bool operator==( const Stack<T,Cont>& lef, const Stack<T,Cont>& righ)
{
	return lef.getter() == righ.getter();
}

template< class T, class Cont >
bool operator!=( const Stack<T,Cont>& lef, const Stack<T,Cont>& righ)
{
	return lef.getter() != righ.getter();
}

template< class T, class Cont >
bool operator<( const Stack<T,Cont>& lef, const Stack<T,Cont>& righ)
{
	return lef.getter() < righ.getter();
}

template< class T, class Cont >
bool operator<=( const Stack<T,Cont>& lef, const Stack<T,Cont>& righ)
{
	return lef.getter() <= righ.getter();
}

template< class T, class Cont >
bool operator>( const Stack<T,Cont>& lef, const Stack<T,Cont>& righ)
{
	return lef.getter() > righ.getter();
}

template< class T, class Cont >
bool operator>=( const Stack<T,Cont>& lef, const Stack<T,Cont>& righ)
{
	return lef.getter() >= righ.getter();
}
}
#endif
