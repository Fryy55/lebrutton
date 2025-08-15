#include <Geode/Geode.hpp>

#include "geode.custom-keybinds/include/Keybinds.hpp"

#include "WideTitleV3.hpp"
#include "SunshineEvent.hpp"
#include "SunshineJumpscare.hpp"

using namespace geode::prelude;
using namespace keybinds;


$on_mod(Loaded) {
	// settings
	(void)Mod::get()->registerCustomSettingType("wide-title", WideTitleV3::parse);

	// my events
	new EventListener<EventFilter<SunshineEvent>>(+[](SunshineEvent*) {
		if (Mod::get()->getSettingValue<bool>("lebrutton-text")) {
			clipboard::write("lebron");

			if (auto lel = LevelEditorLayer::get()) {
				auto objLayer = lel->m_objectLayer;

				auto label = static_cast<TextGameObject*>(lel->createObject(
					914,
					(CCDirector::get()->getWinSize() / 2.f - objLayer->getPosition())
					/
					objLayer->getScale(),
					false
				));
				label->updateTextObject("lebron", false);
				label->m_baseColor->m_colorID = 1011;
			}
		}

		if (Mod::get()->getSettingValue<bool>("lebrutton-sound")) {
			FMODAudioEngine::get()->playEffect("the-broadway.mp3"_spr);
		}

		if (Mod::get()->getSettingValue<bool>("lebrutton-pic")) {
			SunshineJumpscare::create()->show();
		}

		return ListenerResult::Stop;
	});


	// keybinds
	if (
		auto customKeybinds = Loader::get()->getInstalledMod("geode.custom-keybinds");
		customKeybinds && customKeybinds->shouldLoad()
	) {
		Mod::get()->setSavedValue("keyrings-on", true);



		BindManager::get()->registerBindable({
			"lebrutton"_spr,
			"lebron keyring",
			"<cc>le Lebrutton.</c>",
			{ Keybind::create(KEY_L, Modifier::None) },
			Category::GLOBAL,
			Mod::get()->getSettingValue<bool>("keyring-toggle-repeat")
		});

		new EventListener(+[](InvokeBindEvent* event) {
			if (event->isDown())
				SunshineEvent().post();

			return ListenerResult::Propagate;
		}, InvokeBindFilter(nullptr, "lebrutton"_spr));
	} else {
		Mod::get()->setSavedValue("keyrings-on", false);
		// set settings if no keyrings
		Mod::get()->setSettingValue("general-main-menu", true);

		log::info("Custom Keybinds isn't on; keybind features disabled.");
	}
}