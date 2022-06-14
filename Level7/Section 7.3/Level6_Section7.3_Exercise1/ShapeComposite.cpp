#ifndef SHAPE_COMPOSITE_CPP
#define SHAPE_COMPOSITE_CPP
#include "ShapeComposite.h"

//constructors and assignment operator:
template<template<typename, typename> typename Container>
ShapeComposite<Container>::ShapeComposite(const ShapeComposite& s){
	for (std::shared_ptr<Shape> elem : s) {
		this->AddShape(elem->Clone());
	}
}; //public copy constructor



template<template<typename, typename> typename Container>
ShapeComposite<Container>& ShapeComposite<Container>::operator=(const ShapeComposite& pt){
	ShapeComposite newComposite(pt);
	return newComposite;
};  // Assignment operator



//Add shape
template<template<typename, typename> typename Container>
void ShapeComposite<Container>::AddShape(std::shared_ptr<Shape> s) {
	shapeList.emplace_back(s); //add shape to list 
}



//Iterators
template<template<typename, typename> typename Container>
typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::iterator ShapeComposite<Container>::begin() {
	return shapeList.begin();
}
template<template<typename, typename> typename Container>
typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::iterator ShapeComposite<Container>::end() {
	return shapeList.end();
}
template<template<typename, typename> typename Container>
typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::const_iterator ShapeComposite<Container>::begin() const{
	return shapeList.begin();
}
template<template<typename, typename> typename Container>
typename Container<std::shared_ptr<Shape>, std::allocator<std::shared_ptr<Shape>>>::const_iterator ShapeComposite<Container>::end() const {
	return shapeList.end();
}



//Coutn elems
template<template<typename, typename> typename Container>
std::size_t ShapeComposite<Container>::count() {
	return shapeList.size();
}


//Print function overload:
template<template<typename, typename> typename Container>
std::ostream& ShapeComposite<Container>::out(std::ostream& o) const
{
	for (auto elem : *this) {
		o << *elem;
	}
	return o;
}



//clone function overload
template<template<typename, typename> typename Container>
std::shared_ptr<Shape> ShapeComposite<Container>::Clone() {
	ShapeComposite s(*this);
	return std::make_shared<ShapeComposite>(s);
}; //clone function calls copy constructor

#endif