#pragma once

#include <Geode/cocos/sprite_nodes/CCSprite.h>


class SunshineJumpscare final : public cocos2d::CCSprite {
public:
	static SunshineJumpscare* create();

private:
	bool init() override;

public:
	void show();
};