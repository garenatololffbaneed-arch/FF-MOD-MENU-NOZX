package com.zamzzz.aimbot;

public class NativeBridge {
    static {
        // Load library C++ yang bakal di-compile dari aimbot.cpp
        System.loadLibrary("aimbot");
    }
    
    // Method ini yang dipanggil dari MainActivity
    public static native void init(String dumpPath);
    public static native void setAimbot(boolean on);
    public static native void setFov(int fov);
}
