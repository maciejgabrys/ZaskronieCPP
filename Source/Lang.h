#ifndef LANG_H_
#define LANG_H_
#include <string>
#include <sstream>
#include <iostream>

class _LANG_V {
private:
	double num;
	std::string str;

public:

	// Constructors:
	_LANG_V() {
		setNum(0.0);
		setStr("");
	}
	_LANG_V(int n) {
		setNum((double)n);
		setStr((double)n);
	}
	_LANG_V(double n) {
		setNum(n);
		setStr(n);
	}
	_LANG_V(const char* s) {
		setNum(std::string(s));
		setStr(std::string(s));
	}
	_LANG_V(const std::string& s) {
		setNum(s);
		setStr(s);
	}
	_LANG_V(const _LANG_V& v) {
		num = v.num;
		str = v.str;
	}

	// Setters:
	void setNum(double n) {
		num = n;
	}
	void setNum(std::string s) {
		try {
			num = std::stod(s);
		}
		catch (...) {
			num = 0.0;
		}
	}
	void setStr(double n) {
		std::ostringstream r;
		r << n;
		str = r.str();
	}
	void setStr(std::string s) {
		str = s;
	}

	// Comparison operations:
	friend bool operator==(const _LANG_V& v1, const _LANG_V& v2) {
		return (v1.str == v2.str);
	}
	friend bool operator!=(const _LANG_V& v1, const _LANG_V& v2) {
		return (v1.str != v2.str);
	}
	friend bool operator>(const _LANG_V& v1, const _LANG_V& v2) {
		return (v1.num > v2.num);
	}
	friend bool operator>=(const _LANG_V& v1, const _LANG_V& v2) {
		return (v1.num >= v2.num);
	}
	friend bool operator<(const _LANG_V& v1, const _LANG_V& v2) {
		return (v1.num < v2.num);
	}
	friend bool operator<=(const _LANG_V& v1, const _LANG_V& v2) {
		return (v1.num <= v2.num);
	}

	// Number operations:
	friend _LANG_V operator+(const _LANG_V& v1, const _LANG_V& v2) {
		return _LANG_V(v1.num + v2.num);
	}
	friend _LANG_V operator-(const _LANG_V& v1, const _LANG_V& v2) {
		return _LANG_V(v1.num - v2.num);
	}
	friend _LANG_V operator*(const _LANG_V& v1, const _LANG_V& v2) {
		return _LANG_V(v1.num * v2.num);
	}
	friend _LANG_V operator/(const _LANG_V& v1, const _LANG_V& v2) {
		return _LANG_V(v1.num / v2.num);
	}

	// String operations:
	friend _LANG_V operator&(const _LANG_V& v1, const _LANG_V& v2) {
		return _LANG_V(v1.str + v2.str);
	}
	friend _LANG_V operator&(const _LANG_V& v, const char* s) {
		return _LANG_V(v.str + std::string(s));
	}
	friend _LANG_V operator&(const char* s, const _LANG_V& v) {
		return _LANG_V(std::string(s) + v.str);
	}

	// Stream operations:
	friend void operator<<(std::ostream& r, const _LANG_V& v) {
		r << v.str;
	}
	friend void operator>>(std::istream& r, _LANG_V& v) {
		std::string t;
		r >> t;
		v.setNum(t);
		v.setStr(t);
	}
} _LANG_V_BLANK;

class _LANG_F {
private:
	_LANG_V v;

public:
	_LANG_F() {
	}

	friend _LANG_V operator%(_LANG_F& c, _LANG_V(*f)(_LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V, _LANG_V)) {
		c.v = f(_LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK, _LANG_V_BLANK);
		return c.v;
	}

	friend _LANG_V operator%(_LANG_F& c, const _LANG_V& r) {
		c.v = r;
		return c.v;
	}

	operator _LANG_V() const {
		return v;
	}

} _LANG_F_CALLER;

#define FUNC ; _LANG_V
#define IS (_LANG_V $1 = _LANG_V_BLANK,\
			_LANG_V $2 = _LANG_V_BLANK,\
			_LANG_V $3 = _LANG_V_BLANK,\
			_LANG_V $4 = _LANG_V_BLANK,\
			_LANG_V $5 = _LANG_V_BLANK,\
			_LANG_V $6 = _LANG_V_BLANK,\
			_LANG_V $7 = _LANG_V_BLANK,\
			_LANG_V $8 = _LANG_V_BLANK,\
			_LANG_V $9 = _LANG_V_BLANK,\
			_LANG_V $10 = _LANG_V_BLANK,\
			_LANG_V $11 = _LANG_V_BLANK,\
			_LANG_V $12 = _LANG_V_BLANK,\
			_LANG_V $13 = _LANG_V_BLANK,\
			_LANG_V $14 = _LANG_V_BLANK,\
			_LANG_V $15 = _LANG_V_BLANK,\
			_LANG_V $16 = _LANG_V_BLANK) {
#define RETURN ; return
#define END ; return _LANG_V_BLANK; }

#define VAR ; _LANG_V
#define SET ;
#define TO =
#define READ ; std::cin >>
#define PRINT ; std::cout <<

#define IF ; if (
#define THEN ) {
#define ELIF ; } else if (
#define ELSE ; } else {
#define ENDIF ; }

#define EQ ==
#define NE !=
#define GT >
#define GE >=
#define LT <
#define LE <=
#define AND &&
#define OR ||
#define NOT !

#define GOTO ; _LANG_F_CALLER %
#define CALL _LANG_F_CALLER %

#endif /* LANG_H_ */
