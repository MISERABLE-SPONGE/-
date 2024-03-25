#include<SFML/Graphics.hpp>
#include<iostream>




int main()
{

    // ��������
    /*
        sf::VideoMode::getFullscreenModes()[0] ��ȡ��ǰϵͳ֧�ֵ�ȫ���ֱ��ʣ���������Ϊ���ڵĴ�С��
        Fullscreen Window" �Ǵ��ڵı��⣬sf::Style::Fullscreen ���ô�����ʽΪȫ��ģʽ��
    */
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);


    // ���ȫ�����ڵĸ߿�(1920,1080)
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktop.width;
    unsigned int screenHeight = desktop.height;
    std::cout << "Screen Width: " << screenWidth << std::endl;
    std::cout << "Screen Height: " << screenHeight << std::endl;

    // ����һ��Բ����״
    sf::CircleShape dot(20.f); //�뾶Ϊ20
    dot.setFillColor(sf::Color::Red);
    dot.setPosition(1900.f, 1060.f); // ����Բ����Ӿ������Ͻǵ�λ��  (1900.f, 1000.f)�������½�


    // ���� window.isOpen() ���Լ�鴰���Ƿ���Ȼ���ڴ�״̬�������ڹر�ʱ��window.isOpen() ������ false���Ӷ��˳�ѭ�������������ִ�С�
    while (window.isOpen())  
    {

        // sf::Event ���ʾ���ڵĸ����¼����簴��������ƶ������ڴ�С�仯��
        sf::Event event; 

        // window.pollEvent(event) ����ȡ���ڵ��¼�������洢�� event ������
        while (window.pollEvent(event)) 
        {
            // sf::Event::Closed��ʾ���ڹر��¼�
            if (event.type == sf::Event::Closed)
                window.close();
            // �¼�������Ϊ sf::Event::KeyPressed �Ұ��µļ�Ϊ sf::Keyboard::Escape���� ESC ����ʱ�����ǵ��� window.close() ���رմ��ڡ�
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();


            // �ж������Բ��
            if (event.type == sf::Event::MouseButtonPressed) //������¼�
            {
                if (event.mouseButton.button == sf::Mouse::Left) //������
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window); //��¼���λ��
                    sf::Vector2f dotPosition = dot.getPosition(); //��¼Բ��λ��

                    // �ж�������Ƿ���Բ����
                    if (mousePosition.x >= dotPosition.x - dot.getRadius() &&
                        mousePosition.x <= dotPosition.x + dot.getRadius() &&
                        mousePosition.y >= dotPosition.y - dot.getRadius() &&
                        mousePosition.y <= dotPosition.y + dot.getRadius())
                    {
                        // ���������Բ��
                        std::cout << "Clicked on the dot!" << std::endl;
                    }
                    else
                    {
                        // ���û�е������Բ��
                        std::cout << "Clicked out the dot!" << std::endl;
                    }
                }
            }
        }

        //�������
        window.clear();
        // �ڴ����л���Բ��
        window.draw(dot);
        // ��Ⱦ��������
        window.display();

    }

    return 0;
}