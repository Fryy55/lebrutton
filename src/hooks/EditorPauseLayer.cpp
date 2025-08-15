#include <Geode/modify/EditorPauseLayer.hpp>

#include "SunshineEvent.hpp"

using namespace geode::prelude;


class $modify(EditorPauseLayer) {
	$override
	bool init(LevelEditorLayer* lel) {
		if (!EditorPauseLayer::init(lel))
			return false;

		if (!Mod::get()->getSettingValue<bool>("general-editor-pause-menu"))
			return true;

		auto lebrutton = CCMenuItemExt::createSpriteExtra(
			CircleButtonSprite::createWithSpriteFrameName(
				"sunshine-small.png"_spr,
				1.f,
				CircleBaseColor::Green,
				CircleBaseSize::Small
			),
			[](CCMenuItemSpriteExtra*) {
				SunshineEvent().post();
			}
		);
		lebrutton->setID("lebrutton"_spr);

		auto menu = this->getChildByID("guidelines-menu");
		menu->addChild(lebrutton);
		menu->updateLayout();

		return true;
	}
};