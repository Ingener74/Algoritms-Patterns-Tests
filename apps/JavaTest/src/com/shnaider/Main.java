package com.shnaider;

import java.io.Console;

public class Main {
	
	static{
		System.loadLibrary("test_jni");
	}
	private native static void start();

	public static void main(String[] args) {
		System.out.print("Hello\n");
		
		start();
		
		System.out.print("Bye\n");
	}

}
