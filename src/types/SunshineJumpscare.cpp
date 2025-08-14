#include "SunshineJumpscare.hpp"

using namespace geode::prelude;


SunshineJumpscare* SunshineJumpscare::create() {
	auto ret = new SunshineJumpscare;

	if (ret->init()) {
		ret->autorelease();
		return ret;
	}

	delete ret;
	return nullptr;
}

bool SunshineJumpscare::init() {
	if (!CCSprite::initWithSpriteFrameName("sunshine.png"_spr))
		return false;

	this->setID("SunshineJumpscare"_spr);


	this->setZOrder(20522); // gamer said so
	auto winSize = CCDirector::get()->getWinSize();
	this->setScale(winSize.height / this->getContentHeight());
	this->CCNode::setPosition(winSize.width / 2.f, 0.f);
	this->setAnchorPoint({ 0.5f, 0.f });

	return true;
}

void SunshineJumpscare::show() {
	SceneManager::get()->keepAcrossScenes(this);

	this->runAction(
		CCSequence::create(
			CCDelayTime::create(1.5f),
			CCFadeOut::create(1.5f),
			CallFuncExt::create(
				[this]() {
					SceneManager::get()->forget(this);
				}
			),
			CCRemoveSelf::create(),
			nullptr
		)
	);

	return;
}