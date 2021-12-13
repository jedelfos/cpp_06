#ifndef CLASS_HPP
# define CLASS_HPP

# include <cstdlib>
# include <iostream>

class Base {

	public:
		virtual ~Base() {};
};

class A : public Base {

	public:
		A() { std::cout << "[A] constructor call"<< std::endl; };
		~A() {};
};

class B : public Base {

	public:
		B() { std::cout << "[B] constructor call"<< std::endl; };
		~B() {};
};

class C : public Base {

	public:
		C() { std::cout << "[C] constructor call"<< std::endl; };
		~C() {};
};

Base*	generate();
void	identify( Base& ref );
void	identify( Base* ptr );

#endif
