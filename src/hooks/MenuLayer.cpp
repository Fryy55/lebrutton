#include <Geode/modify/MenuLayer.hpp>

#include "SunshineEvent.hpp"

using namespace geode::prelude;


class $modify(MenuLayer) {
	$override
	bool init() {
		if (!MenuLayer::init())
			return false;

		if (!Mod::get()->getSettingValue<bool>("general-main-menu"))
			return true;

		auto lebrutton = CCMenuItemExt::createSpriteExtra(
			CircleButtonSprite::createWithSpriteFrameName(
				"sunshine-small.png"_spr,
				1.f,
				CircleBaseColor::Green,
				CircleBaseSize::MediumAlt
			),
			[](CCMenuItemSpriteExtra*) {
				SunshineEvent().post();
			}
		);
		lebrutton->setID("lebrutton"_spr);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(lebrutton);
		menu->updateLayout();

		return true;
	}
};