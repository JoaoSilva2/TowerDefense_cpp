CC = g++
SFML = -lsfml-graphics -lsfml-window -lsfml-system

game: wave.o ballon.o Canon.o Game.o Bullet.o test.o
	  $(CC) -o game wave.o ballon.o Canon.o Game.o Bullet.o test.o $(SFML)

Game.o: Game.cpp
		  $(CC) -c Game.cpp $(SFML)

wave.o: wave.cpp
		  $(CC) -c wave.cpp $(SFML)

ballon.o: Entities/ballon.cpp
		  $(CC) -c Entities/ballon.cpp $(SFML)

Canon.o: Entities/Canon.cpp
		  $(CC) -c Entities/Canon.cpp $(SFML)

Bullet.o: Entities/Bullet.cpp
		  $(CC) -c Entities/Bullet.cpp $(SFML)

test.o: test.cpp
		  $(CC) -c test.cpp $(SFML)

clean: 
	$(RM) game *.o
