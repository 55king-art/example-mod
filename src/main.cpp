#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

void forcePurgeGarbageMemory() {
    auto textureCache = CCTextureCache::sharedTextureCache();
    if (textureCache) {
        textureCache->removeUnusedTextures();
    }
}

class $modify(MyMemoryFixPlayLayer, PlayLayer) {
    bool init(GJGameLevel* p0, bool p1, bool p2) {
        if (!PlayLayer::init(p0, p1, p2)) return false;
        forcePurgeGarbageMemory();
        return true;
    }

    void resetLevel() {
        PlayLayer::resetLevel();
        forcePurgeGarbageMemory();
    }
    
    void onQuit() {
        PlayLayer::onQuit();
        forcePurgeGarbageMemory();
    }
};

class $modify(MyMemoryFixMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        forcePurgeGarbageMemory();
        return true;
    }
};
