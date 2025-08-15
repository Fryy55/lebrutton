#include <Geode/Geode.hpp>

#include "geode.custom-keybinds/include/Keybinds.hpp"

#include "SunshineEvent.hpp"

using namespace geode::prelude;
using namespace keybinds;


$on_mod(Loaded) {
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
		Mod::get()->setSettingValue("general-pause-menu", true);
		Mod::get()->setSettingValue("general-editor-pause-menu", true);

		log::info("Custom Keybinds isn't on; keybind features disabled.");
	}
}