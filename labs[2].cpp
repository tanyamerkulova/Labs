/* 
 * 1, 2, 3, 4, 5, 6, 7 
*/

#include <iostream>
#include <cstring>

using namespace std;

class String
{
	private:
		char* str;
		int size;
		static int counter;
		
	public:
		String() : str(nullptr), size(0)
		{ 
			counter++;
		}
		String(char* _str) : str(_str)
		{
			counter++;
			size = strlen(_str);
			str = new char[size];
			for(int i = 0; i < size; i++)
				str[i] = _str[i];
		}
		String(const char* _str)
		{
			counter++;
			size = strlen(_str);
			str = new char[size];
			for(int i = 0; i < size; i++)
				str[i] = _str[i];
		}
		
		String(const String& _str)
		{
			
			operator=(_str);
		}
		~String()
		{
			counter--;
			delete [] str;
		}
		int get_size() const
		{
			return size;
		}
		
		char operator[](int i) const
		{
			if(i >=0 && i < size)
				return str[i];
			return '\0';
		}
		String& operator+(const String& s)
		{
			int new_size = size + s.get_size();
			char* new_str = new char[new_size];
			for(int i = 0; i < new_size; i++)
			{
				if(i < size)
					new_str[i] = str[i];
				else
					new_str[i] = s[i-size];
			}
			return *new String(new_str);
		}
		String& operator=(const String& _str)
		{
			counter++;
			delete[] str;
			if(_str.get_size() > 0)
			{
				size = _str.get_size();
				str = new char[size];
				for(int i = 0; i < size; i++)
					str[i] = _str[i];
			}
			else
			{
				size = 0;
				str = nullptr;
			}
			return *this;
		}
		
		friend ostream& operator<<(ostream& o, const String& s)
		{
			if(s.str != nullptr)
				o << s.str;
			return o;
		}
		
		friend void print(const String& s)
		{
			if(s.str != nullptr)
				cout << s.str;
		}
		
		static int get_counter()
		{
			return counter;
		}
};

int String::counter = 0;

int main()
{
	String str1;
	String str2("Hello,");
	String str3(" ");
	String str4 = String("my");
	str1 = str2 + str3 + str4 + str3 + String("friend");
	print(str1);
	cout << endl << "There have been created " << String::get_counter() << " strings." << endl;
	
}

