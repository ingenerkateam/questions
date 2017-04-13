#ifndef QUESTIONMODULE_H
#define QUESTIONMODULE_H
#include <fstream>
#include "testToQuest\lib.h"
#include "TXLib.h"

using namespace std;

namespace questionModule
{

    int One = 1;
    int Two = 2;
    int NoAnswer = 3;
    unsigned int number[100];
    char* question[100];



    namespace
    {
    HDC imageBackGround;
    }

    bool buttonState1()
    {
        return (txMouseX() >=  100 and txMouseX() <= 250 and txMouseY() >= 250 and txMouseY() <= 350 and txMouseButtons() == 1);
    }

    bool buttonState2()
    {
        return (txMouseX() >= 350  and txMouseX() <= 500  and txMouseY() >= 250  and txMouseY() <= 350  and txMouseButtons() == 1);
    }

    int rightAnswer;

    int isRightAnswer()
    {
        if (rightAnswer == 1 and buttonState1())
        {
            return One;
        }
        if (rightAnswer == 2 and buttonState2())
        {
            return Two;
        }
        return NoAnswer;
    }

    void draw(const char* a)
    {
        txSetFillColor(TX_GRAY);
        txRectangle(100, 100, 500, 200);
        txDrawText (100, 100, 500, 200, a);
    }

    void draw(const char* a, const char* a2)
    {
        txRectangle(100, 250, 250, 350);
        txDrawText (100, 250, 250, 350, a);
        txRectangle(350, 250, 500, 350);
        txDrawText (350, 250, 500, 350, a2);
    }

    void _END()
    {
        txDeleteDC(imageBackGround);
        txSleep(100);
    }

    void runQuestionModule(unsigned int number, const char* q, const char* a = "��", const char* a2 = "���")
    {
        if (number != 1 and number != 2)
        {
            _END();
            exit(1);
        }

        /*/ Init /*/
        txClear();
        imageBackGround = txLoadImage ("imageBackGround.bmp");
        txBitBlt (txDC(), 0, 0, 800, 600, imageBackGround, 0, 0);
        rightAnswer = number;
        /*/ ==== /*/

        /*/ Question /*/

        draw(q);
        draw(a, a2);
        while (isRightAnswer() == NoAnswer)
        {
            if (GetAsyncKeyState('N'))
            {
                break;
            }
        }
        if (!isRightAnswer() == number)
        {
            while (true)
            {
                txSetFillColor(RGB(random(255), random(255), random(255)));
                txClear();
            }
        }
        _END();
        /*/ ==== /*/
    }
};

#endif // QUESTIONMODULE_H
