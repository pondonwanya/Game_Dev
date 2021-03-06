#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <SFML/Audio.hpp>

#include "entity.h"
#include "Projectile.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickUp.h"
#include "background.h"
#include "background2.h"
#include "background3.h"
#include "warp.h"
#include "player.h"
#include "MainMenu.h"
#include "Header.h"

bool press;
string name1;
ifstream loadFile;
void score();

int main()

{
	int hightScore[5];
	// random part
	srand(time(NULL));

	// Varible
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::String name;
	float playerMovementSpeed = 1.5;
	float playerMovementSpeed2 = 2; 
	float playerMovementSpeed3 = 3;
	bool faceRight = 1;
	bool hpAlive = true;
	int counterRunning = 0;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;


	bool userName = false;
	bool MyScore = false;
	bool totalscore = false;
	bool mainmenu = true;
	bool state1 = false;
	bool state2 = false;
	bool state3 = false;
	bool lead = false;

	sf::RenderWindow window;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445, (sf::VideoMode::getDesktopMode().height / 2) - 480);

	window.create(sf::VideoMode(800, 600), "Game", sf::Style::Resize | sf::Style::Close);
	window.setPosition(centerWindow);


	//window.setKeyRepeatEnabled(true);

	window.setFramerateLimit(25);
	sf::Texture Sprite;
	Sprite.loadFromFile("png/Sprite.png");

	sf::Sprite playerSprite;
	playerSprite.setTexture(Sprite);
	playerSprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	playerSprite.setTextureRect(sf::IntRect(0, 1080, 641, 542));
	playerSprite.setOrigin(sf::Vector2f(playerSprite.getTexture()->getSize().x / 8, playerSprite.getTexture()->getSize().y / 2));

	sf::Texture background_main;
	background_main.loadFromFile("png/bgMainmenu.png");
	sf::Sprite bgButton;
	bgButton.setTexture(background_main);
	bgButton.setScale(0.5, 0.5);

	sf::Texture user;
	user.loadFromFile("png/user.png");
	sf::Sprite bguser;
	bguser.setTexture(user);
	bguser.setPosition(10, 4);

	sf::Font arial;
	arial.loadFromFile("arial/arial.ttf");
	Textbox textbox1(20, sf::Color::Black, false);
	textbox1.setFont(arial);
	textbox1.setPosition({ 256,207 });
	textbox1.setLimit(true, 10);

	sf::Font font2;
	font2.loadFromFile("chrusty-rock-font/ChrustyRock-ORLA.ttf");
	sf::Text text2("BULLET   DESTROYER", font2, 50);
	text2.setCharacterSize(65);
	text2.setFillColor(sf::Color::Cyan);
	text2.setPosition(50, 10);

	sf::Texture bullet;
	bullet.loadFromFile("png/powerbullet.png");
	sf::Sprite powerbullet;
	powerbullet.setTexture(bullet);
	/*powerbullet.setScale(0.5, 0.5);*/

	sf::Texture Potion;
	Potion.loadFromFile("png/coin01.png");

	sf::Texture hpbar;
	hpbar.loadFromFile("png/hp bar.png");
	sf::Sprite blood;
	blood.setTexture(hpbar);
	blood.setPosition(192, 22);

	sf::Texture Potion2;
	Potion2.loadFromFile("png/chest1.png");

	sf::Texture Potion3;
	Potion3.loadFromFile("png/Potion01.png");

	sf::Texture Powerup;
	Powerup.loadFromFile("png/powerup.png");

	sf::Texture fireBall;
	fireBall.loadFromFile("png/bullet.png");

	sf::Texture Enemy;
	Enemy.loadFromFile("png/EnemySprite.png");

	sf::Texture doorwarp;
	doorwarp.loadFromFile("png/door2.png");

	sf::Texture bg1;
	bg1.loadFromFile("png/bg3.png");

	sf::Texture bg2;
	bg2.loadFromFile("png/bg1.png");

	sf::Texture bg3;
	bg3.loadFromFile("png/bg2.png");


	// Cteate a graphical text to display
	sf::Font font;
	font.loadFromFile("karmatic/ka1.ttf");

	sf::Text text("BULLET   DESTROYER", font, 25);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(0, 0);

	sf::Text text1("Gill", font, 25);
	text1.setFillColor(sf::Color::Black);
	text1.setCharacterSize(20);
	text1.setPosition(0, 20);

	sf::Text texteiei;

	sf::SoundBuffer shot;
	shot.loadFromFile("png/1758.ogg");
	sf::Sound soundshot;
	soundshot.setBuffer(shot);

	sf::SoundBuffer bell;
	bell.loadFromFile("png/1102.ogg");
	sf::Sound soundcoint;
	soundcoint.setBuffer(bell);

	sf::SoundBuffer drink;
	drink.loadFromFile("png/1335.ogg");
	sf::Sound sounddrink;
	sounddrink.setBuffer(drink);

	sf::SoundBuffer hurt;
	hurt.loadFromFile("png/hurt.ogg");
	sf::Sound soundhurt;
	soundhurt.setBuffer(hurt);

	vector<int> scoreboard;

	// class Object
	class player Player1;
	Player1.sprite.setTexture(&Sprite);

	//Projectile Vector Arrey
	vector<projectile>::const_iterator(iter);
	vector<projectile> projectileArrey;

	//Projectile Object
	class projectile projectile1;
	projectile1.sprite.setTexture(&fireBall);

	//Enemy Vector Arrey
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArrey;

	//Enery Object
	class enemy enemy1;
	enemy1.sprite.setTexture(&Enemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0,0,32,32));

	enemy1.rect.setPosition(810, 610);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(-1, 620);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(820, -1);
	enemyArrey.push_back(enemy1);  
	enemy1.rect.setPosition(-10, 100);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(815, 660);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(805, -4);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(-15, 650);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(835, -3);
	enemyArrey.push_back(enemy1);
	enemy1.rect.setPosition(845, 620);
	enemyArrey.push_back(enemy1);

	//Enemy Vector Arrey
	vector<enemy>::const_iterator iter5;
	vector<enemy> enemyArrey2;

	//Enery Object
	class enemy enemy2;
	enemy2.sprite.setTexture(&Enemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0,0,32,32));

	enemy2.rect.setPosition(1500, 610);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-1000, 620);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1900, -10);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-10, 700);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(815, -30);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(805, -400);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(900, 670);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-1000, 690);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1800, -100);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-700, 700);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1500, -600);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(805, -400);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(900, 610);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-1000, 620);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1600, -300);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-400, 1000);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(855, -3);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1500, -400);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(810, 770);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-100, 620);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1300, -1000);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-1000, 100);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(815, -70);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(2600, -800);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-400, 620);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1200, -300);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-4000, 100);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(1600, -500);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(2300, -400);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(910, 1200);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-100, 820);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(2500, -900);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(-1000, 1000);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(2100, -700);
	enemyArrey2.push_back(enemy2);
	enemy2.rect.setPosition(855, -400);
	enemyArrey2.push_back(enemy2);

	//Enemy Vector Arrey
	vector<enemy>::const_iterator iter6;
	vector<enemy> enemyArrey3;

	//Enery Object
	class enemy enemy3;
	enemy3.sprite.setTexture(&Enemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0,0,32,32));

	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -3);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -4);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -3);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -4);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -3);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -4);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 800);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -300);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -400);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 840);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 900);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -300);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(1200, -400);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 900);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(920, -300);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -400);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(800, -100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1000, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -70);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(2600, -800);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-400, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(1200, -300);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-4000, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(1600, -500);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(2300, -400);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(910, 800);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 820);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(900, -900);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 950);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(2100, -700);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(855, -400);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -3);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -4);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -3);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -4);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-1, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 100);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -3);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -4);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 620);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-10, 900);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -300);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(805, -400);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(810, 610);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 900);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(820, -1);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(-100, 900);
	enemyArrey3.push_back(enemy3);
	enemy3.rect.setPosition(815, -300);
	enemyArrey3.push_back(enemy3);



	//Text Vector Arrey
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArrey;

	//Text Display Object
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);

	//Pickup Vector Arrey
	vector<pickUp>::const_iterator iter11;
	vector<pickUp> pickUpArrey;

	//Coin Object
	class pickUp pickUp1;
	pickUp1.sprite.setTexture(&Potion);
	pickUp1.rect.setPosition(500, 500);
	pickUp1.rect.setSize(sf::Vector2f(63.5, 64));
	pickUpArrey.push_back(pickUp1);

	pickUp1.rect.setPosition(600, 300);
	pickUpArrey.push_back(pickUp1);

	//Pickup Vector Arrey
	vector<pickUp>::const_iterator iter10;
	vector<pickUp> pickUpArrey2;

	//chest Object
	class pickUp pickUp2;
	pickUp2.sprite.setTexture(&Potion2);
	pickUp2.rect.setPosition(500, 230);
	pickUp2.rect.setSize(sf::Vector2f(32, 32));
	pickUpArrey2.push_back(pickUp2);

	//Pickup Vector Arrey
	vector<pickUp>::const_iterator iter9;
	vector<pickUp> pickUpArrey3;

	//Potion Object
	class pickUp pickUp3;
	pickUp3.sprite.setTexture(&Potion3);
	pickUp3.rect.setPosition(1200, 1200);
	pickUp3.rect.setSize(sf::Vector2f(48, 48));
	pickUpArrey3.push_back(pickUp3);

	//Pickup Vector Arrey
	vector<pickUp>::const_iterator iter13;
	vector<pickUp> pickUpArrey4;

	//Potion Object
	class pickUp pickUp4;
	pickUp4.sprite.setTexture(&bullet);
	pickUp4.rect.setPosition(1200, 1200);
	pickUp4.rect.setSize(sf::Vector2f(198, 198));
	pickUp4.sprite.setSize(sf::Vector2f(198, 198));
	pickUpArrey4.push_back(pickUp4);

	// background
	class background background1;
	background1.sprite.setTexture(&bg1);

	// background
	class background2 background2;
	background2.sprite.setTexture(&bg2);

	// background
	class background3 background3;
	background3.sprite.setTexture(&bg3);

	//doorwarp Vector Arrey
	vector<warp>::const_iterator iter2;
	vector<warp> warpArrey;

	//Potion Object
	class warp warp1;
	warp1.sprite.setTexture(&doorwarp);
	warp1.rect.setPosition(750, 250);
	warp1.rect.setSize(sf::Vector2f(96, 54));
	warpArrey.push_back(warp1);

	class MainMenu mainaaaaa(0, 0);

	sf::Text mainMenu1;
	sf::Text mainMenu2;
	sf::Text mainMenu3;
	sf::Text Name;
	sf::Text Score;
	//sf::Text Name;

	sf::Font font1;
	font1.loadFromFile("arial/arial.ttf");
	printf("Yoooooooooooooooooooooooo");
	//Play
	mainMenu1.setFont(font1);
	mainMenu1.setFillColor(sf::Color::Black);
	mainMenu1.setString("PLAY");
	mainMenu1.setCharacterSize(40);
	mainMenu1.setPosition(200, 150);

	//Score
	mainMenu2.setFont(font1);
	mainMenu2.setFillColor(sf::Color::Black);
	mainMenu2.setString("SCORE");
	mainMenu2.setCharacterSize(40);
	mainMenu2.setPosition(200, 220);

	//Play
	mainMenu3.setFont(font1);
	mainMenu3.setFillColor(sf::Color::Black);
	mainMenu3.setString("QUIT");
	mainMenu3.setCharacterSize(40);
	mainMenu3.setPosition(200, 290);

	Name.setFont(font1);
	Name.setFillColor(sf::Color::Black);
	Name.setString("Onwanya Ardsana : 63011060");
	Name.setCharacterSize(15);
	Name.setPosition(600, 0);

	Score.setFont(font1);
	Score.setFillColor(sf::Color::Black);
	Score.setString("Score : "+ Player1.gil1);
	Score.setCharacterSize(30);
	Score.setPosition(300, 300);

	int select = 0;

	int eieieieieieie = 0;

	ifstream loadFile;
	string hightName[5];

	sf::String playerName;
	string playernaming;

	sf::Text Text;
	Text.setFont(font1);
	Text.setCharacterSize(28);
	Text.setFillColor(sf::Color::Black);
	Text.setPosition(100, 100);




	//Main Loop:
	while (window.isOpen())
	{

		while (mainmenu)
		{
			printf("%d\n", eieieieieieie);
			eieieieieieie++;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && select == 0) {
				mainmenu = false;
				userName = true;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && select == 1) {
				mainmenu = false;
				lead = true;

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && select == 2) {
				window.close();

			}


			if (eieieieieieie > 3)
			{


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
				{
					if (select > 0)
					{
						select--;
					}
					eieieieieieie = 0;

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
				{
					if (select < 2) {
						select++;
					}
					eieieieieieie = 0;

				}
			}

			mainMenu1.setFillColor(sf::Color::Black);
			mainMenu2.setFillColor(sf::Color::Black);
			mainMenu3.setFillColor(sf::Color::Black);

			if (select == 0)
			{
				mainMenu1.setFillColor(sf::Color::White);
			}
			if (select == 1)
			{
				mainMenu2.setFillColor(sf::Color::White);
			}
			if (select == 2)
			{
				mainMenu3.setFillColor(sf::Color::White);
			}

			sf::Mouse mouse;

			window.draw(bgButton);
			window.draw(text2);
			window.draw(mainMenu1);
			window.draw(mainMenu3);
			window.draw(mainMenu2);
			window.draw(Name);
			window.display();
			window.clear();
		}

		while (userName)
		{
			sf::Event Event;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				userName = false;
				state1 = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				textbox1.setSelected(true);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				textbox1.setSelected(false);
			}


			//Event Loop:
			while (window.pollEvent(Event))
			{

				switch (Event.type)
				{
				case sf::Event::Closed:
					window.close();
				//case sf::Event::TextEntered:
					//textbox1.typedOn(Event);

				}

				if (Event.type == sf::Event::TextEntered)
				{
					if (Event.text.unicode < 128)
					{
						if (Event.text.unicode == static_cast <sf::Uint32>(8) && playerName.getSize() > 0)
						{
							playerName.erase(playerName.getSize() - 1);
						}
						else
						{
							if (playerName.getSize() < 100 && Event.text.unicode != 13)
							{
								if (Event.text.unicode == 32)
								{
									Event.text.unicode = 95;
								}
								playerName += Event.text.unicode;
							}
						}
					}
				}
				Text.setString(playerName);
				

				window.clear();
				window.draw(bgButton);
				window.draw(bguser);
				window.draw(Text);

				//window.draw(text2);
				//textbox1.drawTo(window);
				window.display();
			}
		}

		window.clear();

		while (state1)
		{

			// random part
			int randomTime, r;
			srand(time(NULL));

			r = rand() % 4;

			//cout << "r = " << r << endl;
			// Clock
			sf::Time elapsed1 = clock.getElapsedTime();
			sf::Time elapsed2 = clock.getElapsedTime();
			sf::Time elapsed3 = clock.getElapsedTime();


			//Player collides with Pickup Item Coin

			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				if (Player1.rect.getGlobalBounds().intersects(pickUpArrey[counter].rect.getGlobalBounds()))
				{

					soundcoint.play();

					if (pickUpArrey[counter].isPotion == true)
					{
						Player1.gil += pickUpArrey[counter].potionValue;
					}
					pickUpArrey[counter].destroy = true;
				}

				counter++;
			}

			//Player collides with Pickup Item Potion

			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				if (Player1.rect.getGlobalBounds().intersects(pickUpArrey3[counter].rect.getGlobalBounds()))
				{

					if (pickUpArrey3[counter].isChest == true)
					{
						sounddrink.play();
						Player1.update1();
					}
					pickUpArrey3[counter].destroy3 = true;
				}

				counter++;
			}

			//Player collides with door
			counter = 0;
			if (Player1.rect.getGlobalBounds().intersects(warpArrey[counter].rect.getGlobalBounds()))
			{
				if (Player1.gil1 >= 27) {
					state1 = false;
					state2 = true;
					warpArrey[counter].isDoor = true;
					background2.rect.setPosition(sf::Vector2f(1000, 2000));
					background2.sprite.setPosition(sf::Vector2f(1000, 2000));
					Player1.rect.setPosition(sf::Vector2f(100, 280));

				}
			}
			counter++;

			if (elapsed2.asSeconds() >= 0.1)
			{
				clock2.restart();

				//Enemy Collides with Player (Player takes damage)
				counter = 0;
				for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
				{
					if (Player1.rect.getGlobalBounds().intersects(enemyArrey[counter].rect.getGlobalBounds()))
					{
						soundhurt.play();
						//Text Display
						textDisplay1.text.setString(to_string(enemyArrey[counter].attactDamage));
						textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
						textDisplayArrey.push_back(textDisplay1);

						Player1.hp -= enemyArrey[counter].attactDamage;
						Player1.updateHpBar();

						if (Player1.hp == 0)
						{
							state1 = false;
							totalscore = true;
						}
					}

					counter++;
				}
			}

			//Fires Missle (Space Bar)
			if (elapsed1.asSeconds() >= 0.2)
			{
				clock.restart();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{

					soundshot.play();

					projectile1.rect.setPosition(Player1.rect.getPosition());
					projectile1.direction = Player1.direction;
					projectileArrey.push_back(projectile1);
				}
			}

			//Projectile Collides with Enemy
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				counter2 = 0;
				for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
				{
					if (enemyArrey[counter2].rect.getGlobalBounds().intersects(projectileArrey[counter].rect.getGlobalBounds()))
					{
						projectileArrey[counter].destroy = true;
						Player1.gil1 += enemyArrey[counter2].enemyValue;  // �ԧ���Ǥ�ṹ����

						//Text Display
						textDisplay1.text.setString(to_string(projectileArrey[counter].attactDamage));
						textDisplay1.text.setPosition(enemyArrey[counter2].rect.getPosition().x, enemyArrey[counter2].rect.getPosition().y);
						textDisplayArrey.push_back(textDisplay1);

						enemyArrey[counter2].hp -= projectileArrey[counter].attactDamage;

						if (enemyArrey[counter2].hp <= 0)
						{
							enemyArrey[counter2].alive = false;
						}
					}

					counter2++;
				}
				counter++;
			}

			//Projectile Collides with chest
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				counter2 = 0;
				for (iter10 = pickUpArrey2.begin(); iter10 != pickUpArrey2.end(); iter10++)
				{
					if (pickUpArrey2[counter2].rect.getGlobalBounds().intersects(projectileArrey[counter].rect.getGlobalBounds()))
					{
						projectileArrey[counter].destroy = true;

						pickUpArrey2[counter2].power -= projectileArrey[counter].attactDamage;

						if (pickUpArrey2[counter2].power == 2)
						{
							pickUpArrey2[counter2].updateMovement01();
							//window.draw(pickUpArrey[counter].rect);
							window.draw(pickUpArrey2[counter2].sprite);
						}
						else if (pickUpArrey2[counter2].power == 1)
						{
							pickUpArrey2[counter2].updateMovement02();
							//window.draw(pickUpArrey[counter].rect);
							window.draw(pickUpArrey2[counter2].sprite);
						}
						else if (pickUpArrey2[counter2].power == 0)
						{
							pickUpArrey2[counter2].updateMovement03();
							//window.draw(pickUpArrey[counter].rect);
							window.draw(pickUpArrey2[counter2].sprite);
							pickUpArrey2[counter2].isPower = false;

							if (pickUpArrey2[counter].isPower == false)
							{
								pickUp3.rect.setPosition(500, 180);
								pickUpArrey3.push_back(pickUp3);

							}
						}

					}

					counter2++;
				}
				counter++;
			}

			//Delete Dead Enemy
			counter = 0;
			for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
			{
				if (enemyArrey[counter].alive == false)
				{
					cout << "Dead" << endl;

					// Drop Potion
					if (generateRandom(4) == 1)
					{
						pickUp1.isPotion = true;
						pickUp1.rect.setPosition(enemyArrey[counter].rect.getPosition());
						pickUpArrey.push_back(pickUp1);
					}

					enemyArrey.erase(iter4);
					break;
				}
				counter++;
			}


			//Delete Projectile
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				if (projectileArrey[counter].destroy == true)
				{
					projectileArrey.erase(iter);
					break;
				}
				counter++;
			}

			// Delete Text Display
			counter = 0;
			for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
			{
				if (textDisplayArrey[counter].destroy == true)
				{
					textDisplayArrey.erase(iter8);
					break;
				}
				counter++;
			}

			//Delete Pickup Items
			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				if (pickUpArrey[counter].destroy == true)
				{
					//cout << "Chon" << endl;
					pickUpArrey.erase(iter11);
					break;
				}
				counter++;
			}

			//Delete Potion 
			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				if (pickUpArrey3[counter].destroy3 == true)
				{
					pickUpArrey3.erase(iter9);
					break;

				}
				counter++;
			}


			window.draw(background1.sprite);
			//window.draw(background1.rect);
			background1.update();
			window.draw(background2.sprite);
			background2.update();

			window.draw(blood);

			//Draw Pickup Items
			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				pickUpArrey[counter].update();
				pickUpArrey[counter].updateMovement();
				//window.draw(pickUpArrey[counter].rect);
				window.draw(pickUpArrey[counter].sprite);

				counter++;
			}

			//Draw Pickup Items
			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				pickUpArrey3[counter].update();
				pickUpArrey3[counter].updateMovement3();
				//window.draw(pickUpArrey[counter].rect);
				window.draw(pickUpArrey3[counter].sprite);

				counter++;
			}



			if (Player1.gil1 == 27) {
				//Draw Pickup Items
				counter = 0;
				for (iter10 = pickUpArrey2.begin(); iter10 != pickUpArrey2.end(); iter10++)
				{
					pickUpArrey2[counter].update();
					//window.draw(pickUpArrey[counter].rect);
					window.draw(pickUpArrey2[counter].sprite);

					counter++;
				}
			}

			//Draw Projectiles
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				projectileArrey[counter].update();  // Update Projectile
				window.draw(projectileArrey[counter].rect);
				window.draw(projectileArrey[counter].sprite);
				counter++;
			}

			//Draw Enemies
			counter = 0;
			for (iter4 = enemyArrey.begin(); iter4 != enemyArrey.end(); iter4++)
			{
				int counterRunning = 0;
				if (enemyArrey[counter].rect.getPosition().x > Player1.rect.getPosition().x)   // Left
				{
					enemyArrey[counter].rect.move(-playerMovementSpeed, 0);
				}
				if (enemyArrey[counter].rect.getPosition().x < Player1.rect.getPosition().x)    // Right
				{
					enemyArrey[counter].rect.move(playerMovementSpeed, 0);
				}
				if (enemyArrey[counter].rect.getPosition().y > Player1.rect.getPosition().y)    // Up
				{
					enemyArrey[counter].rect.move(0, -playerMovementSpeed);
				}
				if (enemyArrey[counter].rect.getPosition().y < Player1.rect.getPosition().y)    // Down
				{
					enemyArrey[counter].rect.move(0, playerMovementSpeed);
				}

				enemyArrey[counter].update();
				enemyArrey[counter].updateMovement();
				enemyArrey[counter].updateHpBar();
				window.draw(enemyArrey[counter].rectHp);
				//window.draw(enemyArrey[counter].rect);
				window.draw(enemyArrey[counter].sprite);

				counter++;
			}

			//Update doorwarp
			warp1.update();

			//Draw doorwarp
			window.draw(warp1.rect);
			window.draw(warp1.sprite);

			//Update Player
			Player1.update();
			Player1.updateMovement();

			//Draw Player
			//window.draw(Player1.rect);
			window.draw(Player1.sprite);
			window.draw(Player1.rectHp);


			//Draw Text
			counter = 0;
			for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
			{
				textDisplayArrey[counter].update();
				window.draw(textDisplayArrey[counter].text);
				counter++;
			}

			// Draw Gil (1)
			text.setString("Coin   " + to_string(Player1.gil));
			window.draw(text);

			// Draw Gil (2)
			text1.setString("Score   " + to_string(Player1.gil1));
			window.draw(text1);

			// Update the window
			window.display();
		}

		window.clear();

		while (state2)
		{
			// random part
			int randomTime, r;
			srand(time(NULL));

			r = rand() % 4;

			//cout << "r = " << r << endl;
			// Clock
			sf::Time elapsed1 = clock.getElapsedTime();
			sf::Time elapsed2 = clock.getElapsedTime();
			sf::Time elapsed3 = clock.getElapsedTime();

			//Player collides with Pickup Item

			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				if (Player1.rect.getGlobalBounds().intersects(pickUpArrey[counter].rect.getGlobalBounds()))
				{
					soundcoint.play();
					if (pickUpArrey[counter].isPotion == true)
					{
						Player1.gil += pickUpArrey[counter].potionValue;
					}
					pickUpArrey[counter].destroy = true;
				}

				counter++;
			}

			//Player collides with Pickup Item Potion

			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				if (Player1.rect.getGlobalBounds().intersects(pickUpArrey3[counter].rect.getGlobalBounds()))
				{

					if (pickUpArrey3[counter].isChest == true)
					{
						sounddrink.play();
						Player1.update1();
					}
					pickUpArrey3[counter].destroy3 = true;
				}

				counter++;
			}


			//Player collides with door
			counter = 0;
			if (Player1.rect.getGlobalBounds().intersects(warpArrey[counter].rect.getGlobalBounds()))
			{
				if (Player1.gil1 >= 128) {
					warpArrey[counter].isDoor = true;
					state2 = false;
					state3 = true;
					background3.rect.setPosition(sf::Vector2f(1000, 2000));
					background3.sprite.setPosition(sf::Vector2f(1000, 2000));
					Player1.rect.setPosition(sf::Vector2f(100, 280));
				}

			}
			counter++;


			if (elapsed2.asSeconds() >= 0.1)
				//if (true)
			{
				printf("Eieiei\n");
				clock2.restart();

				//Enemy Collides with Player (Player takes damage)
				counter = 0;
				for (iter5 = enemyArrey2.begin(); iter5 != enemyArrey2.end(); iter5++)
				{
					if (Player1.rect.getGlobalBounds().intersects(enemyArrey2[counter].rect.getGlobalBounds()))
					{
						soundhurt.play();
						//Text Display
						printf("Attack\n");
						textDisplay1.text.setString(to_string(enemyArrey2[counter].attactDamage));
						textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
						textDisplayArrey.push_back(textDisplay1);

						Player1.hp -= enemyArrey2[counter].attactDamage;
						Player1.updateHpBar();

						if (Player1.hp == 0)
						{
							state2 = false;
							state3 = false;
							totalscore = true;
						}

					}
					counter++;
				}
			}
			//cout << Player1.hp << endl;

			//Projectile Collides with Enemy
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				counter2 = 0;
				for (iter5 = enemyArrey2.begin(); iter5 != enemyArrey2.end(); iter5++)
				{
					if (enemyArrey2[counter2].rect.getGlobalBounds().intersects(projectileArrey[counter].rect.getGlobalBounds()))
					{
						//cout << "Collision" << endl;
						projectileArrey[counter].destroy = true;
						Player1.gil1 += enemyArrey2[counter2].enemyValue;  // �ԧ���Ǥ�ṹ����

						//Text Display
						textDisplay1.text.setString(to_string(projectileArrey[counter].attactDamage));
						textDisplay1.text.setPosition(enemyArrey2[counter2].rect.getPosition().x, enemyArrey2[counter2].rect.getPosition().y);
						textDisplayArrey.push_back(textDisplay1);

						enemyArrey2[counter2].hp -= projectileArrey[counter].attactDamage;

						if (enemyArrey2[counter2].hp <= 0)
						{
							enemyArrey2[counter2].alive = false;
						}
					}

					counter2++;
				}
				counter++;
			}

			//Delete Dead Enemy
			counter = 0;
			for (iter5 = enemyArrey2.begin(); iter5 != enemyArrey2.end(); iter5++)
			{
				if (enemyArrey2[counter].alive == false)
				{
					//cout << "Dead" << endl;

					// Drop Potion
					if (generateRandom(4) == 1)
					{
						pickUp1.rect.setPosition(enemyArrey2[counter].rect.getPosition());
						pickUpArrey.push_back(pickUp1);
					}

					enemyArrey2.erase(iter5);
					break;
				}
				counter++;
			}

			//Delete Projectile
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				if (projectileArrey[counter].destroy == true)
				{
					//cout << "proDead" << endl;
					projectileArrey.erase(iter);
					break;
				}
				counter++;
			}

			// Delete Text Display
			counter = 0;
			for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
			{
				if (textDisplayArrey[counter].destroy == true)
				{
					textDisplayArrey.erase(iter8);
					break;
				}
				counter++;
			}

			//Delete Pickup Items
			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				if (pickUpArrey[counter].destroy == true)
				{
					//cout << "Chon" << endl;
					pickUpArrey.erase(iter11);
					break;
				}
				counter++;
			}


			//Fires Missle (Space Bar)
			if (elapsed1.asSeconds() >= 0.1)
				//if (true)
			{
				clock.restart();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					soundshot.play();
					
					projectile1.rect.setPosition(Player1.rect.getPosition());
					projectile1.direction = Player1.direction;
					projectileArrey.push_back(projectile1);
				}
			}

			//Draw background
			window.draw(background2.sprite);
			background2.update();
			window.draw(background3.sprite);
			background3.update();




			//Draw Pickup Items
			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				pickUpArrey[counter].update();
				pickUpArrey[counter].updateMovement();
				//window.draw(pickUpArrey[counter].rect);
				window.draw(pickUpArrey[counter].sprite);

				counter++;
			}

			if (Player1.gil1 >= 140) {
				//Draw Pickup Items
				counter = 0;
				for (iter10 = pickUpArrey2.begin(); iter10 != pickUpArrey2.end(); iter10++)
				{
					pickUpArrey2[counter].update();
					//window.draw(pickUpArrey[counter].rect);
					window.draw(pickUpArrey2[counter].sprite);

					counter++;
				}
			}

			//Draw Projectiles
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				projectileArrey[counter].update();  // Update Projectile
				window.draw(projectileArrey[counter].rect);
				window.draw(projectileArrey[counter].sprite);
				counter++;
			}

			//Draw Enemies
			counter = 0;
			for (iter5 = enemyArrey2.begin(); iter5 != enemyArrey2.end(); iter5++)
			{
				int counterRunning = 0;
				if (enemyArrey2[counter].rect.getPosition().x > Player1.rect.getPosition().x)   // Left
				{
					enemyArrey2[counter].rect.move(-playerMovementSpeed2, 0);
				}
				if (enemyArrey2[counter].rect.getPosition().x < Player1.rect.getPosition().x)    // Right
				{
					enemyArrey2[counter].rect.move(playerMovementSpeed2, 0);
				}
				if (enemyArrey2[counter].rect.getPosition().y > Player1.rect.getPosition().y)    // Up
				{
					enemyArrey2[counter].rect.move(0, -playerMovementSpeed2);
				}
				if (enemyArrey2[counter].rect.getPosition().y < Player1.rect.getPosition().y)    // Down
				{
					enemyArrey2[counter].rect.move(0, playerMovementSpeed2);
				}

				enemyArrey2[counter].update();
				enemyArrey2[counter].updateMovement2();
				enemyArrey2[counter].updateHpBar();
				window.draw(enemyArrey2[counter].rectHp);
				//window.draw(enemyArrey[counter].rect);
				window.draw(enemyArrey2[counter].sprite);

				counter++;
			}

			window.draw(blood);

			//Update doorwarp
			warp1.update();


			//Draw doorwarp
			window.draw(warp1.rect);
			window.draw(warp1.sprite);

			//Update Player
			Player1.update();
			Player1.updateMovement();

			//Draw Player
			//window.draw(Player1.rect);
			window.draw(Player1.sprite);
			window.draw(Player1.rectHp);


			//Draw Text
			counter = 0;
			for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
			{
				textDisplayArrey[counter].update();
				window.draw(textDisplayArrey[counter].text);
				counter++;
			}

			// Draw Gil (1)
			text.setString("Coin   " + to_string(Player1.gil));
			window.draw(text);

			// Draw Gil (2)
			text1.setString("Score   " + to_string(Player1.gil1));
			window.draw(text1);

			// Update the window
			window.display();
		}

		while (state3)
		{

			// random part
			int randomTime, r;
			srand(time(NULL));

			r = rand() % 4;

			cout << "r = " << r << endl;
			// Clock
			sf::Time elapsed1 = clock.getElapsedTime();
			sf::Time elapsed2 = clock.getElapsedTime();
			sf::Time elapsed3 = clock.getElapsedTime();


			//Player collides with Pickup Item Coin

			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				if (Player1.rect.getGlobalBounds().intersects(pickUpArrey[counter].rect.getGlobalBounds()))
				{

					soundcoint.play();

					if (pickUpArrey[counter].isPotion == true)
					{
						Player1.gil += pickUpArrey[counter].potionValue;
					}
					pickUpArrey[counter].destroy = true;
				}

				counter++;
			}

			//Player collides with Pickup Item Potion

			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				if (Player1.rect.getGlobalBounds().intersects(pickUpArrey3[counter].rect.getGlobalBounds()))
				{

					if (pickUpArrey3[counter].isChest == true)
					{
						sounddrink.play();
						Player1.update1();
					}
					pickUpArrey3[counter].destroy3 = true;
				}

				counter++;
			}


			if (elapsed2.asSeconds() >= 0.1)
			{
				clock2.restart();

				//Enemy Collides with Player (Player takes damage)
				counter = 0;
				for (iter6 = enemyArrey3.begin(); iter6 != enemyArrey3.end(); iter6++)
				{
					if (Player1.rect.getGlobalBounds().intersects(enemyArrey3[counter].rect.getGlobalBounds()))
					{
						soundhurt.play();
						//Text Display
						textDisplay1.text.setString(to_string(enemyArrey3[counter].attactDamage));
						textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
						textDisplayArrey.push_back(textDisplay1);

						Player1.hp -= enemyArrey3[counter].attactDamage;
						Player1.updateHpBar();

						if (Player1.hp == 0)
						{
							state3 = false;
							totalscore = true;
						}

					}
					counter++;
				}
			}

			//Fires Missle (Space Bar)
			if (elapsed1.asSeconds() >= 0.1)
			{
				clock.restart();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{

					soundshot.play();
					  

					projectile1.rect.setPosition(Player1.rect.getPosition());
					projectile1.direction = 1;
					projectileArrey.push_back(projectile1);

					projectile1.rect.setPosition(Player1.rect.getPosition());
					projectile1.direction = 2;
					projectileArrey.push_back(projectile1);

					projectile1.rect.setPosition(Player1.rect.getPosition());
					projectile1.direction = 3;
					projectileArrey.push_back(projectile1);

					projectile1.rect.setPosition(Player1.rect.getPosition());
					projectile1.direction = 4;
					projectileArrey.push_back(projectile1);
				}
			}


			//Projectile Collides with Enemy
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				counter2 = 0;
				for (iter6 = enemyArrey3.begin(); iter6 != enemyArrey3.end(); iter6++)
				{
					if (enemyArrey3[counter2].rect.getGlobalBounds().intersects(projectileArrey[counter].rect.getGlobalBounds()))
					{
						projectileArrey[counter].destroy = true;
						Player1.gil1 += enemyArrey3[counter2].enemyValue;  // �ԧ���Ǥ�ṹ����

						//Text Displayssa
						textDisplay1.text.setString(to_string(projectileArrey[counter].attactDamage));
						textDisplay1.text.setPosition(enemyArrey3[counter2].rect.getPosition().x, enemyArrey3 [counter2].rect.getPosition().y);
						textDisplayArrey.push_back(textDisplay1);

						enemyArrey3[counter2].hp -= projectileArrey[counter].attactDamage;

						if (enemyArrey3[counter2].hp <= 0)
						{
							enemyArrey3[counter2].alive = false;
						}                          
					}

					counter2++;
				}
				counter++;
			}

			//Projectile Collides with chest
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				counter2 = 0;
				for (iter10 = pickUpArrey2.begin(); iter10 != pickUpArrey2.end(); iter10++)
				{
					if (pickUpArrey2[counter2].rect.getGlobalBounds().intersects(projectileArrey[counter].rect.getGlobalBounds()))
					{
						projectileArrey[counter].destroy = true;

						pickUpArrey2[counter2].power -= projectileArrey[counter].attactDamage;

						if (pickUpArrey2[counter2].power == 2)
						{
							pickUpArrey2[counter2].updateMovement01();
							//window.draw(pickUpArrey[counter].rect);
							window.draw(pickUpArrey2[counter2].sprite);
						}
						else if (pickUpArrey2[counter2].power == 1)
						{
							pickUpArrey2[counter2].updateMovement02();
							//window.draw(pickUpArrey[counter].rect);
							window.draw(pickUpArrey2[counter2].sprite);
						}
						else if (pickUpArrey2[counter2].power == 0)
						{
							pickUpArrey2[counter2].updateMovement03();
							//window.draw(pickUpArrey[counter].rect);
							window.draw(pickUpArrey2[counter2].sprite);
							pickUpArrey2[counter2].isPower = false;

							if (pickUpArrey2[counter].isPower == false)
							{
								pickUp3.rect.setPosition(500, 180);
								pickUpArrey3.push_back(pickUp3);

							}
						}

					}

					counter2++;
				}
				counter++;
			}

			//Delete Dead Enemy
			counter = 0;
			for (iter6 = enemyArrey3.begin(); iter6 != enemyArrey3.end(); iter6++)
			{
				if (enemyArrey3[counter].alive == false)
				{
					cout << "Dead" << endl;

					// Drop Potion
					if (generateRandom(4) == 1)
					{
						pickUp1.isPotion = true;
						pickUp1.rect.setPosition(enemyArrey3[counter].rect.getPosition());
						pickUpArrey.push_back(pickUp1);
					}

					enemyArrey3.erase(iter6);
					if (enemyArrey3.size() == 0) {

	
							ofstream highscore;
							highscore.open("HS.txt", ios::out | ios::app);
							highscore << "\n"  << Player1.gil1;
							highscore.close();
						state3 = false;
						totalscore = true;
					}
					break;

				}
				counter++;
			}


			//Delete Projectile
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				if (projectileArrey[counter].destroy == true)
				{
					projectileArrey.erase(iter);
					break;
				}
				counter++;
			}

			// Delete Text Display
			counter = 0;
			for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
			{
				if (textDisplayArrey[counter].destroy == true)
				{
					textDisplayArrey.erase(iter8);
					break;
				}
				counter++;
			}

			//Delete Pickup Items
			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				if (pickUpArrey[counter].destroy == true)
				{
					cout << "Chon" << endl;
					pickUpArrey.erase(iter11);
					break;
				}
				counter++;
			}

			//Delete Potion 
			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				if (pickUpArrey3[counter].destroy3 == true)
				{
					pickUpArrey3.erase(iter9);
					break;

				}
				counter++;
			}


			window.draw(background1.sprite);
			//window.draw(background1.rect);
			background1.update();
			window.draw(background2.sprite);
			background2.update();

			window.draw(blood);

			//Draw Pickup Items
			counter = 0;
			for (iter11 = pickUpArrey.begin(); iter11 != pickUpArrey.end(); iter11++)
			{
				pickUpArrey[counter].update();
				pickUpArrey[counter].updateMovement();
				//window.draw(pickUpArrey[counter].rect);
				window.draw(pickUpArrey[counter].sprite);

				counter++;
			}

			//Draw Pickup Items
			counter = 0;
			for (iter9 = pickUpArrey3.begin(); iter9 != pickUpArrey3.end(); iter9++)
			{
				pickUpArrey3[counter].update();
				pickUpArrey3[counter].updateMovement3();
				//window.draw(pickUpArrey[counter].rect);
				window.draw(pickUpArrey3[counter].sprite);

				counter++;
			}



			//Draw Projectiles
			counter = 0;
			for (iter = projectileArrey.begin(); iter != projectileArrey.end(); iter++)
			{
				projectileArrey[counter].update();  // Update Projectile
				window.draw(projectileArrey[counter].rect);
				window.draw(projectileArrey[counter].sprite);
				counter++;
			}

			//Draw Enemies
			counter = 0;
			for (iter6 = enemyArrey3.begin(); iter6 != enemyArrey3.end(); iter6++)
			{
				int counterRunning = 0;
				if (enemyArrey3[counter].rect.getPosition().x > Player1.rect.getPosition().x)   // Left
				{
					enemyArrey3[counter].rect.move(-playerMovementSpeed3, 0);
				}
				if (enemyArrey3[counter].rect.getPosition().x < Player1.rect.getPosition().x)    // Right
				{
					enemyArrey3[counter].rect.move(playerMovementSpeed3, 0);
				}
				if (enemyArrey3[counter].rect.getPosition().y > Player1.rect.getPosition().y)    // Up
				{
					enemyArrey3[counter].rect.move(0, -playerMovementSpeed3);
				}
				if (enemyArrey3[counter].rect.getPosition().y < Player1.rect.getPosition().y)    // Down
				{
					enemyArrey3[counter].rect.move(0, playerMovementSpeed3);
				}

				enemyArrey3[counter].update();
				enemyArrey3[counter].updateMovement3();
				enemyArrey3[counter].updateHpBar();
				window.draw(enemyArrey3[counter].rectHp);
				//window.draw(enemyArrey[counter].rect);
				window.draw(enemyArrey3[counter].sprite);

				counter++;
			}


			window.draw(blood);

			//Update Player
			Player1.update();
			Player1.updateMovement();

			//Draw Player
			//window.draw(Player1.rect);
			window.draw(Player1.sprite);
			window.draw(Player1.rectHp);


			//Draw Text
			counter = 0;
			for (iter8 = textDisplayArrey.begin(); iter8 != textDisplayArrey.end(); iter8++)
			{
				textDisplayArrey[counter].update();
				window.draw(textDisplayArrey[counter].text);
				counter++;
			}

			// Draw Gil (1)
			text.setString("Coin   " + to_string(Player1.gil));
			window.draw(text);

			// Draw Gil (2)
			text1.setString("Score   " + to_string(Player1.gil1));
			window.draw(text1);

			// Update the window
			window.display();
		}

		window.clear();  

		while (totalscore)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				totalscore = false;
				MyScore = true;
			}

			text1.setString("Score   " + to_string(Player1.gil1));
			text1.setPosition(300, 300);


			window.draw(bgButton);
			window.draw(text2);
			window.draw(text1);
			window.display();
			window.clear();
		}

		while (MyScore)
		{
			ifstream readScore,readnameFile;
			
			string nubScore,nubName;
			int i=0,chang=0,chang1=0;
			readScore.open("HS.txt");
			if (readScore.is_open() == 1)
			{
				while (getline(readScore, nubScore) && i < 5)
				{
					hightScore[i] = stoi(nubScore);
					i++;
				}
				
			}

			readScore.close();


			
			//write score
			ofstream writeScore;
			writeScore.open("HS.txt");
			if (writeScore.is_open())
			{
				for (i = 0; i < 5; i++)
				{
					if (Player1.gil1 > hightScore[i])
					{
						for (int j = 4; j > i; j--)
						{
							hightScore[j] = hightScore[j - 1];
						}
						chang = 1;
						chang1 = i;
						hightScore[i] = Player1.gil1;
						break;
					}
				}
				for (int j = 0; j < 5; j++)
				{
					writeScore << hightScore[j] << endl;
				}
			}
			writeScore.close();
			//read name
			i = 0;
			readnameFile.open("playername.txt");
			if (readnameFile.is_open() == 1)
			{
				while (getline(readnameFile, nubName) && i < 5)
				{
					hightName[i] = nubName;
					i++;
				}
			}
			readnameFile.close();
			

			//write name
			ofstream writenameFile;
			writenameFile.open("NM.txt");
			if (writenameFile.is_open() == 1)
			{
				for (int i = 0; i < 5; i++)
				{
					if (chang == 1)
					{
						chang = 0;
						//chang1 = i;
						for (int j = 4; j > i; j--)
						{
							hightName[j] = hightName[j - 1];
						}
						hightName[chang1] = playerName;
						
						break;
					}
				}
				for (int j = 0; j < 5; j++)
				{
					writenameFile << hightName[j] << endl;
				}
			}
			writenameFile.close();




			MyScore = false;
			mainmenu = true;
			
			window.draw(bgButton);
			window.draw(text2);
			window.draw(text1);
			window.display();
			window.clear();
			
		}

		while (lead)
		{
			ostringstream sctostring;
			sctostring << Player1.gil1;
			sf::Text lblNamePlayer, lblScorePlayer, Scorelbl[5], Namelbl[5];
			sf::Text textL;
			string gameover = "LEADERBOARD";
			textL.setString(gameover);
			textL.setFont(font1);
			textL.setCharacterSize(40);
			textL.setPosition((window.getPosition().x / 2) + 200, window.getPosition().y / 2 - 50);
			textL.setFillColor(sf::Color::White);

			ostringstream arragesc[6];

			for (int i = 0; i < 5; i++)
			{
				arragesc[i] << hightScore[i];
			}
			for (int i = 0; i < 5; i++)
			{
				Scorelbl[i].setFont(font1);
				Scorelbl[i].setCharacterSize(50);
				Scorelbl[i].setFillColor(sf::Color::White);
				Scorelbl[i].setString(arragesc[i].str());
				Namelbl[i].setFont(font1);
				Namelbl[i].setCharacterSize(50);
				Namelbl[i].setFillColor(sf::Color::White);
				Namelbl[i].setString(hightName[i]);
			}
			Scorelbl[0].setPosition(718, 188);
			Scorelbl[1].setPosition(718, 275);
			Scorelbl[2].setPosition(718, 356);
			Scorelbl[3].setPosition(718, 440);
			Scorelbl[4].setPosition(718, 524);
			Namelbl[0].setPosition(262, 188);
			Namelbl[1].setPosition(262, 275);
			Namelbl[2].setPosition(262, 356);
			Namelbl[3].setPosition(262, 440);
			Namelbl[4].setPosition(262, 524);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				lead = 0;
				mainmenu = 1;
			}
				
				window.clear();
				window.draw(textL);

				for (int i = 0; i < 5; i++)
				{
					window.draw(Scorelbl[i]);
					window.draw(Namelbl[i]);
				}
				window.display();
			
		}
	}
}    
//void score() {
//
//	vector<pair<int, string>> scoreboard;
//
//
//	press = false;
//
//	scoreboard.clear(); //�������
//
//	loadFile.open("HS.txt");
//	while (!loadFile.eof()) {
//		string tempName;
//		int tempScore;
//		loadFile >> tempName >> tempScore;
//		scoreboard.push_back({ tempScore,tempName });
//	}
//	loadFile.close();
//
//	sort(scoreboard.begin(), scoreboard.end(), greater<pair<int, string>>());
//
//	while (window.isOpen())
//	{
//		int cnt = 0;
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//			{
//				window.close();
//			}
//
//			if (event.type == sf::Event::KeyReleased)
//			{
//				press = true;
//			}
//		}
//
//		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && press)
//		{
//			press = false;
//			chan.play();
//			goto Main;
//		}
//
//		window.clear(sf::Color(76, 76, 76));
//
//		window.draw(mt[8]);
//
//		for (vector<pair<int, string>>::iterator k = scoreboard.begin(); k != scoreboard.end(); ++k)
//		{
//			++cnt;
//			if (cnt > 5)
//				break;
//
//			sf::Text hname, hscore;
//			hscore.setString(to_string(k->first));
//			hscore.setFont(font);
//			hscore.setCharacterSize(40);
//			hscore.setPosition(1200, 300 + (80 * cnt));
//			hscore.setFillColor(sf::Color::Black);
//			window.draw(hscore);
//			hname.setString(k->second);
//			hname.setFont(font);
//			hname.setCharacterSize(40);
//			hname.setPosition(600, 300 + (80 * cnt));
//			hname.setFillColor(sf::Color::Black);
//			window.draw(hname);
//		}
//
//		window.draw(myname);
//
//		window.display();
//	}
//}
