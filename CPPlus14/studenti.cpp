#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average() const
{
	//调用父类的方法
	if (ArrayDb::size()>0)
	{
		return ArrayDb::sum() / ArrayDb::size();
	}
	else 
	{
		return 0;
	}
}
/// <summary>
/// 返回姓名，因为没有使用组合，所以只能这样，
/// Student类继承了string,所以可以把它当做string来用
/// </summary>
/// <returns></returns>
const string& Student::Name() const
{
	return (const string &)*this;
}
/// <summary>
/// 重载运算符 调用父类的方法，原因是私有继承，Student 将父类
/// 成员都弄成了自己的私有的，所以通过这种方式来开放父类接口
/// </summary>
/// <param name="i"></param>
/// <returns></returns>
double& Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

//私有方法  数组输出
ostream& Student::arr_out(ostream& os) const
{
	int i;
	int lim = ArrayDb::size();
	if (lim>0)
	{
		for ( i = 0; i < lim; i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i%5==4)
			{
				os << endl;
			}
		}
		if (i%5!=0)
		{
			os << endl;
		}
	}
	else
	{
		os << " empty array ";
	}

	return os;
}

//友元
istream& operator>>(istream& is, Student& stu)
{
	//强制类型转换成string,当string来使用
	is >> (string&)stu;
	return is;
}

istream& getline(istream& is, Student& stu)
{
	getline(is, (string &)stu);
	return is;
}

ostream & operator<<(ostream & os,const Student & stu)
{
	//强制类型转换成string,当string来使用
	os << "Scores for " << (const string&)stu << ":\n";
	stu.arr_out(os);
	return os;
}
