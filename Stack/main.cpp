#include <iostream>
#include <string>
#include "Stack.hpp"

int main()
{
	try
	{
		std::cout << "\033[31m";
		ft::Stack<int> intSta;
		ft::Stack<std::string> stringSta;
		intSta.push(7);
		std::cout << intSta.top() << " TOP of stack<int>" << std::endl;
		stringSta.push("hello");
		stringSta.push("Внутри");
		ft::Stack<std::string> cop = stringSta;
		std::cout << cop.size() << " -size(). Проверка размера после присваивания" << std::endl;
		std::cout << stringSta.top() << " top<string>" << std::endl;
		stringSta.pop();
		cop = stringSta;
		std::cout << cop.size() << " - size() после pop\n";
		std::cout << (cop==stringSta) << " ==" << std::endl;
		stringSta.pop();
		std::cout << (cop==stringSta) << " !=" << std::endl;
		stringSta.pop();
	}
	catch (std::exception const &ex)
	{
		std::cerr << "Exception: "
			<< ex.what() << std::endl;
		std::cout << "проверка отработки исключений в POP\033[0m" << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}
