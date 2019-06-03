/* 
 * 6, 7, 10
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Videosettings
{
	private:
		class Resolution
		{
			private:
				bool premium;
				static const int premium_x = 2048;
				static const int premium_y = 1080;
				int x;
				int y;				
			public:
				Resolution()
				{
					premium = false;
					set720();
				}
				void set720()
				{
					x = 1280;
					y = 720;
				}
				
				void set1080()
				{
					x = 1920;
					y = 1080;
				}
				void set_premium()
				{
					premium = true;
					x = premium_x;
					y = premium_y;
				}
				int get_x()
				{
					return x;
				}
				int get_y()
				{
					return y;
				}
				bool get_premium()
				{
					return premium;
				}
		};
		
		Resolution resolution;
		double speed;
		
		void set_premium()
		{
			resolution.set_premium();
		}
		
	public:
	Videosettings()
	{
		speed = 1;
	}
		double get_speed()
		{
			return speed;
		}
		int get_x()
		{
			return resolution.get_x();
		}
		int get_y()
		{
			return resolution.get_y();
		}
		void increase_speed()
		{
			speed *= 2;
		}
		void decrease_speed()
		{
			speed /=2;
		}
		void increase_resolution()
		{
			if(resolution.get_x() == 1280)
				resolution.set1080();
			else if((resolution.get_x() == 1920) && resolution.get_premium())
				resolution.set_premium();
		}
		void decrease_resolution()
		{
			if(resolution.get_x() == 1920)
				resolution.set720();
			else if(resolution.get_x() == 2048)
				resolution.set1080();
		}
	friend class PremiumSubscriber;
};

class PremiumSubscriber
{
	private:
		string name;
		string surname;
		
	public:
		Videosettings settings;
		PremiumSubscriber()
		{
			settings.set_premium();
			name = "Unknown";
			surname = "Unknown";
		}
		PremiumSubscriber(string _name, string _surname): name(_name), surname(_surname)
		{
			settings.set_premium();
		}
		void info()
		{
			cout << name << "  " << surname << " is watching videos in " 
				<< settings.resolution.get_x() <<" X " << settings.resolution.get_y()
				<< ", with speed =  " <<  settings.get_speed() << endl;
		}
};

double length(double x1, double y1, double x2, double y2);

int main()
{
	PremiumSubscriber subscriber(string("Video"), string("Lover"));
	subscriber.settings.decrease_speed();
	subscriber.settings.decrease_resolution();
	subscriber.settings.increase_resolution();
	subscriber.info();
	
	double _length = length(0, 3, 4, 0);
	cout << endl << "Length betwen A(0, 3) and B(4, 0) = "<< _length<< endl;
	
}

double length(double x1, double y1, double x2, double y2)
{
	class Dot
	{
		public:
		double x;
		double y;
		
		Dot(double _x, double _y): x(_x), y(_y)
		{	}
		Dot operator+(const Dot& d)
		{
			return Dot(this->x + d.x, this->y + d.y);
		}
		Dot operator-(const Dot& d)
		{
			return Dot(this->x - d.x, this->y - d.y);
		}
		double operator*(const Dot& d)
		{
			return this->x * d.x + this->y * d.y;
		}//scalar product
		Dot& operator=(const Dot& d)
		{
			x = d.x;
			y = d.y;
			return *this;
		}
	};
	
	Dot a(x1, y1), b(x2, y2);
	Dot c = b - a;
	return sqrt(c.x * c.x + c.y * c.y);
}
