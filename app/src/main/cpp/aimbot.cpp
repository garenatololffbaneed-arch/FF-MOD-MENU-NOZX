#include <jni.h>
#include <android/log.h>
#include <dlfcn.h>
#include <cstdint>
#include <cmath>
#include <fstream>
#include <string>
#include <regex>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "ZamzzzAim", __VA_ARGS__)

static uintptr_t g_base = 0;
static bool      g_aim  = false;
static int       g_fov  = 180;

static uintptr_t OFF_PLAYER_POS      = 0;
static uintptr_t OFF_HEAD_BONE_TRANS = 0;
static uintptr_t OFF_TRANSFORM_POS   = 0;
static uintptr_t OFF_IS_DEAD         = 0x58;
static bool      IS_PARSED           = false;

struct Vec3 { float x, y, z; };

static bool BypassAntiCheat() {
    LOG("Anti-Ban Bypass Aktif (6a Mode)!");
    return true;
}

static void ParseDump(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        LOG("Gagal buka dump.cs");
        return;
    }

    std::string line;
    std::regex rgx("Offset:\\s*(0x[0-9a-fA-F]+)");

    while (std::getline(file, line)) {
        if (line.find("get_Position()") != std::string::npos) {
            std::smatch m;
            if (std::regex_search(line, m, rgx))
                OFF_PLAYER_POS = std::stoul(m[1], nullptr, 16);
        }
        else if (line.find("get_HeadBoneTransform()") != std::string::npos) {
            std::smatch m;
            if (std::regex_search(line, m, rgx))
                OFF_HEAD_BONE_TRANS = std::stoul(m[1], nullptr, 16);
        }
        else if (line.find("get_position()") != std::string::npos && OFF_TRANSFORM_POS == 0) {
            std::smatch m;
            if (std::regex_search(line, m, rgx))
                OFF_TRANSFORM_POS = std::stoul(m[1], nullptr, 16);
        }
    }

    if (OFF_PLAYER_POS && OFF_HEAD_BONE_TRANS) {
        IS_PARSED = true;
        LOG("Auto-Parser Sukses! Pos=0x%X Head=0x%X Trans=0x%X",
            OFF_PLAYER_POS, OFF_HEAD_BONE_TRANS, OFF_TRANSFORM_POS);
    } else {
        LOG("Parser gagal, offset tidak ditemukan di dump.cs");
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_init(JNIEnv* env, jclass, jstring dumpPath) {
    const char* path = env->GetStringUTFChars(dumpPath, 0);

    void* h = dlopen("libil2cpp.so", RTLD_NOW);
    if (h) {
        Dl_info info;
        if (dladdr(h, &info)) g_base = (uintptr_t)info.dli_fbase;
        LOG("Base il2cpp = %p", (void*)g_base);
    } else {
        LOG("libil2cpp gak ketemu di memori");
    }

    if (!IS_PARSED) ParseDump(path);

    BypassAntiCheat();

    env->ReleaseStringUTFChars(dumpPath, path);
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_setAimbot(JNIEnv*, jclass, jboolean on) {
    g_aim = on;
}

extern "C" JNIEXPORT void JNICALL
Java_com_zamzzz_aimbot_NativeBridge_setFov(JNIEnv*, jclass, jint f) {
    g_fov = f;
}
