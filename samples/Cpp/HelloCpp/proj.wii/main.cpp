#include "../Classes/AppDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

int main(int argc, char **argv)
{
    // create the application instance
    AppDelegate app;

    CCEGLView* eglView = CCEGLView::sharedOpenGLView();

    return CCApplication::sharedApplication()->run();
}