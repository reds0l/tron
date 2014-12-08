CMP = gcc
MAIN = main
FUNC = func
INC = gfx3
EXEC = tronGame
FLAGS = -lm -lX11

$(EXEC): $(MAIN).o $(FUNC).o $(INC).o
		$(CMP) $(MAIN).o $(FUNC).o $(INC).o $(FLAGS) -o $(EXEC) 

$(MAIN).o: $(MAIN).c $(FUNC).h $(INC).h
		$(CMP) -c $(MAIN).c 

$(FUNC).o: $(FUNC).c
		$(CMP) -c $(FUNC).c 

$(INC).o: $(INC).c
		$(CMP) -c $(INC).c 

clean:
		rm *.o $(EXEC)


