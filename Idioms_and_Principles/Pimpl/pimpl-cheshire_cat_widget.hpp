#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <memory>
#include <iostream>

class Widget {
	public:
		Widget();
		virtual ~Widget();
		int sum() const;
	private:
		class WidgetImpl;
		std::unique_ptr<WidgetImpl> ptrtoimpl;
};
#endif // WIDGET_HPP