<h1>Problema do Jantar dos Filósofos</h1>
<h3>Threads: Deadlock, starvation e semaphores</h3>
<br>
O <b>Problema do Jantar dos Filósofos</b>, proposto por Dijkstra em 1965, é uma abstração de um problema de sincronização onde há uma disputa de recursos por diversos processos, neste caso cinco filósofos sentam numa mesa circular com cinco lamens e cinco hashis, de forma que apenas um filósofo com dois hashis pode comer. 
<br><br>
Este cenário gera <b>Deadlock</b> no momento de inicialização, pois todos os filósofos pegam apenas um hashi e não podem pegar outro para começarem a comer, além disto, este cenário também pode gerar <b>Starvation</b>, onde um dos filósofos nunca chega a comer o seu lamen por nunca conseguir ter o recurso necessário (dois hashis).
<br><br>
A solução deste problema está na construção de <b>Semaphores</b> que regulam a ordem de acesso dos filósofos aos hahsi de forma que todos consigam comer.
