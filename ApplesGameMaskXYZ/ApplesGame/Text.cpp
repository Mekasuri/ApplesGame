#include "Text.h"
#include "Settings.h"
#include <cassert>
namespace ApplesGame {
	void LableInitialization(Label& label) {
        assert(label.textFont.loadFromFile(RESOURCES_PATH + "/Pacmania.otf"));
        label.text.setFont(label.textFont);
        label.text.setCharacterSize(label.textSize);
        label.text.setString(label.message);
        label.text.setPosition(label.position.x, label.position.y);
        label.text.setFillColor(label.color);
	}
}