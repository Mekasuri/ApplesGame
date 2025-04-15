#include "Sounds.h"
#include "Settings.h"
#include <cassert>
namespace ApplesGame {
	void SoundInitialization(Sound& sound, std::string soundName) {
		assert(sound.buffer.loadFromFile(RESOURCES_PATH + soundName));
		sound.sound.setBuffer(sound.buffer);
	}
}