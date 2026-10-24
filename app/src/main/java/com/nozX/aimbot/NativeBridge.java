package com.zamzzz.aimbot;

public class NativeBridge {
    static {
        System.loadLibrary("aimbot");
    }
    public static native void init(String dumpPath);
    public static native void setAimbot(boolean on);
    public static native void setFov(int fov);
  }
