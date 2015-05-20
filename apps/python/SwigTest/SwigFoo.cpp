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

void A::testA() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void B::testB() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void C::testC() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void D::testD() {
    cout << __PRETTY_FUNCTION__ << endl;
}

void E::testE(B*) {
    cout << __PRETTY_FUNCTION__ << endl;

}

void F::testF(C*) {
    cout << __PRETTY_FUNCTION__ << endl;
}

void T::testT(D*) {
    cout << __PRETTY_FUNCTION__ << endl;
}
