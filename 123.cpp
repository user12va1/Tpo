// 123.cpp: ������� ���� �������.

#include "stdafx.h"
#include "Form1.h"
#include "check.h"
using namespace My123;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// ��������� ���������� �������� Windows XP �� �������� �����-���� ��������� ����������
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// �������� �������� ���� � ��� ������
	Application::Run(gcnew Form1());


	return 0;
}
