package com.mtzijin.androidtcpdumpsdk;

public class TcpDumpInterface {
	static{
		  System.loadLibrary("tcpdumpinterface"); 
	}
	
	public native void cinit();
	public native void cstart();
	public native void cfinal();
	
	
	public void cInit()
	{
		cinit();
	}
	
	public void cStart()
	{
		cinit();
	}
	
	public void cFinal()
	{
		cinit();
	}
}
