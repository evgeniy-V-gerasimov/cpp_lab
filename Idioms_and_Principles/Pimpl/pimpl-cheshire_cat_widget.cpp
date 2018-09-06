#include "pimpl_cheshire_cat_widget.hpp"

class Widget::WidgetImpl final{
	
	public:
	WidgetImpl(): x(42), y(83) {std::cout << "ctor: WidgetImpl() \n";}
	~WidgetImpl() {std::cout << "dtor: ~WidgetImpl() \n";}
	int sum() const;
	private:
		int x;
		int y;
};
int Widget::WidgetImpl::sum() const {
	return x+y;
}

Widget::Widget() : ptrtoimpl{std::make_unique<Widget::WidgetImpl>()} {}
Widget::~Widget() = default;

int Widget::sum() const {
	return ptrtoimpl->sum();
}