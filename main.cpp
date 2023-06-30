#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <chrono>
#include "move.h"
#include "menu.h"
#include "locale.h"

using namespace sf;
float kadr = 1; // кадр анимации

int main()
{
    setlocale(LC_ALL, "RUS");

    //MENU window
    RenderWindow MENU(VideoMode(1920, 1080),L"Меню");
    Menu menu(MENU.getSize().x, MENU.getSize().y);
    Music Intro;
    Music Sound;
    Texture menubg;
    menubg.loadFromFile("assets/menubg.png");
    Sprite bg;
    bg.setTexture(menubg);

    if (!Intro.openFromFile("assets/intro.ogg")) { cout << L"Файл не найден :(" << endl; }
    if (!Sound.openFromFile("assets/sound.ogg")) { cout << L"Файл не найден :(" << endl; }
    // MUSIC FROM MENU
    Intro.play(); 
    Intro.setLoop(true);
    while (MENU.isOpen())
    {
        Sound.play(); //playing while game and about
        Sound.setLoop(true);
        Event event;
        while (MENU.pollEvent(event))
        {  
            if (event.type == Event::Closed) { MENU.close();}

            if (event.type == Event::KeyPressed)
            {
                if ((event.key.code == Keyboard::W)||(event.key.code == Keyboard::Up))
                {
                    menu.MoveUp();
                    break;
                }
                if ((event.key.code == Keyboard::S)||(event.key.code == Keyboard::Down))
                {
                    menu.MoveDown();
                    break;
                }
                
                if (event.key.code == Keyboard::Return)
                {
                    RenderWindow Game(VideoMode(1920, 1080), L"Мир Висельника");
                    Texture texture; // фон game
                    Sprite Fon;
                    texture.loadFromFile("assets/pink.png");
                    Fon.setTexture(texture);

                    RenderWindow About(VideoMode(1920, 1080), L"Подробнее об игре");
                    Texture tt; // фон about game
                    Sprite bgAbout;
                    tt.loadFromFile("assets/about.png");
                    bgAbout.setTexture(tt);

                    int x = menu.pressed();
                    Intro.stop();
                    if (x == 0) 
                    {
                        lol::player GG (950, 600, 96, 160, "gg.png", 1); //локация гг х и у
                        lol::npc npc(500, 300, 36, 82, "npc.png", 1);
                        
                        Texture textbox_texture;
                        Sprite textbox_sprite;
                        textbox_texture.loadFromFile("assets/Box.png");
                        textbox_sprite.setTexture(textbox_texture);

                        Font font;
                        if (!font.loadFromFile("assets/pixy.ttf")) { cout << L"Файл не найден :(" << endl; }

                        Text text;
                        text.setFont(font);
                        text.setString(L"Лирэ");
                        text.setCharacterSize(70);
                        text.setPosition(155, 680);

                        Text text1;
                        text1.setFont(font);
                        text1.setString(L"ertalalla");

                        text1.setCharacterSize(55);
                        text1.setPosition(200, 800);

                        Clock clock;
                        
                        while (Game.isOpen()) 
                        {   
                            float time = clock.getElapsedTime().asMicroseconds();
                            clock.restart();
                            time = time / 1500;
                            Event aevent;
                            while (Game.pollEvent(aevent))
                            { 
                                if (aevent.type == Event::Closed)  {Game.close(); }
                                if (aevent.type == Event::KeyPressed)  
                                { if (aevent.key.code == Keyboard::Escape) { Game.close(); } }
                            }
                           
                            GG.stopped(1000, 48*2, 80*2, 800);
                            npc.stopped(1000, 36*2, 82*2, 800);

                            GG.update(time);
                            if (Keyboard::isKeyPressed(Keyboard::A)) {
                                GG.dir = 0;
                                GG.m_speed = 0.3;
                                kadr = kadr + 0.01 * time;
                                if (kadr > 4) {
                                    kadr = kadr - 4;
                                }
                                GG.sprite.setTextureRect(IntRect(48*2 * int(kadr), 240*2, 48*2, 80*2));
                            }
                            else if (Keyboard::isKeyPressed(Keyboard::D)) {
                                GG.dir = 1;
                                GG.m_speed = 0.3;
                                kadr = kadr + 0.01 * time;
                                if (kadr > 4) {
                                    kadr = kadr - 4;
                                }
                                GG.sprite.setTextureRect(IntRect(48*2 * int(kadr), 160*2, 48*2, 80*2));
                            }
                            else if (Keyboard::isKeyPressed(Keyboard::W)) {
                                GG.dir = 2;
                                GG.m_speed = 0.3;
                                kadr = kadr + 0.01 * time;
                                if (kadr > 4) {
                                    kadr = kadr - 4;
                                }
                                GG.sprite.setTextureRect(IntRect(48 *2* int(kadr), 80*2, 48*2, 80*2));
                            }
                            else if (Keyboard::isKeyPressed(Keyboard::S)) {
                                GG.dir = 3;
                                GG.m_speed = 0.3;
                                kadr = kadr + 0.01 * time;
                                if (kadr > 4) {
                                    kadr = kadr - 4;
                                }
                                GG.sprite.setTextureRect(IntRect(48 *2* int(kadr), 0, 48*2, 80*2));
                            }
                            if (GG.perehod(80, 800)) {
                                Sprite Pink;
                                texture.loadFromFile("assets/bg2.png");
                                Pink.setTexture(texture);
                                Game.clear();
                                Game.draw(Pink);
                                Game.draw(GG.sprite);
                                npc.npc_sprite.setPosition(-205, -30);

                            }
                            if (GG.granics(80, 800)) {
                                texture.loadFromFile("assets/pink.png");
                                Fon.setTexture(texture);
                                Game.clear();
                                Game.draw(Fon);
                                Game.draw(GG.sprite);
                                npc.npc_sprite.setPosition(30, 450);
                                Game.draw(npc.npc_sprite);
                            }

                            lol::Textbox Box(100, 500, 800, 300, "Box1.png", "HELP ME");
                            vector<string> talk = { "Hello", "How are you?", "Im not Fine",  "Why", "Matan" };

                            float k = 0;
                            if ((Keyboard::isKeyPressed(Keyboard::E)) && (npc.say() == false)) 
                            {
                                GG.m_speed = 0;
                                cout << "rok" << endl;
                                Game.draw(Box.textbox_sprite);
                                Game.draw(text);
                                Game.display();
                                while ((k < 5)) {
                                    Game.draw(Box.textbox_sprite);
                                    Game.draw(text);
                                    if (Keyboard::isKeyPressed(Keyboard::Q)) {
                                        text1.setString(talk[k]);
                                        Game.draw(text1);
                                        Game.display();
                                        k = k + 0.24;
                                    }
                                }
                            }

                            About.close();
                            Intro.play(); // MUSIC FROM MENU IS PLAYING AGAIN
                            Game.clear();
                            Game.draw(Fon);
                            Game.draw(npc.npc_sprite);
                            Game.draw(GG.sprite);
                            Game.display();
                        }  
                    }

                    if (x == 1)
                    {
                        while (About.isOpen())
                        {
                            Event aevent;
                            while (About.pollEvent(aevent))
                            {
                                if (aevent.type == Event::Closed) { About.close(); }
                                if (aevent.type == Event::KeyPressed)
                                {if (aevent.key.code == Keyboard::Escape) { About.close();} }
                            }
                            
                            Game.close();
                            Intro.play(); // MUSIC FROM MENU IS PLAYING AGAIN
                            About.clear();
                            About.draw(bgAbout);
                            About.display(); 
                        }
                    }

                    if (x == 2) { MENU.close(); }
                }
            }
        }
        MENU.clear();
        MENU.draw(bg); //bg first!
        menu.draw(MENU);
        MENU.display();
    }  
}