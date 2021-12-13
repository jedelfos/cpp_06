#include "TypeId.hpp"

TypeId::TypeId() {}
TypeId::~TypeId() {}
TypeId::TypeId( const TypeId& rhs ) { *this = rhs; }

TypeId::TypeId( const std::string& str ) : _type(_none_), _str(str) {
	std::istringstream	iss(str);

	if (is_special(str)) {
		_type = _special_;
	} else if (is_int(str)) {
		_type = _int_;
	} else if (is_char(str)) {
		_type = _char_;
	} else if (is_float(str)) {
		_type = _float_;
	} else if (is_double(str)) {
		_type = _double_;
	}

	if (_type  == _int_
		|| _type == _float_
		|| _type == _double_) {
		iss >> _num;
	} else if (_type == _char_) {
		char	c;
		iss >> c;
		_num = c;
	}
}

TypeId&	TypeId::operator=( const TypeId& rhs) {
	if (this == &rhs)
		return *this;

	_type = rhs.get_type();
	_str = rhs.get_string();
	_num = rhs.get_num();
	return *this;
}

bool	TypeId::is_special( const std::string& str ) {
	std::istringstream	iss("-inf +inf nan -inff +inff nanf");
	std::string			tmp;

	while (!iss.eof()) {
		iss >> tmp;
		if (tmp == str) {
			return true;
		}
	}
	return false;
}

bool	TypeId::is_int( const std::string& str ) {
	std::istringstream	iss(str);
	int					n;

	iss >> n;
	return (iss.eof() && !iss.fail());
}

bool	TypeId::is_char( const std::string& str ) {
	return (str.length() == 1 && std::isprint(str[0]));
}

bool	TypeId::is_float( const std::string& str ) {
	std::istringstream	iss(str);
	float				n;
	std::string			f;

	iss >> n;
	iss >> f;
	return (f == "f" && iss.eof() && !iss.fail());
}

bool	TypeId::is_double( const std::string& str ) {
	std::istringstream	iss(str);
	double 				n;

	iss >> n;
	return (iss.eof() && !iss.fail());

}

void	TypeId::print_int() {
	std::cout << "int: ";
	if (_type != _special_ && _type != _none_) {
		std::cout << static_cast<int>(_num) << std::endl;
	} else if (_type  == _none_) {
		std::cout << "bad input" << std::endl;
	} else {
		std::cout << "impossible" << std::endl;
	}
}

void	TypeId::print_char() {
	std::cout << "char: ";
	if (_type  == _none_) {
		std::cout << "bad input" << std::endl;
	} else if (_type == _special_){
		std::cout << "impossible" << std::endl;
	} else if (std::isprint(static_cast<char>(_num))) {
		std::cout << '\'' << static_cast<char>(_num) << '\'' << std::endl;
	} else {
		std::cout << "non printable" << std::endl;
	}
}

static bool special_f( const std::string& str ) {
	std::istringstream	iss("-inff +inff nanf");
	std::string			tmp;

	while (!iss.eof()) {
		iss >> tmp;
		if (tmp == str) {
			return true;
		}
	}
	return false;
}

void	TypeId::print_float() {
	std::cout << "float: ";
	if (_type != _special_ && _type != _none_) {
		std::cout << std::setprecision(8) << static_cast<float>(_num) << 'f' << std::endl;
	} else if (_type  == _special_) {
		if(special_f(_str)) {
			std::cout << _str << std::endl;
		} else {
			std::cout << _str << 'f' << std::endl;
		}
	} else {
		std::cout << "bad input" << std::endl;
	}
}

void	TypeId::print_double() {
	std::cout << "double: ";
	if (_type != _special_ && _type != _none_) {
		std::cout << std::setprecision(8) << _num << std::endl;
	} else if (_type  == _special_) {
		if(!special_f(_str)) {
			std::cout << _str << std::endl;
		} else {
			std::cout << _str.substr(0, _str.length() - 1) << std::endl;
		}
	} else {
		std::cout << "bad input" << std::endl;
	}
}

type				TypeId::get_type() const {
	return _type;
}

const std::string&	TypeId::get_string() const {
	return _str;
}

double				TypeId::get_num() const {
	return _num;
}