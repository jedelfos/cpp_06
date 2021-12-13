#ifndef TYPEID_HPP
# define TYPEID_HPP

#include <iostream>
#include <sstream>
#include <iomanip>

enum type {
	_int_,
	_char_,
	_float_,
	_double_,
	_special_,
	_none_
};

class TypeId {
	private:
		double		_num;
		type		_type;
		std::string	_str;

		TypeId();

	public:
		TypeId( const TypeId& rhs );
		TypeId( const std::string& str );
		~TypeId();

		TypeId&		operator=( const TypeId& rhs);

		static bool	is_int( const std::string& str );
		static bool	is_char( const std::string& str );
		static bool	is_float( const std::string& str );
		static bool	is_double( const std::string& str );
		static bool	is_special( const std::string& str );

		void print_int();
		void print_char();
		void print_float();
		void print_double();

		type				get_type() const;
		const std::string&	get_string() const;
		double				get_num() const;

};


#endif
