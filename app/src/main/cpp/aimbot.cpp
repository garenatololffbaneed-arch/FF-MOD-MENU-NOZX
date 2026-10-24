#include <jni.h>
#include <android/log.h>
#include <dlfcn.h>
#include <fstream>
#include <string>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "ZamzzzAim", __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_init(JNIEnv* env, jclass, jstring dumpPath) {
    LOG("Init Berhasil!");
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_setAimbot(JNIEnv*, jclass, jboolean on) {
    LOG("Aimbot: %d", on);
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_setFov(JNIEnv*, jclass, jint fov) {
    LOG("FOV: %d", fov);
}
