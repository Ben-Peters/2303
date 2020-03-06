/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include <stdbool.h>
#include<iostream>
#include<cstring>
#include <time.h>

using namespace std;

Production::Production() {
    // TODO Auto-generated constructor stub

}

Production::~Production() {
    // TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char *argv[]) {
    bool answer = false;
    bool redTurn = false;

    if (argc <= 1) //no interesting information
    {
        cout << ("Didn't find any arguments.") << endl;
        fflush(stdout);
        answer = false;
    } else //there is interesting information
    {
        printf("Found %d interesting arguments.\n", argc - 1);
        fflush(stdout);
        char filename[50];
        char *eptr = (char *) malloc(sizeof(char *));
        long aL = -1L;
        int numMoves = INT8_MAX;
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
                    if (strlen(argv[i]) >= 50) {
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
                    //this is maximum number of moves
                    aL = strtol(argv[i], &eptr, 10);
                    numMoves = (int) aL;
                    printf("Number of moves is %d\n", numMoves);
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

        if (numMoves == INT8_MAX)
            numMoves = promptNumOfMoves();

        CheckerPiece *allPieces = (CheckerPiece *) malloc(sizeof(CheckerPiece) * 24);
        //initBoard(allPieces);
        cout << ("Before read file") << endl;
        answer = readFile(filename, allPieces, redTurn); //read the file
        cout << ("Back from read file") << endl;
        cout << "The board:"<< endl;
	free(boardPrint(allPieces));

        srand(time(0));
        for (int i = 0; i < numMoves; i++) {
            cout<< "Current Board:" << endl;
            free(boardPrint(allPieces));
            int maxPiece = 12;
            int minPiece = 0;
            if (redTurn) {
                maxPiece = 24;
                minPiece = 12;
            }
            CheckerPiece::PossibleMove **possibleMoves;
            possibleMoves = (CheckerPiece::PossibleMove **) malloc(12 * sizeof(malloc(4 * sizeof(possibleMoves))));
            CheckerPiece::PossibleMove *tempPossibleMoves = (CheckerPiece::PossibleMove*) malloc(sizeof(possibleMoves)*4);
            for (int j = minPiece; j < maxPiece; j++) {
                if((allPieces+j)->getPawn()){
                    Pawn* pawn = (Pawn*) (allPieces+j);//seems to be dying here or on the next line for some reason...
                    tempPossibleMoves = pawn->getAllPossibleMoves(allPieces);
                }else{
                    King* king = (King*) (allPieces+j);
                    tempPossibleMoves = king->getAllPossibleMoves(allPieces);
                }
                *(possibleMoves + j) = tempPossibleMoves;
            }
            bool madeMove = false;
            while (!madeMove) {
                int pieceMoved = (rand() % 12) + minPiece;
                int moveMade = (rand() % 4);
                if ((*((*(possibleMoves + (pieceMoved))) + moveMade)).newPiece->getRow() != -1) {
                    makeMove(*(possibleMoves + (pieceMoved)),pieceMoved, allPieces);
                    madeMove = true;
                }
            }
            redTurn = !redTurn;
        }
    }
    return answer;
}

bool Production::readFile(char* filename, CheckerPiece *&pieces, bool &redTurn){
        bool ok = false;
        //the file tells how many rooms there are
        FILE* fp = fopen(filename, "r"); //read the file

        if (fp == NULL)
        {
	    cout << filename << endl;
            cout <<("Error! opening file")<<endl;

        }
        else
        {
            int *row = (int*) malloc(sizeof(int));
            int *col = (int*) malloc(sizeof(int));
            char *team = (char*) malloc(sizeof(char));
            for(int i = 0; i < 24; i++) {
                fscanf(fp, "%d", row);
                fscanf(fp, "%d", col);
                fscanf(fp, "%d", row);
                fscanf(fp, "%d", col);
                fscanf(fp, "%c", team);
                bool red = *team == 'r';
                //cout<< *row << ", " << *col <<", "<< *team<< endl;
                *(pieces+i) = new Pawn(*row,*col,red);
            }
            char *turn = (char*) malloc(sizeof(char));
            fscanf(fp, "%s", turn);
            redTurn = strncmp(turn, "red",3) == 0;
            bool valid= true;
            for(int i = 0; i < 24; i++){
                for(int j = 0; j < 24; j++){
                    if((((pieces+i)->getRow() == (pieces+j)->getRow() && (pieces+i)->getCol() == (pieces+j)->getCol()) || (pieces+i)->getRow()%2 == (pieces+i)->getCol()%2) && i != j)
                    {
                        cout <<((pieces+i)->getRow() == (pieces+j)->getRow() && (pieces+i)->getCol() == (pieces+j)->getCol())<< " " <<i <<" " << j <<endl;
                        valid = false;
                        cout<<"Oops! It looks like you gave an invalid configuration in your starter file."<<endl;
                    }
                }
            }
            ok = valid;
        }
        fclose(fp);

        return ok;

}

void Production::initBoard(CheckerPiece *&pieces) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            *(pieces + (i * 4) + j) = new Pawn(i, (2 * j) + ((i + 1) % 2), false);
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            *(pieces +12+ (i * 4) + j) = new Pawn(i + 5, (2 * j) + (i % 2), true);
        }
    }
}

int Production::promptNumOfMoves() {
    int moves = 0;
    printf("Enter the number of moves to make: ");
    scanf("%d", &moves);
    return moves;
}

void Production::makeMove(CheckerPiece::PossibleMove *move, int pieceToMove, CheckerPiece *&pieces) {
    if(move->king){
        Pawn *temp = (Pawn*) (pieces+pieceToMove);
        *(pieces+pieceToMove) = new King(temp->getRow(),temp->getCol(), temp->getCol());
        delete temp;
    }
    if(move->jump){
        delete (pieces+move->numJumped);
    }
    (pieces+pieceToMove)->setRow(move->newPiece->getRow());
    (pieces+pieceToMove)->setCol(move->newPiece->getCol());
}

void Production::simplePrint(CheckerPiece* pieces) {
    for (int i = 0; i < 24; i++) {
        cout << (pieces + i)->getRow() << " " << (pieces + i)->getCol() << " " << (pieces + i)->getRed() << endl;
    }
}

char* Production::boardPrint(CheckerPiece* pieces) {
	char* board = (char*) malloc(sizeof(char) * 72);
	for(int i = 0; i < 72; i++){
		board[i] = ' ';
		if ((i % 2 == 0 && (i / 9) % 2 == 0) || (i % 2 == 0 && (i / 9) % 2 == 1)){
			board[i] = '.';
		}
		if (i % 9 == 8 && i > 0){
			board[i] = '\n';
		}
		for(int p = 0; p < 24; p++){
			if ((pieces + p)->getRow() == i / 9 && (pieces + p)->getCol() == i % 9 ) {
				board[i] = (pieces + p)->getRed()? 'R':'B';
				//cout << "did a thing" << endl;
			}
		}
	}
	cout << board << endl;
	return board;
//	FILE* fp = fopen(filename, "w");


}
