#pragma once

#include <iostream>
#include "Engine/RendererEngine/SFML/ISound.hpp"
#include "Component.hpp"

class AudioComponent : public Components
{
public:
    enum type_audio {SOUND, MUSIC};
    type_audio m_type;
    Eligos::IAudio *audio;
public:
    AudioComponent() = default;
    AudioComponent(std::size_t id) : Components(id, getCompId()){};
    virtual ~AudioComponent() = default;
    static Components *Create(const std::size_t &id) { return new AudioComponent(id); };
    virtual void modify(const std::string str) {
        if (str.find("Sound") != std::string::npos)
            audio = new Eligos::SfmlSound();
        else
        {
            audio = new Eligos::SfmlMusic();
        }
        std::cout << "--------------------------------------------------" << std::endl;
        audio->load(str);
        audio->Play();
    }
    virtual void dump() {}
    virtual Components *clone() { return new AudioComponent(*this); }
    std::size_t  getEntityId() const { return m_entityId; }
    static std::size_t getCompId() { return 6; };
};