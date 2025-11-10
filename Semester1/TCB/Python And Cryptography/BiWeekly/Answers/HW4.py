from random import randrange
from time import sleep
SLEEP_TIME=0.1
SETS=3

players=[['Novak Djokovic','22/05/1987',30,1150],
        ['Daniil Medvedev','11/02/1996',16,870],
        ['Alexander Zverev','20/04/1997',18,780],
        ['Stefanos Tsitsipas','12/08/1998',17,650],
        ['Andrey Rublev','20/10/1997',20,520],
        ['Rafael Nadal','03/06/1986',17,490],
        ['Matteo Berrettini','12/03/1996',12,460],
        ['Casper Ruud','22/12/1998',10,420],
        ['Hubert Hurkacz','11/02/1997',10,370],
        ['Jannik Sinner','16/08/2001',14,340],
        ['Félix Auger-Aliassime','08/08/2000',11,330],
        ['Cameron Norrie','23/08/1995',10,300],
        ['Diego Schwartzman','16/08/1992',20,260],
        ['Denis Shapovalov','15/03/1999',15,250],
        ['Dominic Thiem','03/09/1996',14,240],
        ['Roger Federer','08/08/1981',27,230]]

# Function to simulate a match between two players
def doMatch(player1:list, player2:list):
    # Function to simulate a game
    def playGame():
        points = [0, 0]
        while True:
            winner = randrange(0, 2)
            sleep(SLEEP_TIME)
            if points[winner] < 30:
                points[winner] += 15
            else:
                points[winner] += 10
            print(f"{points[0]}-{points[1]}", end=', ')
            if points[winner] >= 40 and points[winner] - points[1 - winner] >= 2:
                return winner

    # Function to simulate a set    
    def playSet():
        games = [0, 0]
        while True:
            print(f"game {' ' if games[0]+games[1]+1 < 10 else ''}{games[0] + games[1] + 1}: ", end='')
            winner = playGame()
            games[winner] += 1
            print(f"game winner {player1[0] if winner == 0 else player2[0]} {games[winner]}-{games[1-winner]}")
            if games[winner] >= 6 and games[winner] - games[1 - winner] >= 2:
                return winner

    sets = [0, 0]
    print(f"<Match {player1[0]} - {player2[0]}>")
    while True:
        print(f"<Set {sets[0] + sets[1] + 1}>")
        winner = playSet()
        sets[winner] += 1
        print(f"set winner {player1[0] if winner == 0 else player2[0]} {sets[winner]}-{sets[1-winner]}")
        if sets[winner] == SETS - 1:  
            if winner == 0:
                print(f"Match winner {player1[0]}")
                player1[2] += 1  
                player2[3] += 10  
                return player1
            else:
                print(f"Match winner {player2[0]}")
                player2[2] += 1  
                player2[3] += 10  
                return player2

# Function to simulate a tournament
def doTournament(tname:str, plist:list, pamount:int):
    # Function to choose players for the tournament
    def choicePlayers():
        prtcptrs = []
        while len(prtcptrs) < pamount:
            player = randrange(0, len(plist))
            if plist[player] not in prtcptrs:
                prtcptrs.append(plist[player])
        return prtcptrs

    print(f"Welcome to the {tname} tournament!")
    prtcptrs = choicePlayers()
    round_number = 1

    while len(prtcptrs) > 1:
        print(f"\n--- Round {round_number} ---")
        print("Participants: ", end='')
        for i in range(len(prtcptrs)):
            print(prtcptrs[i][0], end=', ')
        print("\n----------------------------")

        next_round = []
        for i in range(1, len(prtcptrs), 2):
            winner = doMatch(prtcptrs[i - 1], prtcptrs[i])
            for j in range(len(plist)):
                if plist[j][0] == winner[0]:
                    plist[j] = winner
                    break
            next_round.append(winner)

        prtcptrs = next_round
        round_number += 1
        
    print(f"\n{prtcptrs[0][0]} wins the {tname} tournament!")
    prtcptrs[0][3] += 10 
    for i in range(len(plist)):
        if plist[i][0] == prtcptrs[0][0]:
            plist[i] = prtcptrs[0]
            break

# Function to print a single player
def printPlayer(player: list):
    def spaceMaker(player_name):
        space = 27 - len(player_name)   
        return ' ' * space
    print(f"{player[0]}{spaceMaker(player[0])}{player[1]}  {player[2]}  {player[3]}")

# Function to print a list of players based on a specified number
def printPlayers(plist:list, num:int=0):
    for i in range(len(plist)):
        if num == 0:
            printPlayer(plist[i])
        elif i < num:
            printPlayer(plist[i])
        elif num < 0 and i >= len(plist) + num:
            printPlayer(plist[i])

# Function to sort players based on a specified field
def sortPlayers(plist:list, field:str='point', flag:bool=True):
    newlist = plist.copy()
    if field == 'name':
        newlist.sort(key=lambda x: x[0], reverse=flag)
    elif field == 'born':
        newlist.sort(key=lambda x: x[1][6:len(x[1])], reverse=flag)
    elif field == 'match':
        newlist.sort(key=lambda x: x[2], reverse=flag)
    else:
        newlist.sort(key=lambda x: x[3], reverse=flag)
    return newlist
              
# Function to add a player to the list  
def addPlayer(plist:list):
    name = input('Enter name: ')
    born = input('Enter birthday [dd/mm/yyyy]: ')
    matches = int(input('Enter number of matches won: '))
    points = int(input('Enter number of points: '))
    plist.append([name,born,matches,points])
    return plist

# Function to remove the player with the lowest points from the list
def removePlayer(plist:list):
    plist = sortPlayers(plist, field='point', flag=False)
    player = plist[0]
    print(f"player {player[0]} remove from player list")
    plist.pop(0)
    return plist

# Function to display the menu and summon the other functions
def menu(plist:list):
    while True:
        print('1. Print players')
        print('2. Sort players')
        print('3. Add player')
        print('4. Remove player')
        print('5. Do tournament')
        print('6. Exit')
        print('--------------------------------------------\n')
        choice = input('Enter choice: ')
        if choice == '1':
            print('<Print list players>')
            printPlayers(plist, 0)
            print('--------------------------------------------\n')
        elif choice == '2':
            print('1. Sort by points')
            print('2. Sort by name')
            print('3. Sort by matches')
            print('4. Sort by birthday')
            choice = input('Enter choice: ')
            flag_choice = input('Ascending order? (y/n): ')
            if flag_choice == 'y':
                flag = False
            else:
                flag = True
            print('\n<Print Sort list players>')
            if choice == '1':
                printPlayers(sortPlayers(plist,'point',flag))
            elif choice == '2':
                printPlayers(sortPlayers(plist,'name',flag))
            elif choice == '3':
                printPlayers(sortPlayers(plist,'match',flag))
            else:
                printPlayers(sortPlayers(plist,'born',flag))
            print('--------------------------------------------\n')
        elif choice == '3':
            print('<Add player>')
            printPlayers(addPlayer(plist), 0)
            print('--------------------------------------------\n')
        elif choice == '4':
            print('<Remove player>')
            printPlayers(removePlayer(plist), 0)
            print('--------------------------------------------\n')
        elif choice == '5':
            pamount = int(input('Enter number of participants (need to be 2^n): '))
            doTournament('Wimbledon',plist,pamount)
            print('--------------------------------------------\n')
        elif choice == '6':
            break
        sleep(2)
        
def main():
    # print('<Print list players>')
    # printPlayers(players)
    # print('\n<Print list players>')
    # printPlayers(players,4)
    # print('\n<Print list players>')
    # printPlayers(players,-3)
    
    # print('--------------------------------------------')
    # print('\n<Print Sort list players>')
    # printPlayers(sortPlayers(players,flag=False),6)
    # print('\n<Print Sort list players>')
    # printPlayers(sortPlayers(players,field='point',flag=False),-5)
    # print('\n<Print Sort list players>')
    # printPlayers(sortPlayers(players,field='name',flag=False),10)
    # print('\n<Print Sort list players>')
    # printPlayers(sortPlayers(players,field='match',flag=True),10)
    # print('\n<Print Sort list players>')
    # printPlayers(sortPlayers(players,field='born',flag=False),6)
    
    # print('--------------------------------------------')
    # print('<Add player>')
    # addPlayer(players)
    # print('\n<Print list players>')
    # printPlayers(players)

    # print('--------------------------------------------')
    # print('<Remove player>')
    # removePlayer(players)
    # print('\n<Print list players>')
    # printPlayers(players)
    
    # print('--------------------------------------------')
    # print('<Tournament>')
    # doTournament('Wimbledon',players,8)
    # print('\n<Print list players>')
    # printPlayers(sortPlayers(players,field='point',flag=True))
    menu(players)
main()
