/*
 * SwigFoo.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: pavel
 */

#include <iostream>

#include "SwigFoo.h"

using namespace std;

SwigBar::SwigBar() {
}

SwigBar::~SwigBar() {
}

void SwigBar::print() const {
    cout << __FUNCTION__ << endl;
    cout << __func__ << endl;
}

SwigFoo::SwigFoo() {
}

SwigFoo::~SwigFoo() {
}

const SwigBar& SwigFoo::getBar() const {
    return bar;
}
