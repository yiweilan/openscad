#include "circle.h"

namespace libsvg {

const std::string circle::name("circle");

circle::circle() : r(0)
{
}

circle::~circle()
{
}

void
circle::set_attrs(attr_map_t& attrs)
{
	shape::set_attrs(attrs);
	this->x = parse_double(attrs["cx"]);
	this->y = parse_double(attrs["cy"]);
	this->r = parse_double(attrs["r"]);
	
	path_t path;
	draw_ellipse(path, get_x(), get_y(), get_radius(), get_radius());
	path_list.push_back(path);
}

const std::string
circle::dump() const
{
	std::stringstream s;
	s << get_name()
		<< ": x = " << this->x
		<< ": y = " << this->y
		<< ": r = " << this->r;
	return s.str();
}

}