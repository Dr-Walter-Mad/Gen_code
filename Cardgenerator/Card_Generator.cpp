#include "Card_Generator.h"
#include <vcclr.h> // Для работы с управляемыми типами
#include <msclr/marshal_cppstd.h> // Для преобразования строк

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


// Обработчик события click для кнопки exit
void Card_Generator::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close(); // Выключаем приложение
}


// Обработчик события click для кнопки save
void Card_Generator::button3_Click(Object^ sender, EventArgs^ e)
{
	// Создание папки для сохранения сгенерированных карт, если она не существует
	String^ saveFolderPath = Path::Combine(Application::StartupPath, "SavedCards");
	if (!Directory::Exists(saveFolderPath))
		Directory::CreateDirectory(saveFolderPath);

	// Определение ширины и высоты каждой карты
	int cardWidth = 0;
	int cardHeight = 0;
	List<Bitmap^>^ bitmaps = gcnew List<Bitmap^>();

	// Цикл по всем PictureBox сгенерированных карт
	for (int i = 1; i <= 9; i++)
	{
		PictureBox^ currentPictureBox = safe_cast<PictureBox^>(this->Controls["Card_" + Convert::ToString(i)]);
		if (currentPictureBox != nullptr && currentPictureBox->BackgroundImage != nullptr)
		{
			// Создание битмапа для текущего PictureBox
			Bitmap^ bitmap = gcnew Bitmap(currentPictureBox->Width, currentPictureBox->Height);
			currentPictureBox->DrawToBitmap(bitmap, System::Drawing::Rectangle(0, 0, currentPictureBox->Width, currentPictureBox->Height));
			bitmaps->Add(bitmap);

			// Обновление общей ширины и высоты каждой карты
			cardWidth = bitmap->Width;
			cardHeight = bitmap->Height;
		}
	}

	// Вычисление размеров листа сеткой 3 на 3
	int gridWidth = cardWidth * 3;
	int gridHeight = cardHeight * 3;

	// Создание битмапа для листа
	Bitmap^ finalBitmap = gcnew Bitmap(gridWidth, gridHeight);
	Graphics^ graphics = Graphics::FromImage(finalBitmap);

	// Наложение каждой карты на лист в сетке 3 на 3
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
	
// Генерация уникального имени файла для сохранения, основываясь на количестве файлов в директории
	String^ fileNameBase = "Card_";
	array<String^>^ files = Directory::GetFiles(saveFolderPath, fileNameBase + "*.png");
	int fileNumber = files->Length; // Нумерация должна начинаться с 1, если в папке нет файлов
	String^ fileName = Path::Combine(saveFolderPath, fileNameBase + fileNumber.ToString() + ".png");

	// Сохранение изображения листа в файл
	finalBitmap->Save(fileName, System::Drawing::Imaging::ImageFormat::Png);
	


	/*// Генерация уникального имени файла для сохранения
	String^ fileName = Path::Combine(saveFolderPath, "All_Cards.png");

	// Сохранение изображения листа в файл
	finalBitmap->Save(fileName, System::Drawing::Imaging::ImageFormat::Png);*/

	// Освобождение ресурсов
	delete finalBitmap;

	// Освобождение ресурсов битмапов
	for each (Bitmap ^ bitmap in bitmaps)
		delete bitmap;

	// Сообщение пользователю о завершении сохранения
	MessageBox::Show("Все карты успешно сохранены на одном листе", "Сохранение", MessageBoxButtons::OK, MessageBoxIcon::Information);
}



// Обработчик события click для кнопки generate
void Card_Generator::button2_Click(Object^ sender, EventArgs^ e)
{
	// Получение пути к папкам с изображениями
	String^ imagesPathBack = Path::Combine(Application::StartupPath, "ImagesBack");
	String^ imagesPathNumber = Path::Combine(Application::StartupPath, "ImagesText");
	String^ imagesPathShape = Path::Combine(Application::StartupPath, "ImagesShape");

	// Создание экземпляра генератора случайных чисел
	Random^ rand = gcnew Random();

	// Генерация изображений для 9-и PictureBox
	for (int i = 1; i <= 9; i++)
	{
		// Генерация случайного индекса для изображений фона
		int indexBack = rand->Next(Directory::GetFiles(imagesPathBack)->Length);
		String^ imageNameBack = Path::Combine(imagesPathBack, indexBack + ".png");

		// Генерация случайного индекса для изображений текста
		int indexNumber = rand->Next(Directory::GetFiles(imagesPathNumber)->Length);
		String^ imageNameNumber = Path::Combine(imagesPathNumber, indexNumber + ".png");

		// Генерация случайного индекса для изображений формы
		int indexShape = rand->Next(Directory::GetFiles(imagesPathShape)->Length);
		String^ imageNameShape = Path::Combine(imagesPathShape, indexShape + ".png");

		// Получение текущего PictureBox по имени
		PictureBox^ currentPictureBox = safe_cast<PictureBox^>(this->Controls["Card_" + Convert::ToString(i)]);

		if (currentPictureBox != nullptr)
		{
			// Очистка старых элементов PictureBox и Label
			currentPictureBox->Controls->Clear();

			// Установка фона текущему PictureBox
			currentPictureBox->BackgroundImage = Image::FromFile(imageNameBack);
			currentPictureBox->BackgroundImageLayout = ImageLayout::Stretch;

			// Создание и установка PictureBox для изображения формы
			PictureBox^ backPictureBox = gcnew PictureBox();
			backPictureBox->Image = Image::FromFile(imageNameBack);
			backPictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // Используйте растяжение изображения, чтобы оно соответствовало размеру PictureBox
			backPictureBox->Size = currentPictureBox->Size; // Установите размер таким же, как у текущего PictureBox
			backPictureBox->Location = Point(0, 0); // Позиционируйте в левом верхнем углу текущего PictureBox
			backPictureBox->BackColor = Color::Transparent;
			currentPictureBox->Controls->Add(backPictureBox);

			// Создание и установка PictureBox для изображения формы
			PictureBox^ shapePictureBox = gcnew PictureBox();
			shapePictureBox->Image = Image::FromFile(imageNameShape);
			shapePictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // Используйте растяжение изображения, чтобы оно соответствовало размеру PictureBox
			shapePictureBox->Size = backPictureBox->Size; // Установите размер таким же, как у текущего PictureBox
			shapePictureBox->Location = Point(0, 0); // Позиционируйте в левом верхнем углу текущего PictureBox
			shapePictureBox->BackColor = Color::Transparent;
			backPictureBox->Controls->Add(shapePictureBox);

			// Создание и установка PictureBox для изображения текста
			PictureBox^ numberPictureBox = gcnew PictureBox();
			numberPictureBox->Image = Image::FromFile(imageNameNumber);
			numberPictureBox->SizeMode = PictureBoxSizeMode::StretchImage; // Используйте растяжение изображения, чтобы оно соответствовало размеру PictureBox
			numberPictureBox->Size = shapePictureBox->Size; // Установите размер таким же, как у shapePictureBox
			numberPictureBox->Location = Point(0, 0); // Позиционируйте в левом верхнем углу shapePictureBox
			numberPictureBox->BackColor = Color::Transparent;
			shapePictureBox->Controls->Add(numberPictureBox); // Добавьте numberPictureBox как контрол к shapePictureBox



		}
	}
}


