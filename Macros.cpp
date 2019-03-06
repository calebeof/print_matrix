/*
ENTRADA:
VERTICES ARESTAS
CORES
V1 V2 COR
EXEMPLO:
6 8 
5
1 2 1
2 3 2
3 4 3
4 5 1
5 3 5
5 6 3
6 2 4
6 1 2
SAÍDA:
COR i:
v1 - v2
VETOR DE BOOLEANO DAS CORES UTILIZADAS
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD (1000000007LL)
#define INF (INT_MAX)
#define LINF (LL_MAX)
#define TAM (10000)
#define LL long long int 
#define ULL unsigned long long int
#define LD long double
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define si set<int>
#define qi queue<int>
#define sti stack<int>
#define vLL vector<LL>
#define pqi priority_queue<int>
#define pii pair<int, int> 
#define vii vector<pii>
#define vvii vector<vii>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define EPS 1e-9
#define loop( n ) for(int i=0; i<n; i++)
#define LOOP(k,n) for(int i=k; i<n; i++)
#define POOL(k,n) for(int i=k; i>=n; i--)
#define FIND(v, value) find(v.begin(), v.end(), value)
#define SORT( v ) sort(v.begin(), v.end())
#define SORTC(v, comp) sort(v.begin(), v.end(), comp)
#define WW( x ) cout<<#x<<" = "<<(x)<<"\n";
#define endl '\n'

//INICIO UNION FIND (SEM RANK)

int find(int v, vi &pais){
  if(pais[v]!=v)
    pais[v]=find(pais[v], pais);
  return pais[v];
}

void uniao(int v1,int v2, vi &pais, vi &niveis){
  int paiv1 = find(v1, pais);
  int paiv2 = find(v2, pais);
  if(paiv1!=paiv2){
    if(niveis[paiv1]>niveis[paiv2])
      pais[paiv2]=paiv1;
    else{
      pais[paiv1]=paiv2;
      if(niveis[paiv2]==niveis[paiv1])
      niveis[paiv2]++;
    }
  }
}

bool union_find(int v1,int v2, vi &pais){
  int pai1=find(v1, pais);
  int pai2=find(v2, pais);
  if(pai1==pai2)
    return true;
  return false;
}

// FIM UNION_FIND (SEM RANK)

struct Edge{
  int f, s;
  Edge(int a, int b){
    f = a;
    s = b;
  }
};

// UNIÃO DE VÉRTICES EM CADA ARESTA DA COR QUE EU QUERO
void union_color(int cor, vector<vector<Edge> > &ELL, vi &pais, vi &niveis){
  for(int i=0; i<ELL[cor].size(); i++)
    uniao(ELL[cor][i].f, ELL[cor][i].s, pais, niveis);
}

//FUNÇÃO OBJETIVO COM O VETOR BOOLEANO DAS CORES VISITADAS 
void printMark(vb &mark, int cores){
  for(int i=1; i<=cores;i++)
    cout << mark[i];
  cout << endl;
}

void printCores(vector<vector<Edge> > &ELL, int cores){
  for(int i=1; i<=cores; i++){
    cout << "Cor: " << (char)('A'+(i-1)) << endl;
    for(int j=0; j<ELL[i].size(); j++)
      cout << ELL[i][j].f << " - " << ELL[i][j].s << endl;
    cout << endl;
  }
}

int diametroColorido(int origem, int destino, vi &pais, vi &niveis, vector<vector<Edge> > &ELL, vector<vector<pair<int, int> > > &lista, int cores){
  sti atual_origem, atual_destino; //STACKS PARA A VERIFICAÇÃO DAS ADJACÊNCIAS DOS VÉRTICES A POSTERIORI
  vb mark(TAM, false); //MARCAÇÃO DAS CORES
  //ATUAL_ORIGEM E ATUAL_DESTINO SÃO STACKS PARA PEGAR AS ADJACÊNCIAS E PODER VERIFICAR AS CORES DAS ARESTAS ASSOCIADAS À ESSAS ADJACÊNCIAS
  atual_origem.push(origem);
  atual_destino.push(destino);
  //ENQUANTO ORIGEM E O DESTINO AINDA NÃO ESTIVEREM NA MESMA COMPONENTE  
  while(!union_find(origem, destino, pais)){
    int origem_top = atual_origem.top();
    int destino_top = atual_destino.top();
    atual_origem.pop();
    atual_destino.pop();
    for(int i=0; i<lista[origem_top].size() && !union_find(origem, destino, pais);i++){
      //GUARDO A COR ATUAL
      int cor = lista[origem_top][i].second;
      //COLOCO NA PILHA O VÉRTICE ATUAL, PARA VERIFICAR SUAS ADJACÊNCIAS A POSTERIORI
      atual_origem.push(lista[origem_top][i].first);
      if(!mark[cor]){
		//SE A COR ATUAL NÃO FOI MARCADA, ELA É MARCADA E TODAS AS ARESTAS E SEUS VÉRTICES ASSOCIADAS À ELA SÃO UNIDOS
      	mark[cor] = true;
      	union_color(cor, ELL, pais, niveis);
      }
    }
    //PRECISO FAZER O MESMO PASSO MAIS UMA VEZ, JÁ QUE VENHO DO LADO ESQUERDO (ORIGEM) E DO LADO DIREITO (DESTINO)
    for(int i=0; i<lista[destino_top].size() && !union_find(origem, destino, pais); i++){
      int cor = lista[destino_top][i].second;
      atual_destino.push(lista[destino_top][i].first);
      if(!mark[cor]){
      	mark[cor] = true;
      	union_color(cor, ELL, pais, niveis);
      }
    }
  }
  printMark(mark, cores);
  int cont = 0;
  for(int i=0; i<=cores; i++)
    cont+=mark[i];
  return cont;
}

void init(vi &pais, vi &niveis){
  for(int i=0; i<pais.size(); i++){
    pais[i] = i;
    niveis[i] = 0;
  }
}
int main () {
  ios_base::sync_with_stdio(false);
  freopen("input.txt", "r+", stdin);
  freopen("output.txt", "w+", stdout);
  int vertices, arestas;
  int cores;
  vi pais(TAM), niveis(TAM); //VETOR DE PAIS 
  vector<vector<pair<int, int> > > lista(TAM);  //LISTA DE ADJACÊNCIAS COM V1, V2 E COR, RESPECTIVAMENTE
  vector<vector<Edge> >  ELL(TAM); //EDGE-LABELED LIST
  cin >> vertices >> arestas >> cores;
  
  for(int i=0; i<arestas; i++){
    int f, s, cor;
    cin >> f >> s >> cor;
    //LEITURA DAS ARESTAS
    ELL[cor].pb(Edge(f, s));
    lista[f].pb(mp(s, cor));
    lista[s].pb(mp(f, cor));
  }
  for(int i=1; i<=vertices; i++){
    for(int j=i+1; j<=vertices; j++){
      init(pais, niveis);
      cout << i << "->" << j << " ";
      cout << diametroColorido(i, j, pais, niveis, ELL, lista, cores) << endl;
    }
  }
  printCores(ELL, cores);
  return 0;
}
