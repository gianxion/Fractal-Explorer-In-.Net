#pragma once
#include <complex>
#include <vector>
#include "myHeader.h"

namespace FractalExplorer {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	bool unzoom = false; // for the ctrl button
	int maxIt = 100;

	vec3 NovaPalet[17] = {
		vec3(0.0, 0.0, 0.0),
		vec3(66.3, 45.9, 15.3),
		vec3(25.5, 7.65, 25.5),
		vec3(10.2, 0.0,  45.9),
		vec3(5.1, 5.1, 73.95),
		vec3(0.0,  7.65, 99.45),
		vec3(12.75, 43.35, 137.7),
		vec3(22.95, 81.6, 175.95),
		vec3(56.1, 124.95, 209.1),
		vec3(132.6, 181.05, 229.5),
		vec3(209.1, 234.6, 247.35),
		vec3(239.7, 232.05, 191.25),
		vec3(247.35, 201.45, 94.35),
		vec3(255,  170.85, 0.0),
		vec3(204,  127.5,  0.0),
		vec3(153,  86.7, 0.0),
		vec3(104.55, 51,  2.55)
	};

	vec3 PhoenixPalet[17] = {
		vec3(0, 0, 0),
		vec3(176.995, 7.0125, 176.995),
		vec3(33.9915, 36.006, 27.999),
		vec3(31.008, 51, 26.01),
		vec3(8.007, 167.994, 8.007),
		vec3(144.993, 194.004, 32.997),
		vec3(227.995, 223.992, 13.005),
		vec3(22.95, 81.6, 175.95),
		vec3(56.1, 124.95, 209.1),
		vec3(38.9895, 65.994, 222.997),
		vec3(107.993, 8.007, 240.006),
		vec3(204, 52.989, 52.989),
		vec3(255, 0, 0),
		vec3(255, 0, 128.01),
		vec3(237.992, 0, 205.989),
		vec3(144.993, 9.0015, 144.993),
		vec3(89.9895, 0.9945, 86.0115)
	};

	vec3 MandelPalet[17] = {
		vec3(0, 0, 0),
		vec3(255, 0, 170.008),
		vec3(255, 217.005, 0),
		vec3(199.997, 255, 0),
		vec3(8.007, 167.994, 8.007),
		vec3(0, 255, 55.0035),
		vec3(0, 236.002, 125.995),
		vec3(0, 255, 199.997),
		vec3(0, 255, 199.997),
		vec3(0, 255, 241.995),
		vec3(0, 174.012, 255),
		vec3(0, 88.995, 255),
		vec3(0, 37.995, 255),
		vec3(153, 0, 255),
		vec3(204, 0, 255),
		vec3(255, 0, 179.01),
		vec3(255, 0, 0)
	};

	vec3 BurningPalet[17] = {
		vec3(0, 0, 0),
		vec3(120.997, 23.9955, 0),
		vec3(129.005, 96.0075, 35.0115),
		vec3(154.989, 106.998, 4.998),
		vec3(161.007, 130.993, 29.988),
		vec3(228.99, 255, 0),
		vec3(236.002, 219.988, 0),
		vec3(255, 250.997, 0),
		vec3(255, 195.993, 0),
		vec3(250.002, 191.99, 0),
		vec3(253.011, 121.992, 0),
		vec3(221.008, 106.998, 0),
		vec3(167.994, 101.006, 0),
		vec3(149.991, 69.003, 1.989),
		vec3(140.99, 63.0105, 0),
		vec3(97.002, 46.9965, 0),
		vec3(120.997, 23.9955, 0)
	};

	double mouseX = 0;
	double mouseY = 0;
	double min_re = -2.5, max_re = 1.0;
	double min_im = -1.0, max_im = 1.0;

	double zoom = 3.0;
	int nthP = 3;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ Fractals;
	private: System::Windows::Forms::TextBox^ MaxIter;
	private: System::Windows::Forms::Button^ Btn_Iter;
	private: System::Windows::Forms::Label^ Iter_Label;
	private: System::Windows::Forms::TextBox^ zoomFactor;
	private: System::Windows::Forms::TextBox^ nthPower;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnNth;
	private: System::Windows::Forms::Label^ zooming;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ realBox;
	private: System::Windows::Forms::TextBox^ imagBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btn_Help;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->Fractals = (gcnew System::Windows::Forms::Label());
			this->MaxIter = (gcnew System::Windows::Forms::TextBox());
			this->Btn_Iter = (gcnew System::Windows::Forms::Button());
			this->Iter_Label = (gcnew System::Windows::Forms::Label());
			this->zoomFactor = (gcnew System::Windows::Forms::TextBox());
			this->nthPower = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnNth = (gcnew System::Windows::Forms::Button());
			this->zooming = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->realBox = (gcnew System::Windows::Forms::TextBox());
			this->imagBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btn_Help = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(30, 73);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 512);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::PictureBox1_DoubleClick);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PictureBox1_MouseClick);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Mandelbrot", L"Julia", L"Burning ship", L"Newton",
					L"Phoenix", L"Nova", L"DouadyRabbit", L"Multibrot"
			});
			this->comboBox1->Location = System::Drawing::Point(548, 89);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox1_SelectedIndexChanged);
			// 
			// Fractals
			// 
			this->Fractals->AutoSize = true;
			this->Fractals->Location = System::Drawing::Point(590, 73);
			this->Fractals->Name = L"Fractals";
			this->Fractals->Size = System::Drawing::Size(44, 13);
			this->Fractals->TabIndex = 2;
			this->Fractals->Text = L"Fractals";
			this->Fractals->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::Fractals_PreviewKeyDown);
			// 
			// MaxIter
			// 
			this->MaxIter->Enabled = false;
			this->MaxIter->Location = System::Drawing::Point(696, 91);
			this->MaxIter->Name = L"MaxIter";
			this->MaxIter->Size = System::Drawing::Size(100, 20);
			this->MaxIter->TabIndex = 6;
			this->MaxIter->TextChanged += gcnew System::EventHandler(this, &MyForm::MaxIter_TextChanged);
			this->MaxIter->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MaxIter_KeyPress);
			this->MaxIter->Text = Convert::ToString(maxIt);
			// 
			// Btn_Iter
			// 
			this->Btn_Iter->Enabled = false;
			this->Btn_Iter->Location = System::Drawing::Point(804, 91);
			this->Btn_Iter->Name = L"Btn_Iter";
			this->Btn_Iter->Size = System::Drawing::Size(75, 23);
			this->Btn_Iter->TabIndex = 4;
			this->Btn_Iter->Text = L"Enter";
			this->Btn_Iter->UseVisualStyleBackColor = true;
			this->Btn_Iter->Click += gcnew System::EventHandler(this, &MyForm::Btn_Iter_Click);
			// 
			// Iter_Label
			// 
			this->Iter_Label->AutoSize = true;
			this->Iter_Label->Location = System::Drawing::Point(710, 75);
			this->Iter_Label->Name = L"Iter_Label";
			this->Iter_Label->Size = System::Drawing::Size(73, 13);
			this->Iter_Label->TabIndex = 5;
			this->Iter_Label->Text = L"Max Iterations";
			// 
			// zoomFactor
			// 
			this->zoomFactor->Enabled = false;
			this->zoomFactor->Location = System::Drawing::Point(696, 146);
			this->zoomFactor->Name = L"zoomFactor";
			this->zoomFactor->Size = System::Drawing::Size(100, 20);
			this->zoomFactor->TabIndex = 7;
			this->zoomFactor->TextChanged += gcnew System::EventHandler(this, &MyForm::ZoomFactor_TextChanged);
			this->zoomFactor->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::ZoomFactor_KeyPress);
			this->zoomFactor->Text = Convert::ToString(zoom);
			// 
			// nthPower
			// 
			this->nthPower->Enabled = false;
			this->nthPower->Location = System::Drawing::Point(696, 241);
			this->nthPower->Name = L"nthPower";
			this->nthPower->Size = System::Drawing::Size(100, 20);
			this->nthPower->TabIndex = 8;
			this->nthPower->TextChanged += gcnew System::EventHandler(this, &MyForm::NthPower_TextChanged);
			this->nthPower->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::NthPower_KeyPress);
			this->nthPower->Text = Convert::ToString(nthP);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(716, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Zoom Factor";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(699, 225);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Multibrot nth power";
			// 
			// btnNth
			// 
			this->btnNth->Enabled = false;
			this->btnNth->Location = System::Drawing::Point(804, 241);
			this->btnNth->Name = L"btnNth";
			this->btnNth->Size = System::Drawing::Size(75, 23);
			this->btnNth->TabIndex = 11;
			this->btnNth->Text = L"Enter";
			this->btnNth->UseVisualStyleBackColor = true;
			this->btnNth->Click += gcnew System::EventHandler(this, &MyForm::BtnNth_Click);
			// 
			// zooming
			// 
			this->zooming->AutoSize = true;
			this->zooming->Location = System::Drawing::Point(261, 47);
			this->zooming->Name = L"zooming";
			this->zooming->Size = System::Drawing::Size(58, 13);
			this->zooming->TabIndex = 12;
			this->zooming->Text = L"ZOOMING";
			this->zooming->ForeColor = Color::FromArgb(0, 0, 255);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(895, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveFileToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveFileToolStripMenuItem
			// 
			this->saveFileToolStripMenuItem->Name = L"saveFileToolStripMenuItem";
			this->saveFileToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->saveFileToolStripMenuItem->Text = L"Save File";
			this->saveFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::SaveFileToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ExitToolStripMenuItem_Click);
			// 
			// realBox
			// 
			this->realBox->Location = System::Drawing::Point(696, 315);
			this->realBox->Name = L"realBox";
			this->realBox->ReadOnly = true;
			this->realBox->Size = System::Drawing::Size(100, 20);
			this->realBox->TabIndex = 14;
			// 
			// imagBox
			// 
			this->imagBox->Location = System::Drawing::Point(696, 375);
			this->imagBox->Name = L"imagBox";
			this->imagBox->ReadOnly = true;
			this->imagBox->Size = System::Drawing::Size(100, 20);
			this->imagBox->TabIndex = 15;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(731, 299);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 13);
			this->label3->TabIndex = 16;
			this->label3->Text = L"real";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(720, 359);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"imaginary";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"MandelCol", L"JuliaCol", L"BurningCol", L"PhoenixCol",
					L"NovaCol", L"MultibrotCol"
			});
			this->comboBox2->Location = System::Drawing::Point(549, 239);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 21);
			this->comboBox2->TabIndex = 18;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::ComboBox2_SelectedIndexChanged);
			this->comboBox2->Enabled = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(589, 223);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 13);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Coloring";
			// 
			// btn_Help
			// 
			this->btn_Help->Location = System::Drawing::Point(803, 561);
			this->btn_Help->Name = L"btn_Help";
			this->btn_Help->Size = System::Drawing::Size(75, 23);
			this->btn_Help->TabIndex = 20;
			this->btn_Help->Text = L"Help";
			this->btn_Help->UseVisualStyleBackColor = true;
			this->btn_Help->Click += gcnew System::EventHandler(this, &MyForm::Btn_Help_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(895, 606);
			this->Controls->Add(this->btn_Help);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->imagBox);
			this->Controls->Add(this->realBox);
			this->Controls->Add(this->zooming);
			this->Controls->Add(this->btnNth);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->nthPower);
			this->Controls->Add(this->zoomFactor);
			this->Controls->Add(this->Iter_Label);
			this->Controls->Add(this->Btn_Iter);
			this->Controls->Add(this->MaxIter);
			this->Controls->Add(this->Fractals);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Recalls the repsective function to change the coloring
		System::Void ComboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			switch (Convert::ToInt16(comboBox1->SelectedIndex))
			{
			case 0:
			{
				Mandelbrot();
				break;
			}
			case 1:
			{
				Julia();
				break;
			}
			case 2:
			{
				BurningShip();
				break;
			}
			case 4:
			{
				Phoenix();
				break;
			}
			case 5:
			{
				Nova();
				break;
			}
			case 6:
			{
				DouadyRabbit();
				break;
			}
			case 7:
			{
				MultiBrot();
				break;
			}
			default:
				break;
			}
		}

		vec3 getColor(double col)
		{
			Byte r, g, b;

			int clr1 = (int)col;
			double t2 = col - clr1;
			double t1 = 1 - t2;
			clr1 = clr1 % 17;
			int clr2 = (clr1 + 1) % 17;

			if (comboBox1->SelectedIndex == 0 && comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 0) // Mandelbrot or MandelCol
			{
				r = (Byte)(MandelPalet[clr1].x * t1 + MandelPalet[clr2].x * t2);
				g = (Byte)(MandelPalet[clr1].y * t1 + MandelPalet[clr2].y * t2);
				b = (Byte)(MandelPalet[clr1].z * t1 + MandelPalet[clr2].z * t2);
			}
			else if ((comboBox1->SelectedIndex == 1 || comboBox1->SelectedIndex == 6) && comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 1) // Julia and Douady or JuliaCol
			{
				r = sin(0.016 * col + 4) * 230 + 25;
				g = sin(0.013 * col + 2) * 230 + 25;
				b = sin(0.01 * col + 1) * 230 + 25;
			}
			else if (comboBox1->SelectedIndex == 2 && comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 2) // Burning Ship or BurningCol
			{
				r = (Byte)(BurningPalet[clr1].x * t1 + BurningPalet[clr2].x * t2);
				g = (Byte)(BurningPalet[clr1].y * t1 + BurningPalet[clr2].y * t2);
				b = (Byte)(BurningPalet[clr1].z * t1 + BurningPalet[clr2].z * t2);
			}
			else if (comboBox1->SelectedIndex == 4 && comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 3) // Phoenix or PhoenixCol
			{
				r = (Byte)(PhoenixPalet[clr1].x * t1 + PhoenixPalet[clr2].x * t2);
				g = (Byte)(PhoenixPalet[clr1].y * t1 + PhoenixPalet[clr2].y * t2);
				b = (Byte)(PhoenixPalet[clr1].z * t1 + PhoenixPalet[clr2].z * t2);
			}
			else if (comboBox1->SelectedIndex == 5 && comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 4) // Nova or NovaCol
			{
				r = (Byte)(NovaPalet[clr1].x * t1 + NovaPalet[clr2].x * t2);
				g = (Byte)(NovaPalet[clr1].y * t1 + NovaPalet[clr2].y * t2);
				b = (Byte)(NovaPalet[clr1].z * t1 + NovaPalet[clr2].z * t2);
			}
			else if (comboBox1->SelectedIndex == 7 && comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 5) // Multibrot or MultibrotCol
			{
				r = g = b = col;
			}

			return vec3((float)r, (float)g, (float)b);
		}

		void Mandelbrot()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			Byte r, g, b;
			double x, y;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = (min_re + (max_re - min_re) * i / bmp->Width) * 0.75;
					y = (min_im + (max_im - min_im) * j / bmp->Height) * 1.4;

					complex<double> z(0.0, 0.0);
					complex<double> c(x, y);

					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						double xtemp = real(z) * real(z) - imag(z) * imag(z) + real(c);
						z.imag(2.0 * real(z) * imag(z) + imag(c));
						z.real(xtemp);
						it++;
					}

					double color = it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
					// if multibrotCol is selected don't divide for the palette coloring
					vec3 col = getColor((comboBox2->SelectedIndex == 5 ? color : color / maxIt * 17));
					
					bmp->SetPixel(i, j, Color::FromArgb(col.x, col.y, col.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		void Julia()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			Byte r, g, b;
			double x, y;
			double continuous_index;
			bool juliaFlag;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = 0.75 + (min_re + (max_re - min_re) * i / bmp->Width);
					y = 1.4 * (min_im + (max_im - min_im) * j / bmp->Height);

					complex<double> z(x, y);
					complex<double> c(-0.1, 0.651);

					// Deeprun is a subset of Julia set
					//complex<double> c(-0.772727, 0.086364);
					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						double xtemp = real(z) * real(z) - imag(z) * imag(z) + real(c);
						z.imag(2.0 * real(z) * imag(z) + imag(c));
						z.real(xtemp);
						it++;

					}

					if (comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 1)
					{
						continuous_index = it + 1.0 - (log(2) / abs(real(z) * real(z) + imag(z) * imag(z))) / log(2);
						juliaFlag = true;
					}
					else
					{
						continuous_index = it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
						juliaFlag = false;
					}
					// if multibrotCol or Julia set is selected don't divide for the palette coloring
					vec3 color = getColor((comboBox2->SelectedIndex == 5 || juliaFlag ? continuous_index : continuous_index / maxIt * 17));

					bmp->SetPixel(i, j, Color::FromArgb(color.x, color.y, color.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		void DouadyRabbit()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			Byte r, g, b;
			double x, y;
			double continuous_index;
			bool rabbitFlag;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = 0.75 + (min_re + (max_re - min_re) * i / bmp->Width);
					y = 1.4 * (min_im + (max_im - min_im) * j / bmp->Height);

					complex<double> z(x, y);
					complex<double> c(-0.123, 0.745);

					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						double xtemp = real(z) * real(z) - imag(z) * imag(z) + real(c);
						z.imag(2.0 * real(z) * imag(z) + imag(c));
						z.real(xtemp);
						it++;
					}

					if (comboBox2->SelectedIndex == -1 || comboBox2->SelectedIndex == 1)
					{
						continuous_index = it + 1.0 - (log(2) / abs(real(z) * real(z) + imag(z) * imag(z))) / log(2);
						rabbitFlag = true;
					}
					else
					{
						continuous_index = it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
						rabbitFlag = false;
					}

					vec3 color = getColor((comboBox2->SelectedIndex == 5 || rabbitFlag ? continuous_index : continuous_index / maxIt * 17));

					bmp->SetPixel(i, j, Color::FromArgb(color.x, color.y, color.z));

					bmp->SetPixel(i, j, Color::FromArgb(color.x, color.y, color.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		void BurningShip()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			double x, y;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = (min_re + (max_re - min_re) * i / bmp->Width) * 0.93 + 0.3;
					y = (min_im + (max_im - min_im) * j / bmp->Height) * 1.75;


					complex<double> z(0.0, 0.0);
					complex<double> c(x, y);

					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						double xtemp = real(z) * real(z) - imag(z) * imag(z) + real(c);
						z.imag(Math::Abs(2.0 * real(z) * imag(z)) + imag(c));
						z.real(xtemp);
						it++;
					}


					double color = it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
					vec3 col = getColor((comboBox2->SelectedIndex == 5 ? color : color / maxIt * 17));

					bmp->SetPixel(i, j, Color::FromArgb(col.x, col.y, col.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		complex<double> Function(complex<double>& z)
		{
			return z * z * z - 1.0;
		}

		complex<double> Derivative(complex<double> z)
		{
			return z * z * 3.0;
		}

		void Newton()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			Byte r, g, b;
			double x, y;

			complex<double> roots[3] =
			{
				complex<double>(1.0, 0.0),
				complex<double>(-0.5, sqrt(3) / 2),
				complex<double>(-0.5, -sqrt(3) / 2)
			};


			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = (min_re + (max_re - min_re) * i / bmp->Width) * 0.75 + 0.5;
					y = (min_im + (max_im - min_im) * j / bmp->Height) * 1.4;

					complex<double> z(x, y);

					for (int iteration = 0; iteration < maxIt; iteration++)
					{
						float tolerance = 0.000001;

						if (abs(Function(z)) < tolerance)
							break;
						z -= Function(z) / Derivative(z);

						if (iteration != maxIt)
						{
							for (int k = 1; k < 4; k++)
							{
								complex<double> difference = z - roots[k];


								if (Math::Abs(real(difference)) < tolerance && Math::Abs(imag(difference) < tolerance))
								{
									double continuous_index = iteration + 1.0 - (log(2) / abs(real(z) * real(z) + imag(z) * imag(z))) / log(2);
									r = sin(0.016 * continuous_index + 4) * 230 + 25;
									g = sin(0.013 * continuous_index + 2) * 230 + 25;
									b = sin(0.01 * continuous_index + 1) * 230 + 25;

									bmp->SetPixel(i, j, Color::FromArgb((r * k) % 255, (g * k) % 255, (b * k) % 255));
								}

							}
						}
					}
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		void Phoenix()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			double x, y;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = (min_re + (max_re - min_re) * i / bmp->Width) * 0.75 + 0.5;
					y = (min_im + (max_im - min_im) * j / bmp->Height) * 1.4;


					complex<double> z(x, y);
					complex<double> c( 0.566666, -0.5);
					complex<double> pr(0.0, 0.0); // previous complex numbers

					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						z = z * z + real(c) + imag(c) * pr;
						pr = z;
						it++;
					}
					
					double color = it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
					vec3 col = getColor((comboBox2->SelectedIndex == 5 ? color : color / maxIt * 17));

					bmp->SetPixel(i, j, Color::FromArgb(col.x, col.y, col.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		void Nova()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			double x, y;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = (min_re + (max_re - min_re) * i / bmp->Width) * 0.42;
					y = (min_im + (max_im - min_im) * j / bmp->Height) * 0.78;


					complex<double> z(0.0, 0.0);
					complex<double> c(x, y);

					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						z = z - 10.0 * (((z * z * z) - 1.0) / 3.0 * (z * z)) + c;
						it++;
					}

					double color = it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
					vec3 col = getColor((comboBox2->SelectedIndex == 5 ? color : color / maxIt * 17));

					bmp->SetPixel(i, j, Color::FromArgb(col.x, col.y, col.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		void MultiBrot()
		{
			refresh();

			Bitmap^ bmp = gcnew Bitmap(512, 512);
			Byte r, g, b;
			double x, y;

			for (int i = 0; i < bmp->Width; i++)
			{
				for (int j = 0; j < bmp->Height; j++)
				{
					x = (min_re + (max_re - min_re) * i / bmp->Width) * 0.75 + 0.5;
					y = (min_im + (max_im - min_im) * j / bmp->Height) * 1.4;


					complex<double> z(0.0, 0.0);
					complex<double> c(x, y);

					int it = 0;

					while (real(z) * real(z) + imag(z) * imag(z) < 4.0 && it < maxIt)
					{
						double xtemp = Math::Pow((real(z) * real(z) + imag(z) * imag(z)), nthP / 2) * Math::Cos(nthP * Math::Atan2(imag(z), real(z))) + real(c);
						z.imag(Math::Pow(real(z) * real(z) + imag(z) * imag(z), nthP / 2) * Math::Sin(nthP * Math::Atan2(imag(z), real(z))) + imag(c));
						z.real(xtemp);
						it++;
					}


					double color =  it + 1 - (log(log(real(z) * real(z) + imag(z) * imag(z))) / log(2));
					vec3 col = getColor((comboBox2->SelectedIndex == 5 || comboBox2->SelectedIndex == -1 ? color : color = color / maxIt * 17));

					bmp->SetPixel(i, j, Color::FromArgb(col.x, col.y, col.z));
				}
			}

			realBox->Text = Convert::ToString(x);
			imagBox->Text = Convert::ToString(y);

			pictureBox1->Image = bmp;
		}

		double interpolate(double start, double end, double interpolation)
		{
			if (!unzoom)
				return start + ((end - start) * interpolation);
			else
				return start + ((end - start) / interpolation);
		}

		void applyZoom(double mouseRe, double mouseIm, double zoomFact)
		{
			double interpolation = 1.0 / zoomFact;
			min_re = interpolate(mouseRe, min_re, interpolation);
			min_im = interpolate(mouseIm, min_im, interpolation);
			max_re = interpolate(mouseRe, max_re, interpolation);
			max_im = interpolate(mouseIm, max_im, interpolation);
		}

		System::Void ComboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
		{
			// reset the scale
			min_re = -2.5, max_re = 1.0;
			min_im = -1.0, max_im = 1.0;

			if (comboBox1->SelectedIndex == 0)
				Mandelbrot();
			if (comboBox1->SelectedIndex == 1)
				Julia();
			if (comboBox1->SelectedIndex == 2)
				BurningShip();
			if (comboBox1->SelectedIndex == 3)
				Newton();
			if (comboBox1->SelectedIndex == 4)
				Phoenix();
			if (comboBox1->SelectedIndex == 5)
				Nova();
			if (comboBox1->SelectedIndex == 6)
				DouadyRabbit();
			if (comboBox1->SelectedIndex == 7)
				MultiBrot();
		}

		// Handles the double click event inside the fractal
		System::Void PictureBox1_DoubleClick(System::Object^ sender, System::EventArgs^ e)
		{
			Fractals->Focus();
			if (comboBox1->SelectedIndex == 0)
			{
				applyZoom(mouseX, mouseY, zoom);
				Mandelbrot();
			}
			if (comboBox1->SelectedIndex == 1)
			{
				applyZoom(mouseX, mouseY, zoom);
				Julia();
			}
			if (comboBox1->SelectedIndex == 2)
			{
				applyZoom(mouseX, mouseY, zoom);
				BurningShip();
			}
			if (comboBox1->SelectedIndex == 3)
			{
				applyZoom(mouseX, mouseY, zoom);
				Newton();
			}
			if (comboBox1->SelectedIndex == 4)
			{
				applyZoom(mouseX, mouseY, zoom);
				Phoenix();
			}
			if (comboBox1->SelectedIndex == 5)
			{
				applyZoom(mouseX, mouseY, zoom);
				Nova();
			}
			if (comboBox1->SelectedIndex == 6)
			{
				applyZoom(mouseX, mouseY, zoom);
				DouadyRabbit();
			}
			if (comboBox1->SelectedIndex == 7)
			{
				applyZoom(mouseX, mouseY, zoom);
				MultiBrot();
			}
		}

		// Gets only the mouse coordinates if you click just once
		System::Void PictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			mouseX = (double)e->X / (pictureBox1->Width / (max_re - min_re)) + min_re;
			mouseY = (double)e->Y / (pictureBox1->Height / (max_im - min_im)) + min_im;
		}

		// Sets the focus in a label
		System::Void Fractals_PreviewKeyDown(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e)
		{
			if (e->Control) unzoom = !unzoom;
			refresh();
		}


		// Recall the functions with the new max iterator
		System::Void Btn_Iter_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (comboBox1->SelectedIndex == 0)
				Mandelbrot();
			if (comboBox1->SelectedIndex == 1)
				Julia();
			if (comboBox1->SelectedIndex == 2)
				BurningShip();
			if (comboBox1->SelectedIndex == 3)
				Newton();
			if (comboBox1->SelectedIndex == 4)
				Phoenix();
			if (comboBox1->SelectedIndex == 5)
				Nova();
			if (comboBox1->SelectedIndex == 6)
				DouadyRabbit();
			if (comboBox1->SelectedIndex == 7)
				MultiBrot();
		}

		//==========================//
		//----- Max Iteration ----- //
		//==========================//

		System::Void MaxIter_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			// Handle anything that's not a backspace or numbers. The numbers represent their respective Ascii codes
			if (e->KeyChar != 8 && e->KeyChar < 48 || e->KeyChar > 57)
				e->Handled = true;
		}

		System::Void MaxIter_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (MaxIter->Text != "" && Convert::ToInt32(MaxIter->Text) > 10000 || MaxIter->Text->Length > 5)
				MaxIter->Text = "10000";

			if (MaxIter->Text != "" && Convert::ToInt32(MaxIter->Text) >= 0 && Convert::ToInt32(MaxIter->Text) < 10001)
				maxIt = Convert::ToInt32(MaxIter->Text);
		}

		//=======================//
		//----- Zoom Factor -----//
		//=======================//

		System::Void ZoomFactor_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (e->KeyChar != 8 && e->KeyChar < 48 || e->KeyChar > 57)
				e->Handled = true;
		}

		System::Void ZoomFactor_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (zoomFactor->Text != "" && Convert::ToInt32(zoomFactor->Text) > 20000 || zoomFactor->Text->Length > 5)
				zoomFactor->Text = "20000";

			if (zoomFactor->Text != "" && Convert::ToInt32(zoomFactor->Text) >= 0 && Convert::ToInt32(zoomFactor->Text) < 20001)
				zoom = Convert::ToInt32(zoomFactor->Text);
		}

		//=====================//
		//----- MultiBrot -----//
		//=====================//

		System::Void NthPower_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (nthPower->Text != "" && Convert::ToInt32(nthPower->Text) > 500 || nthPower->Text->Length > 3)
				nthPower->Text = "500";

			if (nthPower->Text != "" && Convert::ToInt32(nthPower->Text) >= 0 && Convert::ToInt32(nthPower->Text) < 501)
				nthP = Convert::ToInt32(nthPower->Text);
		}

		System::Void NthPower_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			if (e->KeyChar != 8 && e->KeyChar < 48 || e->KeyChar > 57)
				e->Handled = true;
		}

		System::Void BtnNth_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (comboBox1->SelectedIndex == 7)
				MultiBrot();
		}

		void refresh()
		{
			//---- Disable or Enable ----//
			comboBox2->Enabled = (comboBox1->SelectedIndex != 3);

			nthPower->Enabled = (comboBox1->SelectedIndex == 7);
			btnNth->Enabled = (comboBox1->SelectedIndex == 7);

			MaxIter->Enabled = (comboBox1->SelectedIndex != -1);
			zoomFactor->Enabled = (comboBox1->SelectedIndex != -1);
			Btn_Iter->Enabled = (comboBox1->SelectedIndex != -1);
			//---------------------------//

			if (!unzoom)
			{
				zooming->Text = "ZOOMING";
				zooming->ForeColor = Color::FromArgb(0, 0, 255);
			}
			else
			{
				zooming->Text = "UNZOOMING";
				zooming->ForeColor = Color::FromArgb(255, 0, 0);
			}
		}

		System::Void SaveFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SaveFileDialog^ sfd = gcnew SaveFileDialog();
			sfd->Filter = "Image files (*.jpg, *.jpeg, *.jpe, *.jfif, *.png) | *.jpg; *.jpeg; *.jpe; *.jfif; *.png";

			if (pictureBox1->Image != nullptr)
			{
				if (sfd->ShowDialog() == FractalExplorer::DialogResult::OK)
				{
					System::IO::Stream^ path = sfd->OpenFile();
					pictureBox1->Image->Save(path, System::Drawing::Imaging::ImageFormat::Jpeg);
				}
			}
		}

		System::Void ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Close();
		}

		System::Void Btn_Help_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ str = "Press Double click inside the image box to zoom.\nPress ctrl to switch between zooming and unzooming.\nYou can change the number of iterations and the zoom multiplier.\n";
			MessageBox::Show(str, "Controls", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
	};
}
