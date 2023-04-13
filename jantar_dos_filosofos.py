


table = [1,1,1,1,1] # Hashis na mesa


def think(name):
    print(str(name)+ ": O que é a vida?") # Diálogo de pensamento


def eat(filo):

    print(str(filo["name"])+ ": Macarrão d'cria ein slk") # Diálogo de alimentar-se

    # Devolve os hashis
    table[filo["place"]] = 1
    table[filo["place"] - 1] = 1
    filo["left_h"] = 0
    filo["right_h"] = 0


def starving(name):
    print(str(name)+ ": Estou com fome") # Diálogo de espera


def get_hashi(hashi_place): # Ação de tentar pegar o hashi
    if(table[hashi_place] == 1): 
        table[hashi_place] = 0
        return 1
    return 0

def hungry_philosopher_loop(filo, filos): # (filósofo, array de filósofos)
    
    think(filo["name"])

    while(filo["left_h"] == 0 or filo["right_h"] == 0): # Enquanto as duas mãos estivrerem vazias

        if(filos[filo["place"] - 1]["priority"] > filo["priority"]): # Caso onde outro filósofo possui maior prioridade
            
            if(table[filo["place"]] == 0 and filo["left_h"] == 1):
                table[filo["place"]] = 1

            if(table[filo["place"] - 1] == 0 and filo["right_h"] == 1):
                table[filo["place"] - 1] = 1

            filo["left_h"] = 0
            filo["right_h"] = 0

        else: # Caso padrão

            if(filo["left_h"] == 0): filo["left_h"] = get_hashi(filo["place"])
            if(filo["right_h"] == 0): filo["right_h"] = get_hashi(filo["place"] - 1)
        
        filo["priority"] += 1  # Aumento da prioridade pelo tempo

        if(filo["priority"] % 5 == 0): starving(filo["name"]) # Diálogo de fome que só é executado a cada 5 ciclos para evitar spam 

    eat(filo) 


