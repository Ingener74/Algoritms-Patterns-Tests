package com.shnaider;

import java.io.Console;

public class Main {
	
	static{
		System.load("modules/test_jni/libtest_jni.so");
	}
	private native static void start();

	public static void main(String[] args) {
		System.out.print("Hello\n");
		
		start();
		
		System.out.print("Bye\n");
	}

}
