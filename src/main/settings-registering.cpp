#include <Geode/Geode.hpp>

#include "settingsV3/WideTitleV3.hpp"

using namespace geode::prelude;


$on_mod(Loaded) {
	(void)Mod::get()->registerCustomSettingType("wide-title", WideTitleV3::parse);
}