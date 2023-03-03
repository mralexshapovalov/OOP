#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>



#define SHAPE_CHARATERISTICS Color color,int startX,int startY,int lineWidth
#define SHAPE_VALUES color,startX,startY, lineWidth
//enum (Enumeration - Перечисление) - это набор именованных констант типа 'int'


namespace Geometry 
{
	enum Color
	{

		red = 0x000000FF,
		console_red = 0xCC,
	};


	class Shape  //Фигура
	{

	protected:

		Color color;

		int startX;
		int startY;
		int lineWidth;


		static const int MIN_START_X = 50;
		static const int MIN_START_Y = 50;
		static const int MAX_START_X = 1000;
		static const int MAX_START_Y = 550;
		static const int MIN_SIZE = 50;
		static const int MAX_SIZE = 550;
		static const int MIN_LINE_WIDTH = 1;
		static const int MAX_LINE_WIDTH = 25;

	public:

		int get_startX(int startX)
		{
			return startX;
		}

		int get_startY(int startY)
		{
			return startY;
		}

		int get_lineWidth(int lineWidth)
		{
			return lineWidth;
		}


		void set_startX(int startX)
		{
			if (startX < MIN_START_X)startX = MIN_START_X;
			if (startX > MAX_START_X)startX = MAX_START_X;
			this->startX = startX;
		}

		void set_startY(int startY)
		{
			if (startY < MIN_START_Y)startY = MIN_START_Y;
			if (startY > MAX_START_Y)startY = MAX_START_Y;
			this->startY = startY;
		}

		void set_lineWidth(int lineWidth)
		{
			if (lineWidth < MIN_LINE_WIDTH)lineWidth = MIN_LINE_WIDTH;
			if (lineWidth > MAX_LINE_WIDTH)lineWidth = MAX_LINE_WIDTH;

			this->lineWidth = lineWidth;
		}


		Shape(Color color, int startX, int startY, int lineWidth) :color(color)
		{

			set_startX(startX);
			set_startY(startY);
			set_lineWidth(lineWidth);
			this;
		}

		~Shape() {}

		virtual double get_area() const = 0;

		virtual double get_perimetr() const = 0;

		virtual void draw() const = 0;

		virtual void info() const
		{

			std::cout << "the area of the figure: " << get_area() << std::endl;
			std::cout << "the area of the figure: " << get_perimetr() << std::endl;
			draw();
		};

	};

	class Square :public Shape
	{

	private:
		int side;

	public:

		int get_side(int side)
		{
			return side;
		}

		void set_side(int side)
		{
			if (side < MIN_SIZE)side = MIN_SIZE;
			if (side > MAX_SIZE)side = MAX_SIZE;

			this->side = side;
		}

		Square(int side, SHAPE_CHARATERISTICS) :Shape(SHAPE_VALUES)
		{
			set_side(side);
		}

		~Square() {}

		double get_area()const override
		{
			return side * side;
		}

		double get_perimetr()const override
		{
			return (side + side) * 2;
		}

		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();//Получаем оброботчик окна консоли
			HDC hdc = GetDC(hwnd); //Получаем контекс устройства окна консоли
			//Контекст устройства-это то ,на чем мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, lineWidth, color);

			//PEN (карандаш) рисует контр фигуры
			//PS_SOLID -спплошная линия
			//5 -толщина линии 5 пикселов

			HBRUSH hBrush = CreateSolidBrush(color);

			//Brush -это кисть,рисует заливку замкнутую фигуру

			//Выбираем чем рсовать 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда все инструменты созданы и выбраны можно вызвать функцию 
			//Для рисование фигуры

			::Rectangle(hdc, startX, startY, startX + side, startY + side);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);	//Освобождаем контекст устройства
		}

		void info() const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Side: " << side << std::endl;
			Shape::info();
			draw();
		}

	};


	class Square :public Shape
	{

	private:
		int side;

	public:

		int get_side(int side)
		{
			return side;
		}

		void set_side(int side)
		{
			if (side < MIN_SIZE)side = MIN_SIZE;
			if (side > MAX_SIZE)side = MAX_SIZE;

			this->side = side;
		}

		Square(int side, SHAPE_CHARATERISTICS) :Shape(SHAPE_VALUES)
		{
			set_side(side);
		}

		~Square() {}

		double get_area()const override
		{
			return side * side;
		}

		double get_perimetr()const override
		{
			return (side + side) * 2;
		}

		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();//Получаем оброботчик окна консоли
			HDC hdc = GetDC(hwnd); //Получаем контекс устройства окна консоли
			//Контекст устройства-это то ,на чем мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, lineWidth, color);

			//PEN (карандаш) рисует контр фигуры
			//PS_SOLID -спплошная линия
			//5 -толщина линии 5 пикселов

			HBRUSH hBrush = CreateSolidBrush(color);

			//Brush -это кисть,рисует заливку замкнутую фигуру

			//Выбираем чем рсовать 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда все инструменты созданы и выбраны можно вызвать функцию 
			//Для рисование фигуры

			::Rectangle(hdc, startX, startY, startX + side, startY + side);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);	//Освобождаем контекст устройства
		}

		void info() const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Side: " << side << std::endl;
			Shape::info();
			
		}

	};

	class Rectangle :Shape
	{

	private:
		int sideA;
		int sideB;

	public:

		int get_sideA(int sideA)
		{
			return sideA;
		}

		int get_sideB(int sideB)
		{
			return sideB;
		}

		void set_sideA(int sideA)
		{
			if (sideA < MIN_SIZE)sideA = MIN_SIZE;
			if (sideA > MAX_SIZE)sideA = MAX_SIZE;

			this->sideA = sideA;
		}

		void set_sideB(int sideB)
		{
			if (sideB < MIN_SIZE)sideB = MIN_SIZE;
			if (sideA > MAX_SIZE)sideB = MAX_SIZE;

			this->sideB = sideB;
		}

		Rectangle(int sideA,int sideB, SHAPE_CHARATERISTICS) :Shape(SHAPE_VALUES)
		{
			set_sideA(sideA);
			set_sideA(sideB);
		}

		~Rectangle() {}

		double get_area()const override
		{
			return sideA * sideB;
		}

		double get_perimetr()const override
		{
			return (sideA + sideB) * 2;
		}

		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();//Получаем оброботчик окна консоли
			HDC hdc = GetDC(hwnd); //Получаем контекс устройства окна консоли
			//Контекст устройства-это то ,на чем мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, lineWidth, color);

			//PEN (карандаш) рисует контр фигуры
			//PS_SOLID -спплошная линия
			//5 -толщина линии 5 пикселов

			HBRUSH hBrush = CreateSolidBrush(color);

			//Brush -это кисть,рисует заливку замкнутую фигуру

			//Выбираем чем рсовать 
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда все инструменты созданы и выбраны можно вызвать функцию 
			//Для рисование фигуры

			::Rectangle(hdc, startX, startY, startX + sideA, startY + sideB);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);	//Освобождаем контекст устройства
		}

		void info() const
		{
			std::cout << typeid(*this).name() << std::endl;
			std::cout << "Side: " << sideA << sideB << std::endl;
			Shape::info();
			
		}

	};

}








int main()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	Geometry::Square  square(200, Geometry::Color::red, 300, 50, 5);
	square.info();

	Geometry::Rectangle  rect(120,75, Geometry::Color::red, 550, 50, 5);
	rect.info();

}
