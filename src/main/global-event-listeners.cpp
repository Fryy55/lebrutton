#include <Geode/Geode.hpp>

#include "SunshineEvent.hpp"
#include "SunshineJumpscare.hpp"
#include "utils/random.hpp"

using namespace geode::prelude;


$on_mod(Loaded) {
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
			auto system = FMODAudioEngine::get()->m_system;
			FMOD::Sound* sound;
			FMOD::Channel* channel;

			system->createSound(
				// @geode-ignore(unknown-resource) ik what i'm doing trust
				(Mod::get()->getResourcesDir()/"the-broadway.mp3").string().c_str(),
				FMOD_DEFAULT, nullptr, &sound
			);
			system->playSound(sound, nullptr, false, &channel);
			channel->setVolume(FMODAudioEngine::get()->m_sfxVolume * 2.f);
		}

		if (Mod::get()->getSettingValue<bool>("lebrutton-pic")) {
			SunshineJumpscare::create()->show();
		}

		if (Mod::get()->getSettingValue<bool>("lebrutton-edit")) {
			if (utils::random(1, 100) == 55)
				utils::web::openLinkInBrowser("https://www.youtube.com/watch?v=_g0Bx6o58aE");
		}

		return ListenerResult::Stop;
	});
}