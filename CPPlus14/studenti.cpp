#include "studenti.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

double Student::Average() const
{
	//���ø���ķ���
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
/// ������������Ϊû��ʹ����ϣ�����ֻ��������
/// Student��̳���string,���Կ��԰�������string����
/// </summary>
/// <returns></returns>
const string& Student::Name() const
{
	return (const string &)*this;
}
/// <summary>
/// ��������� ���ø���ķ�����ԭ����˽�м̳У�Student ������
/// ��Ա��Ū�����Լ���˽�еģ�����ͨ�����ַ�ʽ�����Ÿ���ӿ�
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

//˽�з���  �������
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

//��Ԫ
istream& operator>>(istream& is, Student& stu)
{
	//ǿ������ת����string,��string��ʹ��
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
	//ǿ������ת����string,��string��ʹ��
	os << "Scores for " << (const string&)stu << ":\n";
	stu.arr_out(os);
	return os;
}
