#ifndef DEFINING_HPP
#define DEFINING_HPP

    // View

    #define MENUVIEW 0
    #define SOLOGAMEVIEW 1
    #define SETTINGSVIEW 2
    #define SETTINGSMATCH 3

    // Victory Rainbow

    #define SIN(f, t, i) (std::sin(f * t + i) * 127.0f + 128.0f)
    #define COS(f, t, i) (std::cos(f * t + i) * 127.0f + 128.0f)

    // ?

    #define PLAYPOSITION 250
    #define SETTINGSPOSITION 300
    #define TUTORIALPOSITION 350

    // Number of events

    #define NUMBER_OF_EVENT 3

    // Board size

    #define CASE_SIZE 60
    #define LENGTH_BOARD 7
    #define WIDTH_BOARD 6
    #define CIRCLE_RADIUS 25

    // Window size

    #define VIDEOWIDTH 800
    #define VIDEOHEIGHT 600

    // Time before event

    #define JETON_AVANT_EVENT 10

    // Events

    #define EVENT_TETRIS 0
    #define EVENT_SWITCH 1
    #define EVENT_CHUTE 2

#endif // DEFINING_HPP
