#pragma once

#include "Drawable.hpp"

namespace Eligos
{
// ! Reste a coder les collisions
// ! Reste a coder les pv
// ! Reste a coder les degat
// ! fin de partie
// ! Reste a coder les mort
// ! Reste a coder les missiles

enum input_keys
{
    UNKNOW, //0
    Q,      //1
    W,      //2
    E,      //3
    A,      //4
    S,      //5
    D,      //6
    SPACE,  //7
    DIAG_1, //8
    DIAG_2, //9
    DIAG_3, //10
    DIAG_4, //11
    LEFT,   //12
    UP,     //13
    RIGHT,  //14
    DOWN    //15
};

class RendererAPI
{
public:
    enum class API_TYPE
    {
        NONE,
        SFML
    };
    virtual ~RendererAPI() = default;
    inline static API_TYPE getAPI() { return m_Api; };
    virtual void setWindowSize(unsigned int, unsigned int) = 0;
    virtual void setWindowFrameRate(unsigned int widht) = 0;
    virtual void ClearScreen() = 0;
    virtual void setClearColor(int r, int g, int b) = 0;
    virtual void Draw(Drawable::Object *) = 0;
    virtual void Display(void) = 0;
    virtual bool isClose() = 0;
    virtual input_keys getInput() = 0;
    // virtual sf::RenderWindow &getWindow() const = 0;

private:
    static API_TYPE m_Api;
    };
}