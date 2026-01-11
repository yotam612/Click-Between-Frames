#define GEODE_DEFINE_EVENT_EXPORTS
#include <cbf/api.hpp>

#include "includes.hpp"

#if defined(GEODE_IS_WINDOWS)
extern void updateKeybinds();
#endif

extern std::deque<struct Step> stepQueue;

geode::Result<> cbf_api::clearHeldInputs() {
    heldInputs.clear();
    return geode::Ok();
}

geode::Result<> cbf_api::refreshKeybindCache() {
#if defined(GEODE_IS_WINDOWS)
    updateKeybinds();
#endif
    return geode::Ok();
}

geode::Result<> cbf_api::clearInputQueues() {
    std::lock_guard<std::mutex> g(inputQueueLock);

    inputQueue.clear();
    inputQueueCopy.clear();
    stepQueue.clear();

    return geode::Ok();
}
