#include "Card_Generator.h"
#include <vcclr.h> // ��� ������ � ������������ ������
#include <msclr/marshal_cppstd.h> // ��� �������������� �����

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace CardGenerator;


[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	CardGenerator::Card_Generator form;
	Application::Run(% form);
	String^ imagesPath = Path::Combine(Application::StartupPath, "Images");

}


// ���������� ������� click ��� ������ exit
void Card_Generator::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close(); // ��������� ����������
}


// ���������� ������� click ��� ������ save
void Card_Generator::button3_Click(Object^ sender, EventArgs^ e)
{
	// �������� ����� ��� ���������� ��������������� ����, ���� ��� �� ����������
	String^ saveFolderPath = Path::Combine(Application::StartupPath, "SavedCards");
	if (!Directory::Exists(saveFolderPath))
		Directory::CreateDirectory(saveFolderPath);

	// ����������� ������ � ������ ������ �����
	int cardWidth = 0;
	int cardHeight = 0;
	List<Bitmap^>^ bitmaps = gcnew List<Bitmap^>();

	// ���� �� ���� PictureBox ��������������� ����
	for (int i = 1; i <= 9; i++)
	{
		PictureBox^ currentPictureBox = safe_cast<PictureBox^>(this->Controls["Card_" + Convert::ToString(i)]);
		if (currentPictureBox != nullptr && currentPictureBox->BackgroundImage != nullptr)
		{
			// �������� ������� ��� �������� PictureBox
			Bitmap^ bitmap = gcnew Bitmap(currentPictureBox->Width, currentPictureBox->Height);
			currentPictureBox->DrawToBitmap(bitmap, System::Drawing::Rectangle(0, 0, currentPictureBox->Width, currentPictureBox->Height));
			bitmaps->Add(bitmap);

			// ���������� ����� ������ � ������ ������ �����
			cardWidth = bitmap->Width;
			cardHeight = bitmap->Height;
		}
	}

	// ���������� �������� ����� ������ 3 �� 3
	int gridWidth = cardWidth * 3;
	int gridHeight = cardHeight * 3;

	// �������� ������� ��� �����
	Bitmap^ finalBitmap = gcnew Bitmap(gridWidth, gridHeight);
	Graphics^ graphics = Graphics::FromImage(finalBitmap);

	// ��������� ������ ����� �� ���� � ����� 3 �� 3
	int index = 0;
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (index < bitmaps->Count)
			{
				Bitmap^ bitmap = bitmaps[index];
				graphics->DrawImage(bitmap, col * cardWidth, row * cardHeight);
				index++;
			}
		}
	}
	
// ��������� ����������� ����� ����� ��� ����������, ����������� �� ���������� ������ � ����������
	String^ fileNameBase = "Card_";
	array<String^>^ files = Directory::GetFiles(saveFolderPath, fileNameBase + "*.png");
	int fileNumber = files->Length; // ��������� ������ ���������� � 1, ���� � ����� ��� ������
	String^ fileName = Path::Combine(saveFolderPath, fileNameBase + fileNumber.ToString() + ".png");

	// ���������� ����������� ����� � ����
	finalBitmap->Save(fileName, System::Drawing::Imaging::ImageFormat::Png);
	


	/*// ��������� ����������� ����� ����� ��� ����������
	String^ fileName = Path::Combine(saveFolderPath, "All_Cards.png");

	// ���������� ����������� ����� � ����
	finalBitmap->Save(fileName, System::Drawing::Imaging::ImageFormat::Png);*/

	// ������������ ��������
	delete finalBitmap;

	// ������������ �������� ��������
	for each (Bitmap ^ bitmap in bitmaps)
		delete bitmap;

	// ��������� ������������ � ���������� ����������
	MessageBox::Show("��� ����� ������� ��������� �� ����� �����", "����������", MessageBoxButtons::OK, MessageBoxIcon::Information);
}



// ���������� ������� click ��� ������ generate
void Card_Generator::button2_Click(Object^ sender, EventArgs^ e)
{
	// ��������� ���� � ������ � �������������
	String^ imagesPathBack = Path::Combine(Application::StartupPath, "ImagesBack");
	String^ imagesPathNumber = Path::Combine(Application::StartupPath, "ImagesText");
	String^ imagesPathShape = Path::Combine(Application::StartupPath, "ImagesShape");

	// �������� ���������� ���������� ��������� �����
	Random^ rand = gcnew Random();

	// ��������� ����������� ��� 9-� PictureBox
	for (int i = 1; i <= 9; i++)
	{
		// ��������� ���������� ������� ��� ����������� ����
		int indexBack = rand->Next(Directory::GetFiles(imagesPathBack)->Length);
		String^ imageNameBack = Path::Combine(imagesPathBack, indexBack + ".png");

		// ��������� ���������� ������� ��� ����������� ������
		int indexNumber = rand->Next(Directory::GetFiles(imagesPathNumber)->Length);
		String^ imageNameNumber = Path::Combine(imagesPathNumber, indexNumber + ".png");

		// ��������� ���������� ������� ��� ����������� �����
		int indexShape = rand->Next(Directory::GetFiles(imagesPathShape)->Length);
		String^ imageNameShape = Path::Combine(imagesPathShape, indexShape + ".png");

		// ��������� �������� PictureBox �� �����
		PictureBox^ currentPictureBox = safe_cast<PictureBox^>(this->Controls["Card_" + Convert::ToString(i)]);

		if (currentPictureBox != nullptr)
		{
			// ������� ������ ��������� PictureBox � Label
			currentPictureBox->Controls->Clear();

			// ��������� ���� �������� PictureBox
			currentPictureBox->BackgroundImage = Image::FromFile(imageNameBack);
			currentPictureBox->BackgroundImageLayout = ImageLayout::Stretch;

			// �������� � ��������� PictureBox ��� ����������� �����
			PictureBox^ backPictureBox = gcnew PictureBox();
			backPictureBox->Image = Image::FromFile(imageNameBack);
			backPictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // ����������� ���������� �����������, ����� ��� ��������������� ������� PictureBox
			backPictureBox->Size = currentPictureBox->Size; // ���������� ������ ����� ��, ��� � �������� PictureBox
			backPictureBox->Location = Point(0, 0); // �������������� � ����� ������� ���� �������� PictureBox
			backPictureBox->BackColor = Color::Transparent;
			currentPictureBox->Controls->Add(backPictureBox);

			// �������� � ��������� PictureBox ��� ����������� �����
			PictureBox^ shapePictureBox = gcnew PictureBox();
			shapePictureBox->Image = Image::FromFile(imageNameShape);
			shapePictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // ����������� ���������� �����������, ����� ��� ��������������� ������� PictureBox
			shapePictureBox->Size = backPictureBox->Size; // ���������� ������ ����� ��, ��� � �������� PictureBox
			shapePictureBox->Location = Point(0, 0); // �������������� � ����� ������� ���� �������� PictureBox
			shapePictureBox->BackColor = Color::Transparent;
			backPictureBox->Controls->Add(shapePictureBox);

			// �������� � ��������� PictureBox ��� ����������� ������
			PictureBox^ numberPictureBox = gcnew PictureBox();
			numberPictureBox->Image = Image::FromFile(imageNameNumber);
			numberPictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // ����������� ���������� �����������, ����� ��� ��������������� ������� PictureBox
			numberPictureBox->Size = shapePictureBox->Size; // ���������� ������ ����� ��, ��� � shapePictureBox
			numberPictureBox->Location = Point(0, 0); // �������������� � ����� ������� ���� shapePictureBox
			numberPictureBox->BackColor = Color::Transparent;
			shapePictureBox->Controls->Add(numberPictureBox); // �������� numberPictureBox ��� ������� � shapePictureBox



		}
	}
}


