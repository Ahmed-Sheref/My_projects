#include<iostream>
#include<cmath>
#include <string>
using namespace std;


string valid_input (string input);
string encryption_Text(string text, int choose, int key);

int main() 
{
	cout << "*** Welcome to sipher text ***\n\n";
  while (true) 
  {
    string Text_before_cipher;
    cout << "Text: ";
    getline(cin, Text_before_cipher);

    string choose;
    cout << "\n1-Cipher a message\n2-Decipher a message\n(1\\2) => ";
    cin >> choose;
    cin.ignore();
    int choose_number = stoi((valid_input(choose)));

    while(true) 
    {
      if (choose_number == 1 || choose_number == 2)
        break;
      cout << "Please enter valid input (1\\2) ";
      cin >> choose_number;
      cin.ignore();
    }
    cout << "You want to divide the letters into several sections => Key: ";
    string test_key; cin >> test_key;
    cin.ignore();
    int key = stoi(valid_input(test_key));
    while (true) 
    {
      if (key < 1 || key > 2) 
      {
        cout << "Please enter key => 1-2 only: ";
        cin >> key;
        cin.ignore();
      } 
      else
        break;
    }

    if (choose_number == 1 || choose_number == 2) 
    {
      string text_after_cipher = encryption_Text(Text_before_cipher, choose_number, key);
      cout << text_after_cipher << endl;
    }

    string test_try_again;
    cout << "\n1) Try again\n2)Exit\n(1\\2) => ";
    cin >> test_try_again;
    cin.ignore();
		int try_again = stoi(valid_input(test_try_again));
		if (try_again != 1)
		{
      if (try_again == 2)
			{
				cout << "Exit...";
				return 0;
			}
			while (true)
			{
				cout << "Please enter 1-2 Only: ";
				cin >> test_try_again;
				try_again = stoi(valid_input(test_try_again));
      if (try_again == 2)
			{
				cout << "Exit...";
				return 0;
			}
      else if (try_again == 1)
      {
        break;
      }
			}
		}
  }
}



string valid_input (string input) 
{
  string Chek_input = input;
  for (auto ch : Chek_input) 
  {
    if (isdigit(ch) == false) 
    {
      cout << "Please enter a valid number\n";
      cin >> Chek_input;
      return valid_input(Chek_input);
    }
  }
  return (Chek_input);
}

string encryption_Text(string text, int choose, int key) 
{
  int numbers[4] = {0,13};
  int ky = numbers[key-1];
  cout << (choose == 1 ? "\nText After cipher => " : "\nText Before cipher => ");
  string text_after_cipher = "";
  int i = 0;
  for (char ch : text) 
  {
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) 
    {
      if (ch <= 109 && ch >= 97) 
        text_after_cipher += toupper(((25 - (ch - 97)) + 97-ky));
      else if (ch >= 109 && ch >= 97)
        text_after_cipher += toupper((109 - ((ch - 110)))+ky);
      else if (ch <= 77 && ch >= 65) 
        text_after_cipher += toupper(((25 - (ch - 65)) + 65)-ky);
      else if (ch >= 77 && ch >= 65) 
        text_after_cipher += toupper((77 - ((ch - 78)))+ky);
    }
    i++;
  }
  return text_after_cipher;
}