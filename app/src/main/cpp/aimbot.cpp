#include <jni.h>
#include <android/log.h>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "ZamzzzAim", __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_init(JNIEnv* env, jclass clazz, jstring dumpPath) {
    LOG("Init Berhasil! Parser siap.");
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_setAimbot(JNIEnv* env, jclass clazz, jboolean on) {
    LOG("Aimbot Status: %d", on);
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_setFov(JNIEnv* env, jclass clazz, jint fov) {
    LOG("FOV set ke: %d", fov);
}
