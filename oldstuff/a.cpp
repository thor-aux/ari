#include <iostream>
using namespace std;

class Random {
	public:
      static int randint(int Min, int Max) {
         return rand() % (Max + 1 - Min) + Min;
      }
      static void init() {
		  srand (time(NULL));
      }
};

class Person {
	protected:
		string name;
		int health;
		int char_damage;
	public:
	    string getName() { return name; }
	    int getHealth() { return health; }
	    int getDamage() { return char_damage; }
	    int ChangeHealth(int difference) { health += difference; return health;}
	    virtual int attack() { return 0; }
};

class Soldier : public Person {
protected:
	int d;

public:
	Soldier(string n) {
		cout << "Creating a new Soldier named " << n << endl;
	    name = n;
	    health = 50;
	    char_damage = 1;
	}
	 int attack() {
	 	d = Random::randint(char_damage, char_damage + 10);
	 	cout << "Attacked for " << d << endl;
	 	return d;
	}
};

class Wizard : public Person {
public:
	Wizard(string n) {
	   cout << "Creating a new Wizard named " << n << endl;
	   name = n;
	   char_damage = 1;
	}
	 int attack() {
	 	int d;
	 	d = Random::randint(char_damage, char_damage + 10);
	 	cout << "You attacked for " << d << endl;
	 	return d;
	}

};

class Enimie {
	protected:
		string type;
	public:
		string getType() { return type; }
		virtual int attack() { return 0; }
};

class Goblin : public Enimie {
	private:
		int min_damage;
		int max_damage;
		int d;
	public:
		int attack() {
			d = Random::randint(min_damage, max_damage);
			cout << "A goblin attacked you, doing " << d << " damage" << endl;
			return d;
		}
		Goblin(int min, int max) {
			min_damage = min;
			max_damage = max;
	
			cout << "A goblin with minimum damage " << min_damage << " appeared!" << endl;
		}

};


int main() {
   string name, type;
   Person *me;
   Enimie *goblin1;
   int damage;
   bool IA;
   IA = false;

   Random::init();


   cout << "Welcome to: The Tales of Dunrath" << endl;
   cout << "What, adventurer, is your name?" << endl;
   cout << ":";
   cin >> name;
   cout << endl << "Ah, welcome " << name << endl;
   cout << "Are you a Soldier or Wizard? (enter S or W): ";
   cin >> type;
   if (type == "S") {
   	me = new Soldier(name);
   } else if (type =="W") {
   	me = new Wizard(name);
   } else {
   	cout << "Sorry, I don't know what type that is: " << type << endl;
   	return 0;
   }
   goblin1 = new Goblin(1, 10);
   damage = goblin1->attack();
   cout << me->ChangeHealth(-damage) << endl;





   return 0;
}
