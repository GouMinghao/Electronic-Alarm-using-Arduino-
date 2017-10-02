#include <LiquidCrystal.h>   //调用arduino自带的LiquidCrystal库
#include <Servo.h>
#include <MsTimer2.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);//设置接口
Servo myservo;
int h, m, s;
int select = 1;
int selectshow = 0;
void flash()
{
	if (!digitalRead(1))
	{
		select = 2;
		MsTimer2::stop();
	}
}
void setup()
{
	lcd.begin(16, 2);  //初始化LCD
	h = 0;
	m = 1;
	s = 2;
	pinMode(2, INPUT);
	pinMode(1, INPUT);
	myservo.attach(13);
	myservo.write(40);
	MsTimer2::set(200, flash); // 500ms period
	MsTimer2::start();
}
void loop()
{
	switch (select)
	{
	case 1:
	{
		delay(994);  //延时0.5秒，刷新频率这里进行调整
		s--;
		if (s == -1)
		{
			s = 59;
			m--;
			if (m == -1)
			{
				m = 59;
				h--;
				if (h == -1)
				{
					h = 23;
				}
			}
		}
		if ((h == 0) && (m == 0) && (s == 0))
		{
			myservo.write(140);
			lcd.clear();
			lcd.setCursor(3, 0);
			lcd.print("ALL  DONE!");
			while (1)
			{
				;
			}
		}
		lcdprint(0, 0);
		break;
	}
	case 2:
	{
		if (!digitalRead(2))
		{
			s++;
			if (s == 60)
			{
				s = 0;
			}
		}
		if (!digitalRead(1))
		{
			select++;
			selectshow = 0;
			delay(200);
		}
		lcdprint(selectshow,1);
		if (selectshow == 1)
			selectshow = 0;
		else
			selectshow = 1;
		delay(200);
		break;
	}
	case 3:
	{
		if (!digitalRead(2))
		{
			m++;
			if (m == 60)
			{
				m = 0;
			}
		}
		if (!digitalRead(1))
		{
			selectshow = 0;
			select++;
			delay(200);
		}
		lcdprint(selectshow,1);
		if (selectshow == 2)
			selectshow = 0;
		else
			selectshow = 2;
		delay(200);
		break;
	}
	case 4:
	{
		if (!digitalRead(2))
		{
			h++;
			if (h == 24)
			{
				h = 0;
			}
		}
		if (!digitalRead(1))
		{
			select = 1;
			selectshow = 0;
			MsTimer2::start();
			delay(200);
		}
		lcdprint(selectshow,1);
		if (selectshow == 3)
			selectshow = 0;
		else
			selectshow = 3;
		delay(200);
		break;
	}
	}
}
void lcdprint(int selectshow, int show_set_select)
{
	switch (show_set_select)
	{
	case 0:
	{
		lcd.clear();
		lcd.setCursor(2, 0);
		lcd.print("TIME REMAINS");
		lcd.setCursor(4, 1);
		if (h < 10)
		{
			lcd.print("0");
			lcd.print(h);
		}
		else
		{
			lcd.print(h);
		}
		lcd.print(":");
		if (m < 10)
		{
			lcd.print("0");
			lcd.print(m);
		}
		else
		{
			lcd.print(m);
		}
		lcd.print(":");
		if (s < 10)
		{
			lcd.print("0");
			lcd.print(s);
		}
		else
		{
			lcd.print(s);
		}
		break;
	}
	case 1:
	{
		switch (selectshow)
		{
		case 0:
		{
			lcd.clear();
			lcd.setCursor(4, 0);
			lcd.print("TIME SET");
			lcd.setCursor(4, 1);
			if (h < 10)
			{
				lcd.print("0");
				lcd.print(h);
			}
			else
			{
				lcd.print(h);
			}
			lcd.print(":");
			if (m < 10)
			{
				lcd.print("0");
				lcd.print(m);
			}
			else
			{
				lcd.print(m);
			}
			lcd.print(":");
			if (s < 10)
			{
				lcd.print("0");
				lcd.print(s);
			}
			else
			{
				lcd.print(s);
			}
			break;
		}
		case 1:
		{
			lcd.clear();
			lcd.setCursor(4, 0);
			lcd.print("TIME SET");
			lcd.setCursor(4, 1);
			if (h < 10)
			{
				lcd.print("0");
				lcd.print(h);
			}
			else
			{
				lcd.print(h);
			}
			lcd.print(":");
			if (m < 10)
			{
				lcd.print("0");
				lcd.print(m);
			}
			else
			{
				lcd.print(m);
			}
			lcd.print(":");
			if (s < 10)
			{
				lcd.print("0");
				lcd.print(s);
			}
			else
			{
				lcd.print(s);
			}
			lcd.setCursor(10, 1);
			lcd.print("__");
			break;
		}
		case 2:
		{
			lcd.clear();
			lcd.setCursor(4, 0);
			lcd.print("TIME SET");
			lcd.setCursor(4, 1);
			if (h < 10)
			{
				lcd.print("0");
				lcd.print(h);
			}
			else
			{
				lcd.print(h);
			}
			lcd.print(":");
			if (m < 10)
			{
				lcd.print("0");
				lcd.print(m);
			}
			else
			{
				lcd.print(m);
			}
			lcd.print(":");
			if (s < 10)
			{
				lcd.print("0");
				lcd.print(s);
			}
			else
			{
				lcd.print(s);
			}
			lcd.setCursor(7, 1);
			lcd.print("__");
			break;
		}
		case 3:
		{
			lcd.clear();
			lcd.setCursor(4, 0);
			lcd.print("TIME SET");
			lcd.setCursor(4, 1);
			if (h < 10)
			{
				lcd.print("0");
				lcd.print(h);
			}
			else
			{
				lcd.print(h);
			}
			lcd.print(":");
			if (m < 10)
			{
				lcd.print("0");
				lcd.print(m);
			}
			else
			{
				lcd.print(m);
			}
			lcd.print(":");
			if (s < 10)
			{
				lcd.print("0");
				lcd.print(s);
			}
			else
			{
				lcd.print(s);
			}
			lcd.setCursor(4, 1);
			lcd.print("__");
			break;
		}
		}
		break;
	}
	}
}
