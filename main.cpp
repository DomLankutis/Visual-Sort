#include <SFML/Graphics.hpp>
//#include <SFML/Audio/Sound.hpp>
//#include <SFML/Audio/SoundBuffer.hpp>
#include <iostream>

int WIDTH;
int HEIGHT;

sf::VertexArray sq1(sf::Quads, 4);
sf::VertexArray sq2(sf::Quads, 4);
sf::VertexArray sq3(sf::Quads, 4);
sf::VertexArray sq4(sf::Quads, 4);
sf::VertexArray sq5(sf::Quads, 4);
sf::VertexArray sq6(sf::Quads, 4);
sf::VertexArray sq7(sf::Quads, 4);
sf::VertexArray sq8(sf::Quads, 4);
sf::VertexArray sq9(sf::Quads, 4);
sf::VertexArray sq10(sf::Quads, 4);
sf::VertexArray sq11(sf::Quads, 4);
sf::VertexArray sq12(sf::Quads, 4);
sf::VertexArray sq13(sf::Quads, 4);
sf::VertexArray sq14(sf::Quads, 4);
sf::VertexArray sq15(sf::Quads, 4);
sf::VertexArray sq16(sf::Quads, 4);
sf::VertexArray sq17(sf::Quads, 4);
sf::VertexArray sq18(sf::Quads, 4);
sf::VertexArray sq19(sf::Quads, 4);
sf::VertexArray sq20(sf::Quads, 4);
sf::VertexArray sq21(sf::Quads, 4);
std::vector<sf::VertexArray> vertexArray = {sq1,sq2,sq3,sq4,sq5,sq6,sq7,sq8,sq9,sq10,sq11,sq12,sq13,sq14,sq15,sq16,sq17,sq18,sq19,sq20,sq21};
std::vector<int> sortList = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};

//provide vertexArray to swap
//will swap 'i' with 'i+1'
sf::VertexArray visualSort(float yWindowSize, int swap)
{
		int ySwap;
		for (int i = 0; i < 2; i++)
		{
			if (i == 0) { ySwap = swap + 1; }
			else { ySwap = swap; }
			int point1 = vertexArray[swap + i].getBounds().left;
			int point2 = point1 + 50;

			for (int i = 0; i < 4; i++)
			{
				vertexArray[swap + 1][i].color = sf::Color::Red;
			}

			vertexArray[swap + i][0].position = sf::Vector2f(point1, yWindowSize);
			vertexArray[swap + i][1].position = sf::Vector2f(point2, yWindowSize);
			vertexArray[swap + i][2].position = sf::Vector2f(point2, yWindowSize - (30 * sortList[ySwap]));
			vertexArray[swap + i][3].position = sf::Vector2f(point1, yWindowSize - (30 * sortList[ySwap]));
		}
		iter_swap(sortList.begin() + swap, sortList.begin() + swap + 1);
		return (vertexArray[swap], vertexArray[swap + 1]);
}

int main()
	{
		WIDTH = 1280;
		HEIGHT = (WIDTH / 16) * 9;
        char choice;
        std::cout << "B - For Bubble Sort\nG - For Boggo Sort\nI - For Insertion Sort\n>>> "; std::cin >> choice;
        std::cout << choice;
		/*
        sf::SoundBuffer buffer;
		buffer.loadFromFile("${SOURCE_FILES}");

		sf::Sound sound;
		sound.setBuffer(buffer);
        */
		sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT),
		                        "Visual Sort", sf::Style::Default);
		window.setFramerateLimit(60);
		window.setVerticalSyncEnabled(true);
		
		int size = 10;
		int size2 = 60;

		random_shuffle(sortList.begin(), sortList.end());

		for (int i = 0; i < vertexArray.capacity(); i++)
		{
			if (i != 0)
			{
				size = size2 + 10;
				size2 = size2 + 60;
			}
			vertexArray[i][0].position = sf::Vector2f(size, window.getSize().y);
			vertexArray[i][1].position = sf::Vector2f(size2, window.getSize().y);
			vertexArray[i][2].position = sf::Vector2f(size2, window.getSize().y - (30 * sortList[i]));
			vertexArray[i][3].position = sf::Vector2f(size, window.getSize().y - (30 * sortList[i]));
		}

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.key.code == sf::Keyboard::Escape) { window.close(); }
			}

            if(tolower(choice) == 'i')
            {
                //Insertion Sort
                for (int i = 0; i < sortList.capacity(); i++) {

                    auto j = i;
                    while (j > 0 && sortList[j] < sortList[j - 1])
                    {
                        visualSort(window.getSize().y, j - 1);
                        window.clear();
                        for (auto l = 0; l < vertexArray.capacity(); l++) { window.draw(vertexArray[l]); }
                        for (auto k = 0; k < 4; k++)
                        {
                            vertexArray[j][k].color = sf::Color::White;
                        }
                        window.display();
                        j--;
                    }
                    window.display();
                }
            }

            if(tolower(choice) == 'g')
            {
                //Bogo Sort
                std::cout << "entered";
                while(!std::is_sorted(sortList.begin(), sortList.end()))
                {
                    int randVal =  0 + (rand() % static_cast<int>((vertexArray.capacity()-2) - 0 + 1));
                    visualSort(window.getSize().y, randVal);
                    window.clear();
                    for (auto l = 0; l < vertexArray.capacity(); l++) { window.draw(vertexArray[l]); }
                    for (auto k = 0; k < 4; k++)
                    {
                        vertexArray[randVal+1][k].color = sf::Color::White;
                    }
                    window.display();
                }
            }
            if(tolower(choice) == 'b')
            {
                //Bubble Sort
                for (auto i = 0; i < sortList.capacity() - 1; i++)
                {
                    for (auto j = 0; j < sortList.capacity() - i - 1; j++)
                    {
                        if (sortList[j] > sortList[j + 1])
                        {
                            visualSort(window.getSize().y, j);
                            window.clear();
                            for (auto l = 0; l < vertexArray.capacity(); l++) { window.draw(vertexArray[l]); }
                            for (auto k = 0; k < 4; k++)
                            {
                                vertexArray[j + 1][k].color = sf::Color::White;
                                if (j == sortList.capacity())
                                {
                                    vertexArray[vertexArray.capacity()-1][k].color = sf::Color::Blue;
                                }
                            }
                            window.display();
                           // sound.play();
                        }
                    }
                }
            }
			//sound.stop();
		}
	}
