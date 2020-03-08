//
// Created by Tom on 3/7/20.
//

#include "Production.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Production::Production(){

}

Production::~Production() {

}

bool Production::run(int argc, char *argv[]) {
    bool answer = false;
    bool redTurn = false;

    if (argc <= 1) //no interesting information
    {
        std::cout << ("Didn't find any arguments.") << std::endl;
        fflush(stdout);
        answer = false;
    } else //there is interesting information
    {
        printf("Found %d interesting arguments.\n", argc - 1);
        fflush(stdout);
        char filename[51];
        char *eptr = (char *) malloc(sizeof(char *));
        long aL = -1L;
        int boardSize = INT8_MAX;
        for (int i = 1; i < argc; i++) //don't want to read argv[0]
        {//argv[i] is a string
            //in this program our arguments are NR, NC, gens, filename, print and pause
            //because pause is optional, argc could be 6 or 7
            //because print is optional (if print is not present, neither is pause) argc could be 5
            switch (i) {
                case 1:
                    //this is filename
                    printf("The length of the filename is %lu.\n", strlen(argv[i]));
                    printf("The proposed filename is %s.\n", argv[i]);
                    if (strlen(argv[i]) >= 51) {
                        cout << ("Filename is too long.") << endl;
                        fflush(stdout);
                        answer = false;
                    } else {
                        strcpy(filename, argv[i]);
                        printf("Filename was %s.\n", filename);
                        fflush(stdout);
                    }
                    break;
                case 2:
                    //this is the size of the board
                    aL = strtol(argv[i], &eptr, 10);
                    boardSize = (int) aL;
                    printf("Size of board is %d\n", boardSize);
                    fflush(stdout);
                    break;

                default:
                    cout << ("Unexpected argument count.") << endl;
                    fflush(stdout);
                    answer = false;
                    break;
            }//end of switch
        }//end of for loop on argument count
        cout << ("after reading arguments") << endl;
        fflush(stdout);

        if (boardSize == INT8_MAX)
            boardSize = promptForBoardSize();

        Board* userBoard = new Board(boardSize, "Your");
        Board* cpuBoard = new Board(boardSize, "The CPUs");

        userBoard->placeShipsRandom();
        cpuBoard->placeShipsRandom();

        bool playing = true;
        bool userTurn = true;
        while (playing){
            if (userTurn){
                cout << "Your board:" << endl;
                userBoard->printBoard(true);
                cout << endl;

                cout << "The CPU's Board:" << endl;
                cpuBoard->printBoard(false);
                cout << endl;

                // Make user move
                int* target = promptForMove();
                int row = target[0];
                int col = target[1];
                cpuBoard->updateBoard(row, col);
                cpuBoard->didSink();
            }else{
                srand(time(NULL));
                int cpuRow = rand() % (boardSize-1);
                int cpuCol = rand() % (boardSize-1);
                userBoard->updateBoard(cpuRow, cpuCol);
                userBoard->didSink();
            }

            userTurn = !userTurn;
            int result = checkForWinner(userBoard, cpuBoard);
            if (result > 0){
                playing = false;
            }
        }
    }
    return answer;
}

int Production::promptForBoardSize(){
    int size = 0;
    printf("Enter a board size (no larger than 10): ");
    scanf("%d", &size);
    return size;
}

int* Production::promptForMove() {
    int coordinates[2];
    printf("Enter target (Ex: 3 4): ");
    scanf("%d %d", &coordinates[0], &coordinates[1]);
    return coordinates;
}

int Production::checkForWinner(Board* user, Board* cpu) {
    if (user->qtyShipsLeft() == 0) {
        puts("You lost :(");
        return 2;
    }else if (cpu->qtyShipsLeft() == 0){
        puts("You won!!");
        return 1;
    }else{
        return 0;
    }
}