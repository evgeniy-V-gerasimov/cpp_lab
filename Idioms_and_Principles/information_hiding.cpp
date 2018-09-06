#include <iostream>

class User_integer{
	public:
		explicit User_integer(int init): number{init} {}
		bool isNegative() const{
			return number < 0 ? true : false;
		}
		bool isPositive() const{
			return number > 0 ? true : false;
		}
		bool isNull() const{
			return number == 0 ? true : false;
		}
		bool isPrime() const{
			if(number <= 0) return false;
			return number % 2 == 0 ? true : false;
		}
	private:
		int number; // type can be changed, external users of the class dont depend on it
};

class Vehicle{
	public:
		Vehicle(): front_left(DoorState::Closed) {}
		bool isOpened() const{
			return front_left == DoorState::Opened ? true : false;
		}
		bool isClosed() const{
			return front_left == DoorState::Closed ? true : false;
		}
		bool isLocked() const{
			return front_left == DoorState::Locked ? true : false;
		}
		bool isJammed() const{
			return front_left == DoorState::Jammed ? true : false;
		}
	private:
		enum class DoorState { // internal representation can be modified
			Opened,
			Closed,
			Locked,
			Jammed
		};
	DoorState front_left;
};


int main(int argc, char** argv)
{
	User_integer var{42};
	Vehicle bus;
	
	std::cout << var.isNegative() << var.isPositive() << var.isNull() << var.isPrime() << '\n';
	
	std::cout << bus.isOpened() << bus.isClosed() << bus.isLocked() << bus.isJammed() << '\n';
	return 0;
}