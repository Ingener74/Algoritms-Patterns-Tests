/*
 * Main.cpp
 *
 *  Created on: May 19, 2014
 *      Author: pavel
 */

#include <iostream>

#include "Main.h"

JNIEXPORT void JNICALL Java_com_shnaider_Main_start
(JNIEnv *, jobject)
{
    std::cout << "Main start called" << std::endl;
}

