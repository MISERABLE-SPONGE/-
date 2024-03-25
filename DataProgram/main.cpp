#include<SFML/Graphics.hpp>
#include<iostream>




int main()
{

    // 创建窗口
    /*
        sf::VideoMode::getFullscreenModes()[0] 获取当前系统支持的全屏分辨率，并将其作为窗口的大小。
        Fullscreen Window" 是窗口的标题，sf::Style::Fullscreen 设置窗口样式为全屏模式。
    */
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fullscreen Window", sf::Style::Fullscreen);


    // 获得全屏窗口的高宽(1920,1080)
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktop.width;
    unsigned int screenHeight = desktop.height;
    std::cout << "Screen Width: " << screenWidth << std::endl;
    std::cout << "Screen Height: " << screenHeight << std::endl;

    // 创建一个圆点形状
    sf::CircleShape dot(20.f); //半径为20
    dot.setFillColor(sf::Color::Red);
    dot.setPosition(1900.f, 1060.f); // 设置圆点外接矩形左上角的位置  (1900.f, 1000.f)是最右下角


    // 调用 window.isOpen() 可以检查窗口是否仍然处于打开状态。当窗口关闭时，window.isOpen() 将返回 false，从而退出循环，结束程序的执行。
    while (window.isOpen())  
    {

        // sf::Event 类表示窗口的各种事件，如按键、鼠标移动、窗口大小变化等
        sf::Event event; 

        // window.pollEvent(event) 来获取窗口的事件并将其存储在 event 对象中
        while (window.pollEvent(event)) 
        {
            // sf::Event::Closed表示窗口关闭事件
            if (event.type == sf::Event::Closed)
                window.close();
            // 事件的类型为 sf::Event::KeyPressed 且按下的键为 sf::Keyboard::Escape（即 ESC 键）时，我们调用 window.close() 来关闭窗口。
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();


            // 判断鼠标点击圆点
            if (event.type == sf::Event::MouseButtonPressed) //鼠标点击事件
            {
                if (event.mouseButton.button == sf::Mouse::Left) //鼠标左键
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window); //记录鼠标位置
                    sf::Vector2f dotPosition = dot.getPosition(); //记录圆点位置

                    // 判断鼠标点击是否在圆点内
                    if (mousePosition.x >= dotPosition.x - dot.getRadius() &&
                        mousePosition.x <= dotPosition.x + dot.getRadius() &&
                        mousePosition.y >= dotPosition.y - dot.getRadius() &&
                        mousePosition.y <= dotPosition.y + dot.getRadius())
                    {
                        // 鼠标点击到了圆点
                        std::cout << "Clicked on the dot!" << std::endl;
                    }
                    else
                    {
                        // 鼠标没有点击到了圆点
                        std::cout << "Clicked out the dot!" << std::endl;
                    }
                }
            }
        }

        //窗口清空
        window.clear();
        // 在窗口中绘制圆点
        window.draw(dot);
        // 渲染窗口内容
        window.display();

    }

    return 0;
}