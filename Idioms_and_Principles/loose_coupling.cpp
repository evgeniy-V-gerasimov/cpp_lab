#include <iostream>

class Valve {
	public:
	virtual void open() = 0;
	virtual void close() = 0;
};
class ValveServo {
	private:
	Valve& valve;
	bool state {false};
	public:
	ValveServo(Valve& vref) : valve(vref) {}
	void toggle() {
		if(state) {
			state = false;
			valve.close();
		}
		else {
			state = true;
			valve.open();
		}
	}
};
class GateValve: public Valve {
	public:
	void open() override {std::cout << "GateValve opened\n";}
	void close() override {std::cout << "GateValve closed\n";}
};
class BallValve: public Valve {
	public:
	void open() override {std::cout << "BallValve opened\n";}
	void close() override {std::cout << "BallValve closed\n";}
};
class CheckValve: public Valve {
	public:
	void open() override {std::cout << "CheckValve opened\n";}
	void close() override {std::cout << "CheckValve closed\n";}
};
int main(int argc, char** argv)
{
	GateValve gv;
	ValveServo servo_one(gv);
	servo_one.toggle();
	servo_one.toggle();
	return 0;
}