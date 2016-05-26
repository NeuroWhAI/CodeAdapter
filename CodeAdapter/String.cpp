#include "String.h"




BEGIN_NAMESPACE_CA_UTILITY


String::String()
{

}


String::String(const String& other)
	: m_str(other.m_str)
	, m_wstr(other.m_wstr)
{

}


String::String(String&& rhs)
	: m_str(std::move(rhs.m_str))
	, m_wstr(std::move(rhs.m_wstr))
{

}


String::String(const char str[])
{
	setStr(str);
}


String::String(const std::string& str)
{
	setStr(str);
}


String::String(const wchar_t wstr[])
{
	setStr(wstr);
}


String::String(const std::wstring& wstr)
{
	setStr(wstr);
}


String::~String()
{

}

//###########################################################################

void String::updateStr()
{
	m_str.assign(m_wstr.begin(), m_wstr.end());
}

//###########################################################################

const char* String::getStr() const
{
	return m_str.c_str();
}


void String::getStr(std::string* pOut) const
{
	*pOut = m_str;
}

//--------------------------------------------------------------------------

const wchar_t* String::getWStr() const
{
	return m_wstr.c_str();
}


void String::getStr(std::wstring* pOut) const
{
	*pOut = m_wstr;
}

//###########################################################################

void String::setStr(const std::string& str)
{
	m_wstr.assign(str.begin(), str.end());

	updateStr();
}


void String::setStr(const std::wstring& wstr)
{
	m_wstr = wstr;

	updateStr();
}

//--------------------------------------------------------------------------

void String::addStr(const std::string& str)
{
	std::wstring temp;
	temp.assign(str.begin(), str.end());
	m_wstr += temp;

	updateStr();
}


void String::addStr(const std::wstring& wstr)
{
	m_wstr += wstr;

	updateStr();
}

//--------------------------------------------------------------------------

void String::addChar(char ch)
{
	addStr(std::string({ ch }));
}


void String::addChar(wchar_t wch)
{
	addStr(std::wstring({ wch }));
}

//--------------------------------------------------------------------------

void String::InsertStr(const std::string& str, i32 index)
{
	std::wstring temp;
	temp.assign(str.begin(), str.end());
	m_wstr.insert(index, temp);

	updateStr();
}


void String::InsertStr(const std::wstring& wstr, i32 index)
{
	m_wstr.insert(index, wstr);

	updateStr();
}

//--------------------------------------------------------------------------

void String::InsertChar(char ch, i32 index)
{
	InsertStr(std::string({ ch }), index);
}


void String::InsertChar(wchar_t wch, i32 index)
{
	InsertStr(std::wstring({ wch }), index);
}

//--------------------------------------------------------------------------

void String::eraseAt(i32 index)
{
	m_wstr.erase(index, 1);

	updateStr();
}


void String::eraseRange(i32 begin, i32 count)
{
	m_wstr.erase(begin, count);

	updateStr();
}


void String::eraseToEnd(i32 begin)
{
	m_wstr.erase(begin);

	updateStr();
}

//###########################################################################

i32 String::getLength() const
{
	return static_cast<i32>(m_wstr.length());
}

//###########################################################################

String::operator std::string() const
{
	return m_str;
}


String::operator std::wstring() const
{
	return m_wstr;
}

//--------------------------------------------------------------------------

String& String::operator= (const String& right)
{
	m_str = right.m_str;
	m_wstr = right.m_wstr;
	return *this;
}


String String::operator+ (const String& right) const
{
	String temp = *this;
	temp.addStr(right.m_wstr);
	return temp;
}


String& String::operator+= (const String& right)
{
	addStr(right.m_wstr);
	return *this;
}

//--------------------------------------------------------------------------

bool String::operator== (const String& right) const
{
	return (m_wstr == right.m_wstr);
}


bool String::operator== (const std::string& right) const
{
	return (m_str == right);
}


bool String::operator== (const std::wstring& right) const
{
	return (m_wstr == right);
}


bool String::operator!= (const String& right) const
{
	return (m_wstr != right.m_wstr);
}


bool String::operator!= (const std::string& right) const
{
	return (m_str != right);
}


bool String::operator!= (const std::wstring& right) const
{
	return (m_wstr != right);
}


END_NAMESPACE_CA_UTILITY


CodeAdapter::Utility::String operator+ (const std::string& left,
	const CodeAdapter::Utility::String& right)
{
	CodeAdapter::Utility::String temp = left;
	temp.addStr(right.getStr());

	return temp;
}


CodeAdapter::Utility::String operator+ (const std::wstring& left,
	const CodeAdapter::Utility::String& right)
{
	CodeAdapter::Utility::String temp = left;
	temp.addStr(right.getWStr());

	return temp;
}

//--------------------------------------------------------------------------

bool operator== (const std::string& left,
	const CodeAdapter::Utility::String& right)
{
	return (right == left);
}


bool operator== (const std::wstring& left,
	const CodeAdapter::Utility::String& right)
{
	return (right == left);
}


bool operator!= (const std::string& left,
	const CodeAdapter::Utility::String& right)
{
	return (right != left);
}


bool operator!= (const std::wstring& left,
	const CodeAdapter::Utility::String& right)
{
	return (right != left);
}

