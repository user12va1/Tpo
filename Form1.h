#pragma once
#include "check.h"
namespace My123 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  coordx;
	private: System::Windows::Forms::TextBox^  coordy;
	protected: 



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  answer;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->coordx = (gcnew System::Windows::Forms::TextBox());
			this->coordy = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->answer = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Check";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// coordx
			// 
			this->coordx->ForeColor = System::Drawing::SystemColors::WindowText;
			this->coordx->Location = System::Drawing::Point(12, 12);
			this->coordx->Name = L"coordx";
			this->coordx->Size = System::Drawing::Size(100, 20);
			this->coordx->TabIndex = 2;
			// 
			// coordy
			// 
			this->coordy->Location = System::Drawing::Point(138, 12);
			this->coordy->Name = L"coordy";
			this->coordy->Size = System::Drawing::Size(100, 20);
			this->coordy->TabIndex = 3;
			this->coordy->TextChanged += gcnew System::EventHandler(this, &Form1::coordy_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(135, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Y Coord";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"X Coord";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// answer
			// 
			this->answer->Location = System::Drawing::Point(12, 115);
			this->answer->Name = L"answer";
			this->answer->Size = System::Drawing::Size(226, 20);
			this->answer->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(138, 65);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Open file";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"Текстовые файлы (*.txt)|*.txt";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(283, 279);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->answer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->coordy);
			this->Controls->Add(this->coordx);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 double x,y;
				 int result,err;
				 try{
					 x = System::Convert::ToDouble(coordx->Text);
					 y = System::Convert::ToDouble(coordy->Text);	 
				 }
				 catch (...)
				 {
					 MessageBox::Show("Некорректный формат данных. Требуется: x,x y,y");
					 err=1;
				 }

				 result=check(x,y,err);

				 if (result==0)
					 answer->Text="Принадлежит области";
				 if (result==1)
					 answer->Text="На границе области";
				 if (result==2)
					 answer->Text="Не принадлежит области";
				 if (result==4)
					 answer->Text="Ошибка";
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 double x,y;
					 int result,err;
					 System::String^ cx;
					 System::String^ cy;
					 System::IO::StreamReader ^ sr = gcnew
						 System::IO::StreamReader(openFileDialog1->FileName);
					 try
					 {
						 cx= sr->ReadLine();
						 cy= sr->ReadLine();
						 coordx->Text=cx;
						 coordy->Text=cy;
						 x = System::Convert::ToDouble(cx);
						 y = System::Convert::ToDouble(cy); 
					 }
					 catch (...)
					 {
						 MessageBox::Show("Некорректный вид файла. Убеитесь в том, что файл имеет вид x,x[следующая строка]y,y");
						 err=1;
					 }
					 
					 result=check(x,y,err);

					 if (result==0)
						 answer->Text="Принадлежит области";
					 if (result==1)
						 answer->Text="На границе области";
					 if (result==2)
						 answer->Text="Не принадлежит области";
					 if (result==4)
						 answer->Text="Ошибка";

					 //				 MessageBox::Show(cx);
					 sr->Close();
				 }
			 }
	private: System::Void coordy_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}

