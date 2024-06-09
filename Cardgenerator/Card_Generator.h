#pragma once

namespace CardGenerator {

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::IO;
	using namespace CardGenerator;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	public ref class Card_Generator : public System::Windows::Forms::Form
	{
	public:
		Card_Generator(void)
		{
			InitializeComponent();

			button1->Click += gcnew EventHandler(this, &Card_Generator::button1_Click);
			this->WindowState = FormWindowState::Maximized; // Устанавливаем окно в полноэкранный режим
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // Убираем рамку окна
		}

	protected:

		~Card_Generator()
		{
			if (components)
			{
				delete components;
			}

		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::PictureBox^ Card_1;
	private: System::Windows::Forms::PictureBox^ Card_2;
	private: System::Windows::Forms::PictureBox^ Card_3;
	private: System::Windows::Forms::PictureBox^ Card_4;
	private: System::Windows::Forms::PictureBox^ Card_5;
	private: System::Windows::Forms::PictureBox^ Card_6;
	private: System::Windows::Forms::PictureBox^ Card_7;
	private: System::Windows::Forms::PictureBox^ Card_8;
	private: System::Windows::Forms::PictureBox^ Card_9;



	protected:

		System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Card_Generator::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Card_1 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_2 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_3 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_4 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_5 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_6 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_7 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_8 = (gcnew System::Windows::Forms::PictureBox());
			this->Card_9 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_9))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(-4, -5);
			this->button1->Margin = System::Windows::Forms::Padding(0);
			this->button1->MinimumSize = System::Drawing::Size(45, 49);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 148);
			this->button1->TabIndex = 0;
			this->button1->UseMnemonic = false;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Card_Generator::button1_Click);
			this->button1->FlatAppearance->MouseOverBackColor = this->button1->BackColor;
			this->button1->FlatAppearance->MouseDownBackColor = this->button1->BackColor; 
			// 
			// button2
			// 
			this->button2->AutoSize = true;
			this->button2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(115, 116);
			this->button2->Margin = System::Windows::Forms::Padding(0);
			this->button2->MinimumSize = System::Drawing::Size(75, 81);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(106, 106);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Card_Generator::button2_Click);
			this->button2->FlatAppearance->MouseOverBackColor = this->button2->BackColor;
			this->button2->FlatAppearance->MouseDownBackColor = this->button2->BackColor;
			// 
			// button3
			// 
			this->button3->AutoSize = true;
			this->button3->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(115, 296);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->MinimumSize = System::Drawing::Size(75, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 106);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Card_Generator::button3_Click);
			this->button3->FlatAppearance->MouseOverBackColor = this->button3->BackColor;
			this->button3->FlatAppearance->MouseDownBackColor = this->button3->BackColor;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Impact", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(783, 16);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Неразменная колода";
			this->label1->Click += gcnew System::EventHandler(this, &Card_Generator::label1_Click);
			// 
			// Card_1
			// 
			this->Card_1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_1.Image")));
			this->Card_1->Location = System::Drawing::Point(252, 14);
			this->Card_1->Name = L"Card_1";
			this->Card_1->Size = System::Drawing::Size(157, 234);
			this->Card_1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_1->TabIndex = 6;
			this->Card_1->TabStop = false;
			// 
			// Card_2
			// 
			this->Card_2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_2.Image")));
			this->Card_2->Location = System::Drawing::Point(432, 14);
			this->Card_2->Name = L"Card_2";
			this->Card_2->Size = System::Drawing::Size(157, 234);
			this->Card_2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_2->TabIndex = 7;
			this->Card_2->TabStop = false;
			// 
			// Card_3
			// 
			this->Card_3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_3.Image")));
			this->Card_3->Location = System::Drawing::Point(613, 14);
			this->Card_3->Name = L"Card_3";
			this->Card_3->Size = System::Drawing::Size(157, 234);
			this->Card_3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_3->TabIndex = 8;
			this->Card_3->TabStop = false;
			// 
			// Card_4
			// 
			this->Card_4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_4.Image")));
			this->Card_4->Location = System::Drawing::Point(252, 263);
			this->Card_4->Name = L"Card_4";
			this->Card_4->Size = System::Drawing::Size(157, 234);
			this->Card_4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_4->TabIndex = 9;
			this->Card_4->TabStop = false;
			// 
			// Card_5
			// 
			this->Card_5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_5.Image")));
			this->Card_5->Location = System::Drawing::Point(432, 263);
			this->Card_5->Name = L"Card_5";
			this->Card_5->Size = System::Drawing::Size(157, 234);
			this->Card_5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_5->TabIndex = 10;
			this->Card_5->TabStop = false;
			// 
			// Card_6
			// 
			this->Card_6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_6.Image")));
			this->Card_6->Location = System::Drawing::Point(613, 263);
			this->Card_6->Name = L"Card_6";
			this->Card_6->Size = System::Drawing::Size(157, 234);
			this->Card_6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_6->TabIndex = 11;
			this->Card_6->TabStop = false;
			// 
			// Card_7
			// 
			this->Card_7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_7.Image")));
			this->Card_7->Location = System::Drawing::Point(252, 512);
			this->Card_7->Name = L"Card_7";
			this->Card_7->Size = System::Drawing::Size(157, 234);
			this->Card_7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_7->TabIndex = 12;
			this->Card_7->TabStop = false;
			// 
			// Card_8
			// 
			this->Card_8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_8.Image")));
			this->Card_8->Location = System::Drawing::Point(432, 512);
			this->Card_8->Name = L"Card_8";
			this->Card_8->Size = System::Drawing::Size(157, 234);
			this->Card_8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_8->TabIndex = 13;
			this->Card_8->TabStop = false;
			// 
			// Card_9
			// 
			this->Card_9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Card_9.Image")));
			this->Card_9->Location = System::Drawing::Point(613, 512);
			this->Card_9->Name = L"Card_9";
			this->Card_9->Size = System::Drawing::Size(157, 234);
			this->Card_9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->Card_9->TabIndex = 14;
			this->Card_9->TabStop = false;
			this->Card_9->Click += gcnew System::EventHandler(this, &Card_Generator::Card_9_Click);
			// 
			// Card_Generator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(981, 687);
			this->Controls->Add(this->Card_9);
			this->Controls->Add(this->Card_8);
			this->Controls->Add(this->Card_7);
			this->Controls->Add(this->Card_6);
			this->Controls->Add(this->Card_5);
			this->Controls->Add(this->Card_4);
			this->Controls->Add(this->Card_3);
			this->Controls->Add(this->Card_2);
			this->Controls->Add(this->Card_1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Card_Generator";
			this->Text = L"Card_Generator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card_9))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		// Обработчик события click для кнопки exit
		void button1_Click(Object^ sender, EventArgs^ e) override;


		// Обработчик события click для кнопки save
		void button3_Click(Object^ sender, EventArgs^ e) override;


		// Обработчик события click для кнопки generate
		void button2_Click(Object^ sender, EventArgs^ e) override;


#pragma endregion
	private: System::Void Card_9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	/*private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}*/
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}