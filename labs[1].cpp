/* 
 * 1, 3, 5, 8, 9
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Instrument
{
	protected:
		string type;
		virtual void do_sound() = 0;
};

class Guitar : private Instrument
{
	public:
		Guitar()
		{
			type = "Guitar";
		}
		
		void do_sound()
		{
			cout << type << " is making sound" << endl;
		} 
};

class Human
{
	private:
		string name;
		string surname;	
	public:	
		Human()
		{
			this->name = this->surname = "Unknown";
		}
		Human(string name, string surname)
		{
			this->name = name;
			this->surname = surname;
		}	
		
		string get_name()
		{
			return name;
		}
		string get_surname()
		{
			return surname;
		}
};	
class Guitarist: public Human, public Guitar
{
	public:
		Guitarist() : Human()
		{ }
		Guitarist(string name, string surname) : Human(name, surname) 
		{ }
		
		void play_guitar()
		{
			cout << get_name() << " " << get_surname() << " is playing."<<endl;
			do_sound();
		}
};

int main()
{
	Guitarist g("Yegor", "Letov");
	g.play_guitar();
}
