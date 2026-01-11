#pragma once
#include <Geode/loader/Dispatch.hpp>

// Public API for other mods.
// Exported via GEODE_EVENT_EXPORT so optional dependencies can call it.

namespace cbf_api {
    geode::Result<> clearHeldInputs()
        GEODE_EVENT_EXPORT(&clearHeldInputs, ());

    geode::Result<> refreshKeybindCache()
        GEODE_EVENT_EXPORT(&refreshKeybindCache, ());

    // optional but recommended to avoid stale events mapped with old binds
    geode::Result<> clearInputQueues()
        GEODE_EVENT_EXPORT(&clearInputQueues, ());
}
