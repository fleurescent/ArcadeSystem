#include "Node.h"
#include "Config.h"
#include "MenuScreen.h"
#include "SimpleButton.h"

class RootNode : public Node // inherits from node
{
    public:

    RootNode(SDL_Renderer* renderer_in, Node* parentNode_in) : Node(renderer_in, parentNode_in)
    {
        // Make screens
        MenuScreen* rootNodeScreen1 = createMenuScreen();
        MenuScreen* rootNodeScreen2 = createMenuScreen();

        // create images to put on screens
        ArcadeTexture* rootNodeScreen1Background = createImage(renderer_in, "rootNodeImages/rootNodeScreenBackground.png", true);
        ArcadeTexture* rootNodeScreen2Background = createImage(renderer_in, "rootNodeImages/rootNodeScreenBackground.png", true);

        // add the images to the screen
        rootNodeScreen1->addTextureToScreen(rootNodeScreen1Background);
        rootNodeScreen2->addTextureToScreen(rootNodeScreen2Background);

        // add some text to the screen
        ArcadeTexture* mainMenuText = createSimpleText(renderer_in, "fonts/retro/italic.ttf", 100, "SCREEN 1", 255, 255, 0);
        mainMenuText->setPosition(windowWidth / 2 - mainMenuText->getW() / 2, 25);

        ArcadeTexture* mainMenuText2 = createSimpleText(renderer_in, "fonts/retro/italic.ttf", 100, "SCREEN 2", 255, 255, 0);
        mainMenuText2->setPosition(windowWidth / 2 - mainMenuText2->getW() / 2, 25);

        // add text to the screen
        rootNodeScreen1->addTextureToScreen(mainMenuText);
        rootNodeScreen2->addTextureToScreen(mainMenuText2);
        
        // create a button and set position
        SimpleButton* button1 = createSimpleTextButton(renderer_in, "fonts/pixel/classic.ttf", 30, "go to screen 2", 255, 0, 0);
        button1->setButtonPosition(windowWidth / 2 - button1->getWidth()/2,
        mainMenuText->getY() * mainMenuText->getH() + 50);

        button1->setButtonAction(createAction(MOVE_SCREENS, rootNodeScreen2));

        // add the button to the screen
        rootNodeScreen1->addButtonToScreen(button1);

        SimpleButton* button2 = createSimpleTextButton(renderer_in, "fonts/pixel/classic.ttf", 30, "go to screen 2", 255, 0, 0);
        button2->setButtonPosition(windowWidth / 2 - button2->getWidth()/2,
        mainMenuText2->getY() * mainMenuText2->getH() + 50);

        button2->setButtonAction(createAction(MOVE_SCREENS, rootNodeScreen1));

        //this->addScreen();
        //this->addScreen();

        //this->
    }
};