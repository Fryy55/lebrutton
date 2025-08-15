#include <Geode/modify/PauseLayer.hpp>

#include "SunshineEvent.hpp"

using namespace geode::prelude;


class $modify(PauseLayer) {
	$override
	void customSetup() {
		PauseLayer::customSetup();

		if (!Mod::get()->getSettingValue<bool>("general-pause-menu"))
			return;

		auto lebruttonSpr = CircleButtonSprite::createWithSpriteFrameName(
			"sunshine-small.png"_spr,
			1.f,
			CircleBaseColor::Green,
			CircleBaseSize::Small
		);
		lebruttonSpr->setScale(0.8f);
		auto lebrutton = CCMenuItemExt::createSpriteExtra(
			lebruttonSpr,
			[](CCMenuItemSpriteExtra*) {
				SunshineEvent().post();
			}
		);
		lebrutton->setID("lebrutton"_spr);

		auto menu = this->getChildByID("right-button-menu");
		menu->addChild(lebrutton);
		menu->updateLayout();

		return;
	}
};