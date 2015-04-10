/*
 * SwigFoo.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: pavel
 */

#include <iostream>

#include "SwigFoo.h"

using namespace std;

SwigBaz::SwigBaz() {
}

SwigBaz::~SwigBaz() {
}

void SwigBaz::testMe() {
    cout << __func__ << endl;
}

SwigBar::SwigBar() {
}

SwigBar::~SwigBar() {
}

void SwigBar::printBar() const {
    cout << __FUNCTION__ << endl;
}

SwigBaz* SwigBar::getBaz() {
    return &baz;
}

SwigFoo::SwigFoo() {
}

SwigFoo::~SwigFoo() {
}

SwigBar* SwigFoo::getBar() {
    return &bar;
}

