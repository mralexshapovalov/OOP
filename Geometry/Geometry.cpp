
#include<Windows.h>
#include<iostream>


#define delimiter "\n----------------------------------------\n"

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_default = 0x07
	};
	//enum (Enumeration - Перечисление) - это набор именованных констант типа 'int'

	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;
	public:
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(int start_x)
		{
			if (start_x < 10)start_x = 10;
			if (start_x > 500)start_x = 500;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < 10)start_y = 10;
			if (start_y > 500)start_y = 500;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < 5)line_width = 5;
			if (line_width > 20)line_width = 20;
			this->line_width = line_width;
		}

		Shape(Color color, int start_x, int start_y, int line_width) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			std::cout << "Площадь фигуры: " << get_area() << std::endl;
			std::cout << "Периметр фигуры: " << get_perimeter() << std::endl;
			draw();
		}
	};

	/*class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side > 20)side = 20;
			if (side < 5)side = 5;
			this->side = side;
		}
		//					Constructors:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны квадрата: " << side << endl;
			Shape::info();
		}
	};*/

	class Rectangle :public Shape
	{
		double side_1, side_2;
	public:
		double get_side_1()const
		{
			return side_1;
		}
		double get_side_2()const
		{
			return side_2;
		}
		void set_side_1(double side_1)
		{
			if (side_1 < 50)side_1 = 50;
			if (side_1 > 550)side_1 = 550;
			this->side_1 = side_1;
		}
		void set_side_2(double side_2)
		{
			if (side_2 < 50)side_2 = 50;
			if (side_2 > 550)side_2 = 550;
			this->side_2 = side_2;
		}
		Rectangle(double side_1, double side_2, Color color, int start_x, int start_y, int line_width)
			:Shape(color, start_x, start_y, line_width)
		{
			set_side_1(side_1);
			set_side_2(side_2);
		}
		~Rectangle() {}

		double get_area()const override
		{
			return side_1 * side_2;
		}
		double get_perimeter()const override
		{
			return (side_1 + side_2) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side_1; i++)
			{
				for (int j = 0; j < side_2; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/

			HWND hwnd = GetConsoleWindow();	//Получаем обработчик окна консоли
			HDC hdc = GetDC(hwnd);	//Получаем контекст усройства окна косоли
			//Контекст устройства - это то, на чем мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			//Pen (карандаш) рисут контур фигуры,
			//PS_SOLID - сплошная линия
			//5 - толщина линии 5 пикселов

			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - это кисть, рисует заливку замкнутой фигуры.

			//Выбираем чем и на чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда все инфстументы созданы и выбраны, можно вызывать функцию,
			//для рисования нужно фигуры:

			::Rectangle(hdc, start_x, start_y, start_x + side_1, start_y + side_2);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);	//Освобождаем контекст устройства
		}

		void info()const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Сторона 1: " << side_1 << std::endl;
			std::cout << "Сторона 2: " << side_2 << std::endl;
			Shape::info();
		}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, Color color, int start_x, int start_y, int line_width)
			:Rectangle(side, side, color, start_x, start_y, line_width) {}
		~Square() {}
	};
}

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	setlocale(LC_ALL, "");

	Geometry::Square square(1000, Geometry::Color::red, 300, 10, 5);
	square.info();

	Geometry::Rectangle rect(120, 75, Geometry::Color::blue, 500, 10, 8);
	rect.info();
}
