# -*- coding: utf-8 -*-
"""
Created on Thu Jul 21 10:20:01 2022

@author: Sudatra
"""

import random

class gameBoard:
    
    def __init__(self, board):
        self.board = board
        
    def get_letter_to_numbers():
        letter_to_nos = {'A': 0, 'B': 1, 'C': 2, 'D': 3, 'E': 4, 'F': 5, 'G': 6,
                          'H': 7}
        return letter_to_nos
    
    def printBoard(self):
        print(' A B C D E F G H')
        print(' +-+-+-+-+-+-+-+')
        
        rowNo = 1
        for row in self.board:
            print('%d|%s|' % (rowNo, '|'.join(row)))
            rowNo += 1
    
class battleship:
    
    def __init__(self, board):
        self.board = board
    
    def createShips(self):
        for i in range(5):
            self.xRow, self.yCol = random.randint(0, 7), random.randint(0, 7)
            while self.board[self.xRow][self.yCol] == 'X':
                self.xRow, self.yCol = random.randint(0, 7), random.randint(0, 7)
            self.board[self.xRow][self.yCol] = 'X'
            
        return self.board
    
    def get_user_input(self):
        try:
            xRow = input('Enter row of the ship: ')
            while xRow not in '12345678':
                print('Enter valid choice')
                xRow = input('Enter row of the ship: ')
            
            yCol = input('Enter column letter of ship').upper()
            while yCol not in 'ABCDEFGH':
                print('Enter valid choice')
                yCol = input('Enter column letter of ship').upper()
            return int(xRow) - 1, gameBoard.get_letter_to_numbers()[yCol]
                
        except ValueError and KeyError:
            print('Not valid choice')
            return self.get_user_input()
    
    def count_hit_ships(self):
        hits = 0
        
        for row in self.board:
            for col in row:
                if col == 'X':
                    hits += 1
        return hits
    
def runGame():
    computerBoard = gameBoard([[' '] * 8 for i in range(8)])
    userBoard = gameBoard([[' '] * 8 for i in range(8)])
    battleship.createShips(computerBoard)
    turns = 10
    while turns > 0:
        gameBoard.printBoard(userBoard)
        
        user_xRow, user_yCol = battleship.get_user_input(object)
        while userBoard.board[user_xRow][user_yCol] == '-' or userBoard.board[user_xRow][user_yCol] == 'X':
            print('Duplicate Guess')
            user_xRow, user_yCol = battleship.get_user_input(object)
        
        if userBoard.board[user_xRow][user_yCol] == 'X':
            print('Battleship sunk')
            userBoard.board[user_xRow][user_yCol] = 'X'
        else:
            print('Missed!!')
            userBoard.board[user_xRow][user_yCol] = '-'
        
        if battleship.count_hit_ships(userBoard) == 5:
            print('All 5 battleships sunk!')
            break
        else:
            turns -= 1
            print(f'You have {turns} remaining')
            
            if turns == 0:
                print('Sorry! You are out of turns')
                gameBoard.printBoard(userBoard)
                break

if __name__ == '__main__':
    runGame()