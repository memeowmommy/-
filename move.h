#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
using namespace std;
using namespace sf;

namespace lol 
{
    class player 
    { 
    public:
        float m_x, m_y, m_w, m_h, m_vx, m_vy, m_speed = 0;
        int dir = 0;
        int m_location = 0;
        String m_name;
        Texture texture;
        Sprite sprite;
        String m_Hero_name;
        player() {}
        player(int x, int y, int w, int h, String name, int location) 
        {
            m_x = x;
            m_y = y;
            m_w = w;
            m_h = h;
            m_name = name;
           // m_Hero_name = Hero_name;
            m_location = location;
            texture.loadFromFile("assets/" + name);
            sprite.setTexture(texture);
            sprite.setTextureRect(IntRect(0, 0, m_w, m_h));
            sprite.setPosition(m_x, m_y);
        }
        bool flag = false;
        bool flag1 = true;
        bool perehod(int y, int h) 
        {
            bool flag = false;
            bool flag1 = true;
            if ((m_y <= 0) && (Keyboard::isKeyPressed(Keyboard::W)) && (flag == false) && (flag1 == true)) 
            {
                m_y = 900;
                flag = true;
                flag1 = false;
                m_location = 2;
                return true;
            }
            else 
            {
                flag1 = true;
                flag = false;
                return false;
            }
        }

        bool granics(int y, int h) 
        {
            if ((m_y + m_h >= 1080) && (Keyboard::isKeyPressed(Keyboard::S)) && (flag1 == false) && (flag == true)) 
            {
                m_y = 100;
                flag1 = true;
                flag = false;
                m_location = 1;
                return true;
            }
            else 
            {
                flag1 = false;
                flag = true;
                return false;
            }
        }

        void update(float time) 
        {
            switch (dir) 
            {
            case 0: m_vx = -m_speed; m_vy = 0; break;
            case 1: m_vx = m_speed; m_vy = 0; break;
            case 2: m_vx = 0; m_vy = -m_speed; break;
            case 3: m_vx = 0; m_vy = m_speed; break;
            }
            m_x = m_x + m_vx * time;
            m_y = m_y + m_vy * time;
            m_speed = 0;
            sprite.setPosition(m_x, m_y);
        }

        void stopped(int x, int w, int y, int h) 
        {
            if ((m_x + m_w >= 1900) && (Keyboard::isKeyPressed(Keyboard::D))) {m_speed = 0;}
            if ((m_x <= 10) && (Keyboard::isKeyPressed(Keyboard::A))) {m_speed = 0;}
            if ((m_y + m_h >= 1070) && (Keyboard::isKeyPressed(Keyboard::S)) && (m_location == 1)) {m_speed = 0;}
            if ((m_y <= 700) && (Keyboard::isKeyPressed(Keyboard::W)) && (m_location == 2)) { m_speed = 0;}
        }
    };

    class Textbox {
    public:
        Sprite textbox_sprite;
        float m1_x, m1_y, m1_w, m1_h = 0;
        String m_text;
        String m_name1;
        Texture textbox_texture;
        Font font;
        Textbox(int x1, int y1, int w1, int h1, String name1, String text) 
        {
            m1_x = x1;
            m1_y = y1;
            m1_w = w1;
            m1_h = h1;
            m_name1 = name1;
            m_text = text;
            String word;
            font.loadFromFile("assets/pixy.ttf");
            sf::Text text5;
            text5.setFont(font);
            text5.setCharacterSize(55);
            text5.setPosition(200, 700);
            textbox_texture.loadFromFile("assets/" + name1);
            textbox_sprite.setTexture(textbox_texture);
            text5.setString(text); 
        }
    };

    class npc : public player 
    {
    public:
        float npc_x, npc_y, npc_w, npc_h = 0;
        String npc_name;
        Texture npc_texture;
        Sprite npc_sprite;
        npc(int x, int y, int w, int h, String name, int location) 
        {
            npc_x = x;
            npc_y = y;
            npc_w = w,
            npc_h = h;
            npc_name = name;
            npc_texture.loadFromFile("assets/" + name);
            npc_sprite.setTexture(npc_texture);
            npc_sprite.setPosition(npc_x, npc_y);
        }

        bool say() 
        {
            if (((npc_x + npc_w) > m_x) || (m_x < (npc_x - 10))) 
            {
                cout << "5" << endl;
                return false;
            }
            else { return true;}
        }
    };
}

