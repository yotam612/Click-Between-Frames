#pragma once

#include "includes.hpp"

#include <vector>

// Public API exported for other mods via Geode events.
GEODE_EVENT_EXPORT void refreshKeybindCache();
GEODE_EVENT_EXPORT void clearHeldInputs();
GEODE_EVENT_EXPORT void clearHeldInputsForKeys(std::vector<uint16_t> const& keys);
GEODE_EVENT_EXPORT void clearInputQueues();
GEODE_EVENT_EXPORT void injectInput(PlayerButton button, bool down, TimestampType timestamp, bool isPlayer1 = true);
